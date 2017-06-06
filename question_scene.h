#ifndef QUESTION_SCENE_H
#define QUESTION_SCENE_H

#include <QDialog>

#include "player.h"
#include "questionabcd.h"

namespace Ui {
class Question_scene;
}

class Question_scene : public QDialog
{
    Q_OBJECT

public:
    explicit Question_scene(Player& player, vector<QuestionABCD*> questions, int rbrSobe, int rbrPitanja, vector<int> path, QWidget *parent = 0);
    ~Question_scene();

signals:
    void next();

private slots:
    void on_answer1_clicked();
    void on_answer2_clicked();
    void on_answer3_clicked();
    void on_answer4_clicked();
    void whatNext();

private:
    Ui::Question_scene *ui;
    QuestionABCD _question;
    vector<QuestionABCD*> _questions;
    int _rbrPitanja;
    int _rbrSobe;
    Player _player;
    vector<int> _path;
};

#endif // QUESTION_SCENE_H
