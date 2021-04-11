#ifndef GRAPHICWIDGET_H
#define GRAPHICWIDGET_H

#include <QGraphicsView>
#include <QMouseEvent>

/*
 * GraphicWidget class, that handles the user clics on the window.
 */
class GraphicWidget : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicWidget();
signals:
    void mouseClicked(int,int);

protected:
    void mousePressEvent(QMouseEvent *event);
};
#endif // GRAPHICWIDGET_H
