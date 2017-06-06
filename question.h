#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <QString>
#include <vector>

using namespace std;

class Question {

public:
    Question();
    Question(int points, const QString& text, const QString& correctAnswer);
    Question(const Question& q);
    Question& operator=(const Question& q);
    virtual ~Question();

    virtual int points() const;
    virtual const QString& text() const;
    virtual const QString& correctAnswer() const;

    virtual QString askQuestion(const int i) const;
    virtual int checkAnswer(const QString& answer) const = 0;

private:
    int _points;
    QString _text;
    QString _correctAnswer;
};

#endif // QUESTION_H
