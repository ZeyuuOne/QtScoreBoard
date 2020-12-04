#include "score.h"

Score::Score()
{
    increment = 1;
    QVector<int> val;
    val.resize(6);
    his.clear();
    his.push_back(val);
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
    if (his.size()>0) his.pop();
}

QVector<int> Score::getCurrentScore(){
    return his.top();
}

QVector<QString> Score::getTeamName(){
    return teamName;
}
