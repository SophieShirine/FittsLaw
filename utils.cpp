#include "utils.h"

void createFadeIn(QGraphicsOpacityEffect *op, QPropertyAnimation *fadeInAnimation, QWidget *widget){
    op = new QGraphicsOpacityEffect(widget);
    op->setOpacity(0);
    fadeInAnimation = new QPropertyAnimation( op, "opacity" );
    widget->setGraphicsEffect(op);
    fadeInAnimation->setDuration( 500 );
    fadeInAnimation->setStartValue( 1.0 );
    fadeInAnimation->setEndValue( 0.0 );
}

void createFadeOut(QGraphicsOpacityEffect *op, QPropertyAnimation *fadeOutAnimation, QWidget *widget){
    op = new QGraphicsOpacityEffect(widget);
    op->setOpacity(1.0);
    fadeOutAnimation = new QPropertyAnimation(op, "opacity" );
    widget->setGraphicsEffect(op);
    fadeOutAnimation->setDuration( 500 );
    fadeOutAnimation->setStartValue( 1.0 );
    fadeOutAnimation->setEndValue( 0.0 );
}

