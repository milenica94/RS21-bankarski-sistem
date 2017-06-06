#include "question.h"

#include <iostream>
#include <QString>
#include <vector>

using namespace std;

Question::Question()
{}

Question::Question(int points, const QString& text, const QString& correctAnswer)
    :_points(points), _text(text), _correctAnswer(correctAnswer)
{}

Question::Question(const Question& q){

    _points = q.points();
    _text = q.text();
    _correctAnswer = q.correctAnswer();
}

Question& Question::operator=(const Question& q){

    if(this != &q){

        _points = q.points();
        _text = q.text();
        _correctAnswer = q.correctAnswer();
    }
    return *this;
}

Question::~Question(){}

int Question::points() const{

    return _points;
}

const QString& Question::text() const{

    return _text;
}

const QString& Question::correctAnswer() const{

    return _correctAnswer;
}

QString Question::askQuestion(const int i) const{
}

int Question::checkAnswer(const QString& answer) const{
}

