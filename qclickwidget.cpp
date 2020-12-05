#include "qclickwidget.h"

QClickWidget::QClickWidget(QWidget *parent) : QWidget(parent)
{

}

void QClickWidget::mousePressEvent(QMouseEvent *ev)
{
    mousePos = QPoint(ev->x(), ev->y());
}

void QClickWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    if(mousePos == QPoint(ev->x(), ev->y())) emit clicked();
}
