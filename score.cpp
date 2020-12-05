#include "score.h"
#include "qfile.h"
#include "qtextstream.h"

Score::Score()
{
    increment = 1;
    QVector<int> val;
    val.resize(6);
    his.clear();
    his.push_back(val);
    QFile in("D:/team.txt");
    if (!in.open(QIODevice::ReadOnly | QIODevice::Text)){
    };
    teamName.resize(6);
    QTextStream textStream(&in);
    for (int i=0;i<6;i++){
        QString teamNameStr = textStream.readLine();
        teamName[i]=teamNameStr;
    }
    in.close();
}

void Score::setIncrement(int _increament){
    increment = _increament;
}

void Score::increase(int index){
    QVector<int> val = his.top();
    val[index] += increment;
    his.push(val);
}

void Score::revoke(){
    if (his.size()>1) his.pop();
}

QVector<int> Score::getCurrentScore(){
    return his.top();
}

QVector<QString> Score::getTeamName(){
    return teamName;
}

int Score::getIncrement(){
    return increment;
}
