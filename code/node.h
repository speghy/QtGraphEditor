#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QList>
#include <QPainter>

class Edge;
class GraphWidget;
QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

class Node : public QGraphicsItem // Вершина графа
{
private:
    int index; // Номер вершины
    QList<Edge *> edgeList; // Список ссылок рёбер, с которыми соединена вершина
    QPointF newPos; // Координаты вершины на экране
    GraphWidget *graph; // Ссылка на виждет, на котором должна отображаться вершина
    int colorC =254;
    int colorM =254;
    int colorY =30;
    int colorK =30;
    int dist = 0;
    int type = 0;
    int w1=0;
    int w2=0;
    int w3=0;

public:
    Node(GraphWidget *graphWidget); // Конструктор

    void addEdge(Edge *edge); // Добавить к этой вершине ребро
    QList<Edge *> edges(); // Вернуть список рёбер, к которыми соединена эта вершина
    void removeEdge(Edge *deletedEdge); // Удалить ребро от этой вершины
    int getIndex(); // Возвращает номер вершины
    void setIndex(int index); // Нумерует вершину
    void setHeightColor(int C,int M,int Y,int K);
    int getType();
    void setType(int type_index);
    int getDist() const;
    void setDist(int value);
    bool checked = 0;
    void setw(int a,int b,int c);
    int geta();
    int getb();
    int getc();
protected:
    QRectF boundingRect() const; // Просчитывает нужные координаты прямоугольника, внутри которого будет вершина
    QPainterPath shape() const; // Делает кликабельную область, в которой находится вершина, кругом, а не прямоугольником
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); // Рисует вершину

    QVariant itemChange(GraphicsItemChange change, const QVariant &value); // Регистрирует изменение положения вершины
    void mousePressEvent(QGraphicsSceneMouseEvent *event); // Регистрирует нажатие на вершину мышкой
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event); // Регистрирует отпускание вершины мышкой
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) Q_DECL_OVERRIDE;
};

#endif // NODE_H
