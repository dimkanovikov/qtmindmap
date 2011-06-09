#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "node.h"


class GraphWidget : public QGraphicsView
{
    Q_OBJECT


public:
    GraphWidget(QWidget *parent = 0);
    QGraphicsScene *getScene();
    void setActiveNode(Node *node);
    void insertNode();

protected:

    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);
    void scaleView(qreal scaleFactor);
    void drawBackground(QPainter *painter, const QRectF &rect);


private:

    void showingAllNodeNumbers(const bool &show = true);
    void showingNodeNumbersBeginWithNumber(const int &number, const bool &show = true);
    bool numberStartsWithNumber(const int &number, const int &prefix);

    QList<Node *> m_nodeList;
    Node *m_activeNode;
    QGraphicsScene *m_scene;
    bool m_showingNodeNumbers;
    QString m_followNumber;
    Node *m_followNode;

};

#endif // GRAPHWIDGET_H
