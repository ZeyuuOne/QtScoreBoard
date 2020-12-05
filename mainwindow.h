#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <score.h>
#include <timer.h>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void increaseSignal(int i);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QLabel* labelScore[6];
    QLabel* labelTeamName[6];
    QProgressBar* progressBarScore[6];
    QClickWidget* widgetTeamScore[6];
    Score score;
    Timer timer;

public slots:
    void refreshScoreView();
    void increase(int i);
    void revoke();
};
#endif // MAINWINDOW_H
