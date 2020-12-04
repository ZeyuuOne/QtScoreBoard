#ifndef SCORE_H
#define SCORE_H

#include "QVector"
#include "QStack"

class Score
{
private:
    int increment;
    QVector<QString> teamName;
    QStack<QVector<int>> his;

public:
    Score();
    Score(int _num);
    void setIncrement(int _increament);
    void increase(int index);
    void revoke();
    QVector<int> getCurrentScore();
    QVector<QString> getTeamName();
};

#endif // SCORE_H
