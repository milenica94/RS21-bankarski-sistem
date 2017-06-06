#ifndef QUESTIONABCD_H
#define QUESTIONABCD_H

#include "question.h"

#include <iostream>
#include <QString>
#include <vector>

using namespace std;

class QuestionABCD : public Question {

public:
    QuestionABCD();
    QuestionABCD(int points, const QString& text, const QString& correctAnswer,
             const QString& answer1, const QString& answer2, const QString& answer3="", const QString& answer4="");
    QuestionABCD(const QuestionABCD& q);
    QuestionABCD& operator=(const QuestionABCD& q);
    ~QuestionABCD();

    void init(const QuestionABCD& q);
    void deinit();

    int points() const;
    const QString& text() const;
    const QString& correctAnswer() const;
    const vector<QString>& offeredAnswers() const;

    QString askQuestion(const int i) const;
    int checkAnswer(const QString &answer) const;

private:
    vector<QString> _offeredAnswers;
};

ostream & operator <<(ostream& out, const QuestionABCD& question);

#endif // QUESTIONABCD_H
