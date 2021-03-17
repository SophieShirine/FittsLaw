#ifndef UTILS_H
#define UTILS_H
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QWidget>

void createFadeIn(QGraphicsOpacityEffect *op, QPropertyAnimation *fadeInAnimation, QWidget *widget);
void createFadeOut(QGraphicsOpacityEffect *op, QPropertyAnimation *fadeOutAnimation, QWidget *widget);

#endif // UTILS_H

