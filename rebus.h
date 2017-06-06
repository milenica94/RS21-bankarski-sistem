#ifndef REBUS_H
#define REBUS_H

#include "question.h"

#include <QString>

using namespace std;

class Rebus : public Question {

public:
    Rebus();
    Rebus(int points, const QString& text, const QString& correctAnswer);
    Rebus(const Rebus& r);
    Rebus& operator=(const Rebus& r);
    ~Rebus();

    void init(const Rebus& r);
    void deinit();

    int points() const;
    const QString& text() const;
    const QString& correctAnswer() const;

    QString askQuestion(const int i) const;
    int checkAnswer(const QString &answer) const;

};

#endif // REBUS_H
