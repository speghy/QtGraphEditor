#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>
#include <math.h>
#include <QtMath>
#include <QPainter>
#include "node.h"
#include <QtWidgets>
#include <iostream>
#include <QRegion>

class Edge : public QGraphicsItem
{
    Q_INTERFACES(QGraphicsItem)
private:
    Node *source, *dest;

    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;
    QBrush color;
    Qt::PenStyle	style;
    QGraphicsItemAnimation	*posAnim;
    QTimeLine				*timer;
    QGraphicsScene* scene;
    unsigned length;
    int flow;
    int type = 1;
    int w1=0;
    int w2=0;
    int w3=0;
    int num_e = 0;

public:
    Edge(Node *sourceNode, Node *destNode);
    Edge(Node *sourceNode, Node *destNode, unsigned length);
    Edge(Node *sourceNode, Node *destNode, int w11, int w22, int w33);
    int is_reverse = 0;
    QRectF boundingRect() const;
    Node *sourceNode() const;
    Node *destNode() const;
    QGraphicsScene* getScene();
    void setW(int iw1,int iw2,int iw3);

    void adjust();
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void setColor(QBrush newColor);
    void setStyle(Qt::PenStyle st);
    void setType(int newtype);
    int getType();

    qreal getLength(); //Возвращает длину ребра
    int getFlow();
    void setLength(unsigned value);
    void setFlow(int value);
    void addFlow(int value);
    QGraphicsPixmapItem	*it; //объект на ребре
    void animate(QGraphicsScene *scene, bool auto1);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // EDGE_H
