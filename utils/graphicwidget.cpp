#include "graphicwidget.h"
#include <iostream>

GraphicWidget::GraphicWidget() {

}

void GraphicWidget::mousePressEvent(QMouseEvent *event) {
    emit mouseClicked(event->x(), event->y());
}
