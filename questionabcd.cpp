#include "questionabcd.h"

#include <iostream>
#include <QString>
#include <vector>

#include <QDebug>

using namespace std;

QuestionABCD::QuestionABCD()
{}

QuestionABCD::QuestionABCD(int points, const QString& text, const QString& correctAnswer,
                   const QString& answer1, const QString& answer2, const QString& answer3, const QString& answer4)
    :Question(points, text, correctAnswer)
{

    _offeredAnswers.push_back(answer1);
    _offeredAnswers.push_back(answer2);

    if(answer3 != "")
        _offeredAnswers.push_back(answer3);
    if(answer4 != "")
        _offeredAnswers.push_back(answer4);
}

QuestionABCD::QuestionABCD(const QuestionABCD& q)
    :Question(q)
{
        _offeredAnswers.clear();

        for(auto i = q.offeredAnswers().begin(); i != q.offeredAnswers().end(); i++)
            _offeredAnswers.push_back(*i);

}

QuestionABCD& QuestionABCD::operator=(const QuestionABCD& q){

    if(this != &q){
        Question::operator =(q);

        _offeredAnswers.clear();

        for(auto i = q.offeredAnswers().begin(); i!= q.offeredAnswers().end(); i++)
            _offeredAnswers.push_back(*i);

    }
    return *this;
}

QuestionABCD::~QuestionABCD()
{}


int QuestionABCD::points() const{

    return Question::points();
}

const QString& QuestionABCD::text() const{

    return Question::text();
}

const QString& QuestionABCD::correctAnswer() const{

    return Question::correctAnswer();
}

const vector<QString>& QuestionABCD::offeredAnswers() const{

    return _offeredAnswers;
}

QString QuestionABCD::askQuestion(const int i) const{

    QString out = "Pitanje broj " + QString::number(i);
    out += " za ";
    out += QString::number(this->points());
    out += " poena: \n" + this->text() + "\n";

    for(auto i = this->offeredAnswers().begin(); i < this->offeredAnswers().end(); i++){
        out += "" + *i + "\n";
    }

    return out;
}

int QuestionABCD::checkAnswer(const QString &answer) const{

    if(answer[0] == this->correctAnswer()[0])
        return this->points();
    else
        return 0;
}
