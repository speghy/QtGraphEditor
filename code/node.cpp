#include "edge.h"
#include "node.h"
#include "graphwidget.h"

#include<QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>

int Node::getType()
{
    return type;
}

void Node::setw(int a, int b, int c)
{
    w1=a;
    w2=b;
    w3=c;
}
int Node::geta()
{
    return w1;
}
int Node::getb()
{
    return w2;
}
int Node::getc()
{
    return w3;
}

void Node::setType(int type_index)
{
    type = type_index;
}

int Node::getDist() const
{
    return dist;
}

void Node::setDist(int value)
{
    dist = value;
    update();
}

Node::Node(GraphWidget *graphWidget): graph(graphWidget)
{
    setFlags(ItemIsSelectable | ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(+1);
}

void Node::addEdge(Edge *edge)
{
    edgeList << edge;
    edge->adjust();
}

void Node::removeEdge(Edge *deletedEdge)
{
    edgeList.removeAll(deletedEdge);
}

QList<Edge *> Node::edges()
{
    return edgeList;
}

int Node::getIndex()
{
    return index;
}

void Node::setIndex(int index)
{
    this->index = index;
}

QRectF Node::boundingRect() const
{
    qreal adjust = 43;
    return QRectF( -15 - adjust, -15 - adjust, 38 + adjust, 38 + adjust);
}

QPainterPath Node::shape() const
{
    QPainterPath path;
    path.addEllipse(-15, -15, 38, 38);
    return path;
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    // Fill
    if (option->state & QStyle::State_Sunken)//затонувший
    {
        painter->setBrush(QColor(254, 254, 34, 255));
    }
    else if (option->state & QStyle::State_Selected)//выделение вершины
    {
        painter->setBrush(QColor(254, 254, 34, 255));
    }
    else
    {
        painter->setBrush(QColor(colorC, colorM, colorY, colorK));
    }

    painter->setPen(QPen(QColor(130, 180, 130, 255), 3));
    painter->drawEllipse(-15, -15, 38, 38);
    painter->setPen(QPen(Qt::black));
    painter->setFont(QFont("Roboto", 7));
    setZValue(1300);
    QString text = "gv"+QString::number(index);
    if (index < 10)
    {
        painter->drawText(-8, 8, text);
    }
    else
    {
        painter->drawText(-10, 8, text);
    }
    /*text = QString::number(dist);
    painter->setFont(QFont("Roboto", 10, 100));
    painter->setPen(QPen(Qt::red));
    painter->drawText(-20, -20, text);*/
}

QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        foreach (Edge *edge, edgeList)
            edge->adjust();
        break;
    default:
        break;
    }

    return QGraphicsItem::itemChange(change, value);
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
void Node::setHeightColor(int C,int M,int Y,int K)
{
    colorC =C;
    colorM =M;
    colorY =Y;
    colorK =K;
}

void Node::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{

    QGraphicsItem::contextMenuEvent(event);
    if (!this->isSelected())
        return;
    QMenu menu;
    QAction *new_val = menu.addAction("Изменить пропускную способность");
    menu.addSeparator();
    QAction *new_val2 = menu.addAction("Изменить тип вершины");
    menu.addSeparator();
    QAction *selected_action = menu.exec(event->screenPos());
    if(selected_action == new_val)
    {
        // добавить пункт в меню выбора где-то тут
        QMessageBox msgBox;
        QSpinBox *dest = new QSpinBox();
        QSpinBox *length = new QSpinBox();
        length->setRange(0, 10000);
        dest->setRange(0, graph->getEdges().size());
        msgBox.layout()->addWidget(dest);
        msgBox.layout()->addWidget(length);
        msgBox.exec();
        int destNum = dest->value();
        int lengthNum = length->value();
        for (auto i : edges())
            if (i->destNode()->getIndex() == destNum)
            {
                i->setLength(static_cast<unsigned>(lengthNum));
            }
        update();
     }
    if (selected_action == new_val2)
    {
         QMessageBox msgBox2;
         QRadioButton *selectHeightRadioButton1 = new QRadioButton();
         selectHeightRadioButton1->setText("Объекты охраны");
         QRadioButton *selectHeightRadioButton2 = new QRadioButton();
         selectHeightRadioButton2->setText("РУО");
         QRadioButton *selectHeightRadioButton3 = new QRadioButton();
         selectHeightRadioButton3->setText("Главный компьютер");
         QRadioButton *selectHeightRadioButton4 = new QRadioButton();
         selectHeightRadioButton4->setText("Потенциальный нарушитель");
         msgBox2.layout()->addWidget(selectHeightRadioButton1);
         msgBox2.layout()->addWidget(selectHeightRadioButton2);
         msgBox2.layout()->addWidget(selectHeightRadioButton3);
         msgBox2.layout()->addWidget(selectHeightRadioButton4);
         msgBox2.exec();
         if(selectHeightRadioButton1->isChecked())
         {
             colorC =254;
             colorM =254;
             colorY =30;
             colorK =30;
             type = 1;
         }
         if(selectHeightRadioButton2->isChecked())
         {
             colorC =30;
             colorM =200;
             colorY =200;
             colorK =30;
             type = 2;
         }
         if(selectHeightRadioButton3->isChecked())
         {
             colorC =30;
             colorM =30;
             colorY =200;
             colorK =150;
             type = 3;
         }
         if(selectHeightRadioButton4->isChecked())
         {
             colorC =30;
             colorM =200;
             colorY =200;
             colorK =150;
             type = 4;
         }
    }
     setSelected(false);


}
