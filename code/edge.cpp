#include "edge.h"
//#include "Node.h"

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;
static int num = 0;

Edge::Edge(Node *sourceNode, Node *destNode): arrowSize(15)
{
    setAcceptedMouseButtons(nullptr);
    setCacheMode(DeviceCoordinateCache);
    source = sourceNode;
    dest = destNode;
    source->addEdge(this);
    dest->addEdge(this);
    adjust();
    length = 100;
    flow = 0;
    color = Qt::black;

    timer = new QTimeLine; //создание таймера
    timer->setFrameRange(0,500);
    timer->setLoopCount(1);

    posAnim= new QGraphicsItemAnimation; //создание анимации
    posAnim->setTimeLine(timer);
    it = new QGraphicsPixmapItem;
    num_e=num;
     num++;
}
void Edge::setW(int iw1, int iw2, int iw3)
{
    w1=iw1;
    w2=iw2;
    w3=iw3;
    setLength(length);

}

Edge::Edge(Node *sourceNode, Node *destNode, unsigned length) : Edge(sourceNode, destNode)
{

    w1=source->geta();
    w2=source->getb();
    w3=source->getc();
    qDebug()<<w1<<w2<<w3;
    setLength(length);
    num_e=num;
}
Edge::Edge(Node *sourceNode, Node *destNode, int w11, int w22, int w33)
{

    setLength(length);
}
QGraphicsScene* Edge::getScene()
{
    return scene;
}

void Edge::setType(int newtype)
{
    type= newtype;
}
int Edge::getType()
{
    return type;
}

void Edge::setColor(QBrush newColor)
{
    color = newColor;
    setZValue(999);
}

void Edge::setStyle(Qt::PenStyle st)
{
    style = st;
    update();
}
Node *Edge::sourceNode() const
{
    return source;
}

Node *Edge::destNode() const
{
    return dest;
}

void Edge::adjust()
{
    if (!source || !dest) return;

    QLineF line(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));
    qreal length = line.length();

    prepareGeometryChange();
    QPointF edgeOffset((line.dx() * 22) / length, (line.dy() * 22) / length);

    //    Рисование простого ребра
    if (length > qreal(30.))
    {
        QPointF edgeOffset((line.dx() * 22) / length, (line.dy() * 22) / length);
        sourcePoint = line.p1() + edgeOffset;
        destPoint = line.p2() - edgeOffset;
    }
    else
    {
        sourcePoint = destPoint = line.p1();
    }
}


qreal Edge::getLength()
{
    return length;
}

int Edge::getFlow()
{
    return flow;
}

void Edge::setLength(unsigned value)
{

    length = value;
    update();
}

void Edge::setFlow(int value)
{
    flow = value;
    update();
}

void Edge::addFlow(int value)
{
    flow += value;
    update();
}

QRectF Edge::boundingRect() const
{
    if (!source || !dest) return QRectF();

    qreal penWidth = 2;
    qreal extra = (penWidth + arrowSize)+60;

    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
                                      destPoint.y() - sourcePoint.y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (!source || !dest) return;
    painter->setRenderHint(QPainter::Antialiasing);

    QLineF line(sourcePoint, destPoint);
    if (qFuzzyCompare(line.length(), qreal(0.))) return;

    // Draw the line
    painter->setPen(QPen(color, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);
    QFont font;
    font.setPixelSize(15);
    painter->setFont(font);

    // Draw the arrows
    double angle = ::acos(line.dx() / line.length());
    if (line.dy() >= 0)
        angle = TwoPi - angle;

    QPointF destArrowP1 = destPoint + QPointF(sin(angle - Pi / 3) * arrowSize,
                                              cos(angle - Pi / 3) * arrowSize);
    QPointF destArrowP2 = destPoint + QPointF(sin(angle - Pi + Pi / 3) * arrowSize,
                                              cos(angle - Pi + Pi / 3) * arrowSize);
    int weight = static_cast<int>(length);

    float float_weight = weight*0.01;
    QString output;
    if(is_reverse!=1)
    {
        if(type!=3)
        {
        output += "ge" + QString::number(num_e)+":"+QString::number(float_weight) ;
        }
        else
        {

                float float_w1 = 0.01*w1;
                float float_w2 = 0.01*w2;
                float float_w3 = 0.01*w3;
                output += "ge" + QString::number(num_e)+ ": " +
                        QString::number(float_w1) +      "  " +
                        QString::number(float_w2) +      "  " +
                        QString::number(float_w3);

        }
    }
    if (flow != 0)
        output += " F:" + QString::number(flow);
    if (flow < 0)
    {
        QPointF bottom = {(sourcePoint.rx()+destPoint.rx())/2, (sourcePoint.ry()+destPoint.ry())/2-20};
         painter->drawText(bottom, output);
    }
    else
        painter->drawText((sourcePoint+destPoint)/2, output);
    painter->setBrush(Qt::black);
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);
}
void Edge::animate(QGraphicsScene *scene, bool auto1)
{
    if(sourcePoint == destPoint)
        return;

    QLineF line(sourcePoint, destPoint);

/**/    double angle = ::acos(line.dx() / line.length());
    if (line.dy() >= 0)
        angle = TwoPi - angle;
//Пусть объект движется по прямой, а не по дуге
    QPointF c = 0.5*line.p1() + 0.5*line.p2();// +QPointF(-sin(angle)*40,cos(Pi - angle)*40);
//    QPointF c = 0.5*line.p1() + 0.5*line.p2() +QPointF(-sin(angle)*40,cos(Pi - angle)*40);

    QPainterPath a;
    a.moveTo(sourcePoint);
    a.quadTo(c,destPoint);
    timer->setDuration(static_cast<int>(a.length()/0.1));
    if (auto1)
    {
        QPixmap p(":/cars/1.png");
        it->setPixmap(p); //установить изображение на объект
        it->setOffset(-p.size().width()/2.0,-p.size().height()/2.0); //установка центра
        it->setZValue(0.5);
        it->setPos(sourceNode()->scenePos());
        it->setTransformationMode(Qt::SmoothTransformation);
        posAnim->setItem(it);
    }
/**/
// эта часть кода обеспечивает движение
    bool ce = true;
    for(int i = 0; i <= 10; i++)
    {
        qreal p = i/10.0;
        qreal p_pred =0;
        if(i>0)
            p_pred =(i-1)/10.0;
        if(a.angleAtPercent(p) > a.angleAtPercent(p_pred))
            ce = false;
        if(i==0)
            posAnim->setPosAt(p,sourceNode()->scenePos());
         else if(i==10)
            posAnim->setPosAt(p,destNode()->scenePos());
        else
            posAnim->setPosAt(p,a.pointAtPercent(p));

/**/        posAnim->setRotationAt(p,
                               ce
                               ? -a.angleAtPercent(p)
                                 : 360 - a.angleAtPercent(p)
                               );/**/
    }/**/
    if (!auto1)
    {
        QGraphicsEllipseItem* a1 = scene->addEllipse(0, 0, 10, 10);
        QColor col = Qt::black;
        a1->setParentItem(this);
        a1->setPos(sourcePoint);
        a1->setPen(QPen(col, 0));
        a1->setBrush(QBrush(col));
        a1->update();
        posAnim->setItem(a1);

    }
    scene->addItem(it);
    timer->start();

    // Соединение завершения таймера и удаление всех созданных объектов
//   connect(timer,&QTimeLine::finished,posAnim,&QGraphicsItemAnimation::deleteLater);

}

/* какая-та хаета */

// Установка контексного меню при правом клике мышью

void Edge::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{/*
    QGraphicsItem::contextMenuEvent(event);
    setSelected(true);
    // Создание меню
    QMenu menu;
        QAction *  new_val = menu.addAction("Изменить пропускную способность");
    menu.addSeparator();
        QAction * remove_action = menu.addAction("Удалить ребро");
    menu.addSeparator();
        QAction * setFirstType = menu.addAction("Установить тип вершины 1");
    menu.addSeparator();
        QAction * setSecondType = menu.addAction("Установить тип вершины 2");
    menu.addSeparator();
         QAction * setFirdype = menu.addAction("Установить тип вершины 3");
   // Выбор пункта меню
    QAction * selected_action = menu.exec(event->screenPos());
    // Выполнение действий
    if(selected_action == remove_action)
               QMessageBox::information(0,"info","Пока не выполняется!");
     if(selected_action == new_val)
     {
         QMessageBox msgBox;
         QSpinBox *spin = new QSpinBox();
         spin->setRange(0, 10000);
         msgBox.layout()->addWidget(spin);
         msgBox.exec();
         length = spin->value();
         this->adjust();
         update();
     }
     if(selected_action==setFirstType)
     {
         setColor(QBrush(Qt::black));
     }
     if(selected_action==setSecondType)
     {
         setColor(QBrush(Qt::white));
     }
     if(selected_action==setFirdype)
     {
         setColor(QBrush(Qt::red));
     }
     setSelected(false);*/
}
