#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qclickwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowTitle("知识竞赛");
    labelScore[0] = ui->labelScore1;
    labelScore[1] = ui->labelScore2;
    labelScore[2] = ui->labelScore3;
    labelScore[3] = ui->labelScore4;
    labelScore[4] = ui->labelScore5;
    labelScore[5] = ui->labelScore6;
    labelTeamName[0] = ui->labelTeamName1;
    labelTeamName[1] = ui->labelTeamName2;
    labelTeamName[2] = ui->labelTeamName3;
    labelTeamName[3] = ui->labelTeamName4;
    labelTeamName[4] = ui->labelTeamName5;
    labelTeamName[5] = ui->labelTeamName6;
    progressBarScore[0] = ui->progressBarScore1;
    progressBarScore[1] = ui->progressBarScore2;
    progressBarScore[2] = ui->progressBarScore3;
    progressBarScore[3] = ui->progressBarScore4;
    progressBarScore[4] = ui->progressBarScore5;
    progressBarScore[5] = ui->progressBarScore6;
    widgetTeamScore[0] = ui->widgetTeamScore1;
    widgetTeamScore[1] = ui->widgetTeamScore2;
    widgetTeamScore[2] = ui->widgetTeamScore3;
    widgetTeamScore[3] = ui->widgetTeamScore4;
    widgetTeamScore[4] = ui->widgetTeamScore5;
    widgetTeamScore[5] = ui->widgetTeamScore6;
    for (int i=0;i<6;i++) progressBarScore[i]->setRange(0,200);
    ui->lineEditIncrement->setText("1");
    ui->lineEditTimeLength->setText("60");
    ui->labelTime->setText("00:00");
    connect(widgetTeamScore[0],&QClickWidget::clicked,this,[&](){this->increase(0);});
    connect(widgetTeamScore[1],&QClickWidget::clicked,this,[&](){this->increase(1);});
    connect(widgetTeamScore[2],&QClickWidget::clicked,this,[&](){this->increase(2);});
    connect(widgetTeamScore[3],&QClickWidget::clicked,this,[&](){this->increase(3);});
    connect(widgetTeamScore[4],&QClickWidget::clicked,this,[&](){this->increase(4);});
    connect(widgetTeamScore[5],&QClickWidget::clicked,this,[&](){this->increase(5);});
    connect(ui->pushButtonRevoke,&QPushButton::clicked,this,&MainWindow::revoke);
    refreshScoreView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshScoreView(){
    bool ok;
    int increment = ui->lineEditIncrement->text().toInt(&ok);
    if (ok) score.setIncrement(increment);
    else ui->lineEditIncrement->setText(QString::number(score.getIncrement()));
    for (int i=0;i<6;i++){
        labelScore[i]->setText(QString::number(score.getCurrentScore()[i]));
        progressBarScore[i]->setValue(score.getCurrentScore()[i]);
        labelTeamName[i]->setText(score.getTeamName()[i]);
    }
    update();
}

void MainWindow::increase(int i){
    bool ok;
    int increment = ui->lineEditIncrement->text().toInt(&ok);
    if (ok) score.setIncrement(increment);
    else ui->lineEditIncrement->setText(QString::number(score.getIncrement()));
    score.increase(i);
    refreshScoreView();
}

void MainWindow::revoke(){
    score.revoke();
    refreshScoreView();
}
