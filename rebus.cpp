#include "rebus.h"

#include <QString>
#include <algorithm>

using namespace std;

void to_lower(string& s){

    transform(s.begin(), s.end(), s.begin(), [](unsigned char c){return tolower(c);});
}

Rebus::Rebus()
{}

Rebus::Rebus(int points, const QString& text, const QString& correctAnswer)
    :Question(points, text, correctAnswer)
{}

Rebus::Rebus(const Rebus& r)
    :Question(r)
{}

Rebus& Rebus::operator=(const Rebus& r){

    if(this != &r){

       Question::operator=(r);
    }
    return *this;
}

Rebus::~Rebus(){}

int Rebus::points() const{

    return Question::points();
}

const QString& Rebus::text() const{

    return Question::text();
}

const QString& Rebus::correctAnswer() const{

    return Question::correctAnswer();
}

QString Rebus::askQuestion(const int i) const{

    QString out = "Pitanje broj " + QString::number(i);
    out += " za ";
    out += QString::number(this->points());
    out += " poena: \n" + this->text() + "\n";
    return out;

}

int Rebus::checkAnswer(const QString &answer) const{


    string a = answer.toUtf8().constData();
    to_lower(a);

    if(QString::fromStdString(a) == this->correctAnswer())
        return this->points();
    else
        return 0;
}
