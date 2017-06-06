#include "questionscene.h"
#include "ui_questionscene.h"

#include "player.h"
#include "question.h"
#include "questionabcd.h"
#include "rebus.h"

#include <QTextEdit>
#include <QString>
#include <QPixmap>
#include <QPalette>
#include <QVector>

QuestionScene::QuestionScene(Player& player, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuestionScene)
{
    ui->setupUi(this);

    QPixmap bkgnd("C:\\Users\\Natalija\\Desktop\\Fakultet\\IV godina\\Razvoj softvera\\projekat\\labirinthGUI3\\question_marks.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ui->rebusAnswer->hide();
    ui->answer3->hide();
    ui->answer4->hide();

    ui->player1Label->setText(player.name());

    ui->player1Label->palette();
    palette.setColor(ui->player1Label->backgroundRole(), Qt::white);
    palette.setColor(ui->player1Label->foregroundRole(), Qt::white);
    ui->player1Label->setPalette(palette);

    QuestionABCD question1(10, "Koliko ima studenata u ovom timu?", "c)", "a) Jedan", "b) Dva", "c) Tri");

    ui->question->setText(question1.askQuestion(1));

    if(question1.offeredAnswers().size() >= 3){
        ui->answer3->show();
    }
    if(question1.offeredAnswers().size() == 4){
        ui->answer4->show();
    }

}

QuestionScene::~QuestionScene()
{
    delete ui;
}

void QuestionScene::on_answer1_clicked(QuestionABCD& question)
{
    // Proverava se odgovor
    int point;

    point = question.checkAnswer(ui->answer1->text());

    ui->question->setText(ui->answer1->text());

   /* if(point > 0)
        ui->question->setText("TACAN ODGOVOR!");
    else
        ui->question->setText("NETACAN ODGOVOR!");*/

   /* player->setRoomCount(player->roomCount() + point);
    player->setTotalCount(player->totalCount() + point);*/
}

void QuestionScene::on_answer2_clicked(QuestionABCD& question)
{
    int point;

    point = question.checkAnswer(ui->answer2->text());
    ui->question->setText(ui->answer2->text());

  /*  if(point > 0)
        ui->question->setText("TACAN ODGOVOR!");
    else
        ui->question->setText("NETACAN ODGOVOR!");*/

    /*player->setRoomCount(player->roomCount() + point);
    player->setTotalCount(player->totalCount() + point);*/
}

void QuestionScene::on_answer3_clicked(QuestionABCD& question)
{
    int point;

    point = question.checkAnswer(ui->answer3->text());
    ui->question->setText(ui->answer3->text());

   /* if(point > 0)
        ui->question->setText("TACAN ODGOVOR!");
    else
        ui->question->setText("NETACAN ODGOVOR!");*/

    /*player->setRoomCount(player->roomCount() + point);
    player->setTotalCount(player->totalCount() + point);*/
}

void QuestionScene::on_answer4_clicked(QuestionABCD& question)
{
    int point;

    point = question.checkAnswer(ui->answer4->text());

   /* if(point > 0)
        ui->question->setText("TACAN ODGOVOR!");
    else
        ui->question->setText("NETACAN ODGOVOR!");*/

   /* player->setRoomCount(player->roomCount() + point);
    player->setTotalCount(player->totalCount() + point);*/
}
