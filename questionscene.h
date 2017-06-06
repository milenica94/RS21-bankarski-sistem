#ifndef QUESTIONSCENE_H
#define QUESTIONSCENE_H

#include "player.h"
#include "question.h"
#include "questionabcd.h"
#include "rebus.h"

#include <QDialog>
#include <QVector>

namespace Ui {
class QuestionScene;
}

class QuestionScene : public QDialog
{
    Q_OBJECT

public:
    QuestionScene();
    explicit QuestionScene(Player& player, QWidget *parent = 0);
    ~QuestionScene();

private slots:
    void on_answer1_clicked(QuestionABCD& );

    void on_answer2_clicked(QuestionABCD& );

    void on_answer3_clicked(QuestionABCD& );

    void on_answer4_clicked(QuestionABCD& );

private:
    Ui::QuestionScene *ui;
    Player* player;
};

#endif // QUESTIONSCENE_H
