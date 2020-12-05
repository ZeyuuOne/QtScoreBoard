#ifndef QCLICKWIDGET_H
#define QCLICKWIDGET_H

#include <QWidget>
#include <QPoint>
#include <QMouseEvent>

class QClickWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QClickWidget(QWidget *parent = nullptr);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

private:
    QPoint mousePos;
};

#endif // QCLICKWIDGET_H
