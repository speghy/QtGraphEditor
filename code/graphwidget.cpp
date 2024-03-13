    #include "graphwidget.h"
#include "iostream"
#include <QKeyEvent>
#include <QDebug>

GraphWidget::GraphWidget(QWidget *parent): QGraphicsView(parent)//Конструктор
{
    scene = new QGraphicsScene(this);
    setScene(scene);
}

void GraphWidget::resizeEvent(QResizeEvent *event)
//Вызывается при изменении размера окна
{
    scene->setSceneRect(0, 0, width()-2, height()-2);
    QGraphicsView::resizeEvent(event);
}

void GraphWidget::drawBackground(QPainter *painter, const QRectF &)
// Отрисовка фона
{
    QRectF sceneRect = this->sceneRect();
    painter->fillRect(sceneRect, QColor(255, 255, 255, 255));//Окрашиваем область в цвет градиента
}

void GraphWidget::addNode()//Добавляем вершину
{
    Node *node = new Node(this); // Создаём новую вершину
    scene->addItem(node); // Добавляем её на экран

////    Node->setPos(QPointF(event->pos().x(), event->pos().y())); // Перемещаем к курсору
//?    Node->setPos(QPointF(50, 50));
    listOfNode << node; // Добавить эту вершину в список вершин
    changeIndecesOfAllVerteces(); // Поставить новый индекс вершине
//  Обеспечим сдвиг порождаемых вершин относительно предыдущей
    int ii = node->getIndex();
    node->setPos(QPointF(50+ii*10, 50+ii*10));
    update(); // Обновяем экран
}

void GraphWidget::deleteEdge(Edge *edge)
{
    scene->removeItem(edge);
    edge->destNode()->removeEdge(edge);
    edge->sourceNode()->removeEdge(edge);
    delete edge;
};

Node* GraphWidget::addNode1(QPointF position,int t)
//Добавляем вершину с заданной позицией и номером
{
    Node *node = new Node(this); // Создаём новую вершину
    node->setIndex(t);
    scene->addItem(node); // Добавляем её на экран
    listOfNode << node; // Добавить эту вершину в список вершин
    node->setPos(position);
    update(); // Обновяем экран
    return node;
};

Edge * GraphWidget::addEdge(Node *source,Node *dest, unsigned length)
{
    edgeCheck();
    Edge *edge = new Edge(source, dest, length);
    scene->addItem(edge);
    return edge;
}

void GraphWidget::addEdge(Node *source, Node *dest)
{
    scene->addItem(new Edge(source, dest));
};

void GraphWidget::mouseDoubleClickEvent(QMouseEvent *event) // Отслеживание двойного клика мышкой
{
    //Если щёлкнули левой кнопкой мыши дважды - добавили вершину
    if (event->button() == Qt::LeftButton) // Если был произведён двойной клик левой кнопкой мыши
    {
        Node *node = new Node(this); // Создаём новую вершину
        scene->addItem(node); // Добавляем её на экран
        node->setPos(QPointF(event->pos().x(), event->pos().y())); // Перемещаем к курсору
        listOfNode << node; // Добавить эту вершину в список вершин
        changeIndecesOfAllVerteces(); // Поставить новый индекс вершине
        update(); // Обновяем экран
    }

    //Если щёлкнули правой кнопкой мыши дважды - провели рёбра
    //от всех выбранных вершин к той, на которую кликнули
    //и нажали клавишу Shift, чтобы запретить создание контекстного меню
    else if (event->button() == Qt::RightButton)
        // /*&&true/*(this->qq==false)/*&& QApplication::keyboardModifiers() == Qt::ShiftModifier */)
        // Если был произведён двойной клик правой кнопкой мыши
    {
        Node *dest = static_cast<Node*>(itemAt(event->pos()));
        //Вершина, в которую надо провести все рёбра от выбранных вершин
        int lasttypeset = 1;
        foreach (QGraphicsItem *item, scene->selectedItems())//Для всех выбранных вершин
        {
            int w11=0;
            int w22=0;
            int w33=0;
            bool isFindSameEdge = false;
            bool isFindReverse = false;
            Node *source = static_cast<Node*>(item);// Привести текушую вершину к типу Node
            if (source == dest) continue;
            int lengthNum = 0;
            foreach (Edge *compareEdge, source->edges())
            {
                if ((compareEdge->sourceNode() == dest &&
                    compareEdge->destNode() == source))
                {
                    isFindReverse = true;
                    QMessageBox msgBox;
                    QLabel *text = new QLabel();
                    QRadioButton *selectEdgeRadioButton1 = new QRadioButton();
                    selectEdgeRadioButton1->setText("удалить ребро");
                    msgBox.layout()->addWidget(selectEdgeRadioButton1);
                    msgBox.exec();
                    if(selectEdgeRadioButton1->isChecked()==1) deleteEdge(compareEdge);
                    if(compareEdge->getType()==1) lasttypeset=1;
                     if(compareEdge->getType()==2) lasttypeset=2;
                     if(compareEdge->getType()==3) lasttypeset=3;
                    lengthNum = static_cast<int>(compareEdge->getLength());
                    compareEdge->is_reverse = 1;
                    qDebug()<<"REWERTED!";
                }
            }
            if (!isFindReverse)
            {

                QMessageBox msgBox;
                QLabel *text = new QLabel();
                text->setText("Длина ребра:");
                QSpinBox *length = new QSpinBox();
                length->setRange(0, 100);
                QRadioButton *selectEdgeRadioButton1 = new QRadioButton();
                selectEdgeRadioButton1->setText("ребро обозначает удаленность объектов");
                QRadioButton *selectEdgeRadioButton2 = new QRadioButton();
                selectEdgeRadioButton2->setText("ребро обозначае возможеность наблюдать объект");
                QRadioButton *selectEdgeRadioButton3 = new QRadioButton();
                selectEdgeRadioButton3->setText("ребро обозначае возможность управлять движением квадрокоптера");
                QRadioButton *selectEdgeRadioButton4 = new QRadioButton();
                selectEdgeRadioButton4->setText("удалить ребро");
                msgBox.layout()->addWidget(selectEdgeRadioButton1);
                msgBox.layout()->addWidget(selectEdgeRadioButton2);
                msgBox.layout()->addWidget(selectEdgeRadioButton3);
                 msgBox.layout()->addWidget(selectEdgeRadioButton4);
                msgBox.layout()->addWidget(text);
                msgBox.layout()->addWidget(length);
                msgBox.exec();
                lengthNum = length->value();
                if(  selectEdgeRadioButton1->isChecked()==1)
                {
                    lasttypeset=1;
                }
                if(  selectEdgeRadioButton2->isChecked()==1)
                {
                     lasttypeset=2;
                }
                if(  selectEdgeRadioButton3->isChecked()==1)
                {
                     QMessageBox msgBox4;
                     lasttypeset=3;
                     QLabel *text566 = new QLabel();
                     QSpinBox *length566 = new QSpinBox();
                     length566->setRange(0, 100);
                     text566->setText("Степень достоверности использования канала передачи  Wi-Fi");
                     QLabel *text567 = new QLabel();
                     text567->setText("Степень достоверности использования канала передачи Bluetooth");
                     QSpinBox *length567 = new QSpinBox();
                     length567->setRange(0, 100);
                     QSpinBox *length569 = new QSpinBox();
                     QLabel *text569 = new QLabel();
                     text569->setText("Степень достоверности использования канала передачи УКВ");
                     length569->setRange(0, 100);
                     msgBox4.layout()->addWidget(text566);
                     msgBox4.layout()->addWidget(length566);
                      msgBox4.layout()->addWidget(text567);
                      msgBox4.layout()->addWidget(length567);
                      msgBox4.layout()->addWidget(text569);
                      msgBox4.layout()->addWidget(length569);



                      msgBox4.exec();
                      w11 = length566->value();
                      w22 = length567->value();
                      w33 = length569->value();
                      qDebug()<<"l="<<length566->value();
                      source->setw(w11,w22,w33);
                      qDebug()<<"a="<<source->geta();
                      qDebug()<<"b="<<source->getb();
                      qDebug()<<"c="<<source->getc();
                      qDebug()<<"w1="<<w11;
                      qDebug()<<"w2="<< w22;
                      qDebug()<<"w3="<< w33;
                }
                if(  selectEdgeRadioButton4->isChecked()==1)
                {
                     lasttypeset=4;

                     qDebug()<<lasttypeset;
                }
            }
          /*  foreach (Edge *compareEdge, source->edges())
            {
            if(  compareEdge->getType()==1)compareEdge->setColor(Qt::black);
            if(  compareEdge->getType()==2)compareEdge->setColor(Qt::red);
            if(  compareEdge->getType()==3)compareEdge->setColor(Qt::green);
            compareEdge->update();
            }*/

            foreach (Edge *compareEdge, source->edges())
            {
                if ((compareEdge->sourceNode() == source &&
                    compareEdge->destNode() == dest))
                {
                    for (auto i : source->edges())
                        if (i->destNode() == dest)
                        {
                            i->setLength(static_cast<unsigned>(lengthNum));
                            if(lasttypeset==4)
                            {
                                deleteEdge(compareEdge);
                            }
                            if(  compareEdge->getType()==1)
                            {
                                compareEdge->setType(1);
                                compareEdge->setColor(Qt::black);
                                lasttypeset = 1;
                            }
                            if(  compareEdge->getType()==2)
                            {
                                compareEdge->setType(2);
                                compareEdge->setColor(Qt::red);
                                lasttypeset = 2;
                            }
                            if(  compareEdge->getType()==3)
                            {
                                compareEdge->setType(3);
                                compareEdge->setColor(Qt::green);
                                lasttypeset = 3;
                            }

                            compareEdge->update();

                             qDebug()<<lasttypeset;
                        }
                    isFindSameEdge = true;
                    break;
                }
            }
            if (isFindSameEdge) continue;
            Edge* newedge = new Edge(source, dest, static_cast<unsigned>(lengthNum));
            newedge->setType(lasttypeset);

            newedge->setW(w11,w22,w33);
            newedge->update();
            if(  newedge->getType()==1)newedge->setColor(Qt::black);
            if(  newedge->getType()==2)newedge->setColor(Qt::red);
            if(  newedge->getType()==3)newedge->setColor(Qt::green);
            scene->addItem(newedge);
            if(lasttypeset==4)
            {
                deleteEdge(newedge);
            }

        }
    }
}

QPointF GraphWidget::getPosOfNode(int index)
// Возвращает местоположение вершины с номером index
{
    return listOfNode.at(index)->pos();
}

int GraphWidget::getListOfNodeSize()
//Возвращает количество вершин
{
    return listOfNode.size();
}

void GraphWidget::changeIndecesOfAllVerteces()
//Переименовывет вершины после удаления некоторых вершин
{
    foreach (Node *itemNode, listOfNode)
    {
        itemNode->setIndex(listOfNode.indexOf(itemNode));
        itemNode->update();
    }
}

QVector<Edges *> GraphWidget::getEdges()
// Возвращает список всех рёбер графа
{
    QVector<Edges *> EdgesList;
    foreach (Node *Node, listOfNode)
    {
        foreach (Edge *edge, Node->edges())
        {
            if (Node->getIndex() == edge->destNode()->getIndex()) continue;
            Edges *curr = new Edges;
            curr->source = Node->getIndex(); // В каждую запись включает первую вершину ребра
            curr->dest = edge->destNode()->getIndex(); // Вторую вершину ребра
            curr->length = (int)edge->getLength();     // Длину ребра
            curr->edge = edge; // Ссылку на само ребро
            EdgesList << curr;
        }
    }
    return EdgesList;
}
void GraphWidget::edgeCheck()
{
    foreach (Edges *compareEdge, getEdges())
    {
        foreach(Edges *edgeToCheck,getEdges())
        {
         if((compareEdge->edge!=NULL)&&(edgeToCheck->edge!=NULL))
          {
           if((compareEdge->edge->sourceNode()->getType()==2)&&(edgeToCheck->edge->sourceNode()->getType()==2))
           {

               if((compareEdge->dest)==(edgeToCheck->dest))
               {
                   if((compareEdge->source)!=(edgeToCheck->source))
                   {


                        if(compareEdge->edge->getLength()>edgeToCheck->edge->getLength())

                        {

                            scene->removeItem(edgeToCheck->edge);

                            edgeToCheck->edge->destNode()->removeEdge(edgeToCheck->edge);

                            edgeToCheck->edge->sourceNode()->removeEdge(edgeToCheck->edge);
                            edgeToCheck->edge=NULL;

                            continue;
                        }
                        if(compareEdge->edge->getLength()<= edgeToCheck->edge->getLength())

                        {

                            scene->removeItem(compareEdge->edge);

                            compareEdge->edge->destNode()->removeEdge(compareEdge->edge);

                            compareEdge->edge->sourceNode()->removeEdge(compareEdge->edge);
                            compareEdge->edge=NULL;

                       }

                   }
               }
           }

         }
        }
    }
    QMessageBox msgBox;
    QString text12 = "Оптимизация проведена успешно";
    QLabel *text1 = new QLabel(text12);
    msgBox.layout()->addWidget(text1);
    msgBox.exec();
}
int GraphWidget::getmaxl(Node *sourceNode, Node *destNode,int   )
{

}
void GraphWidget::getMaximumLength()
{
    int max = 0;
    int min=100;
    foreach (Node *itemNode, listOfNode)
     {
        if(itemNode->getType()==2)
        {
            max = 0;
            min = 100;
             if(!itemNode->edges().empty())
             {
             foreach(Edge* getOxrObj, itemNode->edges())
             {
                 //if((getOxrObj->destNode()->getType()==1)||(getOxrObj->destNode()->getType()==4)) проверка не нужна
                     qDebug()<<"yep2";
                getOxrObj->destNode()->checked=1;

             }


             foreach(Edge* getOxrObj, itemNode->edges())
             {
                 if(!getOxrObj->destNode()->edges().empty())
                 foreach (Edge* OxrObjSv, getOxrObj->destNode()->edges())
                 {
                  if ( OxrObjSv->getType()==1)
                  {
                      if((OxrObjSv->destNode()->checked==1)&&(OxrObjSv->sourceNode()->checked==1))
                      {
                          qDebug()<<"yep";
                          if(OxrObjSv->getLength()>max)
                              max=OxrObjSv->getLength();
                          if(OxrObjSv->getLength()<min)
                              min=OxrObjSv->getLength();
                      }
                  }
                 }


             }

             foreach(Edge* getOxrObj, itemNode->edges())
             {
                getOxrObj->destNode()->checked=0;
             }
              qDebug()<<min<<" "<<max;

              QMessageBox msgBox;
              QString text12 = "Подграф с центром в вершине: " + QString::number(itemNode->getIndex());
              QLabel *text1 = new QLabel(text12);
              msgBox.layout()->addWidget(text1);
              QString text13 = "включает вершины: ";
              foreach(Edge* getOxrObj, itemNode->edges())
              {
                  if(getOxrObj->getType()==2)
                  {
                      text13+=QString::number(getOxrObj->destNode()->getIndex())+" ";
                      getOxrObj->destNode()->setHeightColor(40,200,40,180);
                      getOxrObj->destNode()->update();
                  }
                  if(getOxrObj->destNode()->getType()==4)
                      if(getOxrObj->getLength()<=min)
                      {
                           QLabel *text1345 = new QLabel("Потенциальный нарушитель в области охраны!");
                           msgBox.layout()->addWidget(text1345);
                      }
              }
              QLabel *text134 = new QLabel(text13);
              msgBox.layout()->addWidget(text134);
              QString text15 = "диаметр:         ";
              text15+=QString::number(max);
              QLabel *text11 = new QLabel(text15);
              msgBox.layout()->addWidget(text11);
              QString text16 = "радиус:          ";
              text16+=QString::number(min);
              QLabel *text17 = new QLabel(text16);
              msgBox.layout()->addWidget(text17);
              msgBox.exec();
              min=0;
              max=0;
              foreach(Edge* getOxrObj, itemNode->edges())
              {
                  if(getOxrObj->getType()==2)
                  {
                      getOxrObj->destNode()->setHeightColor(254,254,30,30);
                      getOxrObj->destNode()->update();
                  }
              }

            }

        }

    }
}
//Удаляет выбранные вершины
void GraphWidget::deleteSelectedItems()
{
    foreach (QGraphicsItem *itemNode, scene->selectedItems())//Для каждой выбранной вершины
    {
        scene->removeItem(itemNode);//Убрать её из окна
        listOfNode.removeAt(listOfNode.indexOf((Node *)itemNode)); //Убрать из списка вершин

        foreach (Edge *itemEdge, ((Node *)itemNode)->edges()) //Для каждого ребра, связанного с данной вершиной
        {
            // ???? пытаюсь удалить автомобиль
            if(!itemEdge->it->pixmap().isNull()) // Удалить со сцены аним. объект
                scene->removeItem(itemEdge->it);
            scene->removeItem(itemEdge);//Убрать ребро из окна
            itemEdge->destNode()->removeEdge(itemEdge);//Убрать ребро из списка рёбер первой вершины
            itemEdge->sourceNode()->removeEdge(itemEdge);//Убрать ребро из списка рёбер второй вершины
            delete itemEdge;//Удалить само ребро
        }
        delete itemNode;//Удалить саму вершину
    }
}

void GraphWidget::deleteAllItems() //Удаляет все вершины
{
   foreach (Node *itemNode, listOfNode)
    {
        scene->removeItem(itemNode);//Убрать её из окна

        foreach (Edge *itemEdge, itemNode->edges())
            //Для каждого ребра, связанного с данной вершиной
        {
            scene->removeItem(itemEdge);//Убрать ребро из окна
            itemEdge->destNode()->removeEdge(itemEdge);
            //Убрать ребро из списка рёбер первой вершины
            itemEdge->sourceNode()->removeEdge(itemEdge);
            //Убрать ребро из списка рёбер второй вершины
            delete itemEdge;//Удалить само ребро
        }
        itemNode->edges().clear();
        delete itemNode;//Удалить саму вершину
    }
   listOfNode.clear();
   scene->clear();
}


#ifndef QT_NO_WHEELEVENT
//! [5]
void GraphWidget::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, -event->delta() / 240.0));
}
//! [5]
#endif
//! [7]
void GraphWidget::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}
//! [7]

bool GraphWidget::createGraphFromInc(QString temp)         // Создать граф из списка инц.
{
    QList<QString> nodes;
    QList<QStringList> child_of_nodes;
    temp  = temp.trimmed();
    QTextStream stream(&temp);
    while(!stream.atEnd())
    {
        QString line = add_spaces_and_simplifie(stream.readLine(220));
        if(line.isEmpty()) continue;
        QStringList list = line.split(":");
        if(list.first() == list.last()) return false;
        QString t = list.first().trimmed();
        if (nodes.count(t) == 0)
            nodes << t;
        QString t2 = list.last().trimmed();
        QStringList list_of_children = t2.split(" , ",QString::SkipEmptyParts);
        child_of_nodes << list_of_children;
    }
    QList<QString> all_n; // Все вершины
    for (int i = 0; i < nodes.size();i++)
        if(!all_n.contains(nodes[i]))
            all_n << nodes[i];
    for (int i = 0; i < nodes.size();i++)
        for(int k = 0; k < child_of_nodes[i].size();k++)
            if(!all_n.contains(child_of_nodes[i][k]))
                all_n << child_of_nodes[i][k];
    //проверка, что все вершины это числа
    bool ok = true;
    for (int i = 0; i < nodes.size();i++)
        for(int k = 0; k < child_of_nodes[i].size();k++)
        {
            child_of_nodes[i][k].toInt(&ok);
        }
    if (!ok)
    {
        return false;
    }
    int radius = 200;
    double segments = (/*TwoPi*/6.28)/all_n.size();
    if (all_n.size() >= 16)
        radius = all_n.size()*70/6;
    double current_angle = 0;

    foreach(QString str,all_n)
    {
        // Создание всех вершин и размещение их по кругу
        QPointF pos(radius*cos(current_angle)+250,radius*sin(current_angle)+250);
        int k = str.toInt();
        //чтобы получить целые координаты для сохранения в файл
        int a, b;
        a = static_cast<int>(pos.rx());
        b = static_cast<int>(pos.ry());
        pos.setX(a); pos.setY(b);
        addNode1(pos,k);
        update();
        current_angle += segments;
    }
    for (int i = 0; i < nodes.size(); i++)
    {
        Node * a = findNode(nodes[i].toInt());
        //по номеру надо найти вершину
        for(int k = 0; k < child_of_nodes[i].size(); k++)
        {
            //            // Ищем детей a
            Node* b = findNode(child_of_nodes[i][k].toInt());
            if (a && b) // Елси найдены
            {
                addEdge(a, b);
            }
            else
                continue;
        }
    }
    return true;
}

QString GraphWidget::add_spaces_and_simplifie(QString str_for_work)
{
    QChar symbs[2]{':',','};
    for(int i = 0; i < 2; i++)
    {
        int a = -2;
        while((a = str_for_work.indexOf(symbs[i],a+2))!=-1)
        {
            {
                str_for_work.insert(a, ' ');
                str_for_work.insert(a+2, ' ');
            }
        }
    }
    str_for_work = str_for_work.simplified();
    return str_for_work;
}


Node* GraphWidget::findNode(int val/*,QList<Node *> listOfNode*/)//по номеру надо найти вершину
{
    Node *a;
    //по номеру надо найти вершину
    foreach (Node *itemNode, listOfNode)
    {
        if (itemNode->getIndex() == val)
        {
            a = static_cast<Node*>(itemNode); // Привести текушую вершину к типу Node
            return a;
        }
    }
    return nullptr;
}
