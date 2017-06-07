#include "question_scene.h"
#include "ui_question_scene.h"

#include "player.h"
#include "questionabcd.h"
#include "report_scene.h"

#include <QPixmap>
#include <QPalette>
#include <QDebug>
#include <QTime>

void delay(int n);    

Question_scene::Question_scene(Player& player, vector<QuestionABCD*> questions, int rbrSobe, int rbrPitanja, vector<int> path, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_scene)
{
    ui->setupUi(this);

    QFont font("Segoe Print", 10);
    ui->question->setFont(font);
    ui->answer1->setFont(font);
    ui->answer2->setFont(font);
    ui->answer3->setFont(font);
    ui->answer4->setFont(font);

    connect(this, SIGNAL(next()), this, SLOT(whatNext()));

    _player = player;
    _questions = questions;
    _rbrPitanja = rbrPitanja;
    _question = *_questions[_rbrPitanja];
    _rbrSobe = rbrSobe;
    _path = path;

    QPixmap bkgnd("C:\\Users\\Natalija\\Desktop\\Fakultet\\IV godina\\Razvoj softvera\\projekat\\labirinthGUI3\\question_marks.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ui->player1Label->setText(_player.name());

    ui->player1Label->palette();
    palette.setColor(ui->player1Label->backgroundRole(), Qt::white);
    palette.setColor(ui->player1Label->foregroundRole(), Qt::white);
    ui->player1Label->setPalette(palette);


    // Pojavljuju se ako ovi odgovori postoje
    ui->answer3->hide();
    ui->answer4->hide();


    ui->question->setText(_question.askQuestion(++_rbrPitanja));

    if(_question.offeredAnswers().size() >= 3){
        ui->answer3->show();
    }
    if(_question.offeredAnswers().size() == 4){
        ui->answer4->show();
    }

}

Question_scene::~Question_scene()
{
    delete ui;
}

void Question_scene::on_answer1_clicked()
{
    int poeni = _question.checkAnswer(ui->answer1->text());

    if(poeni > 0){
        delay(0.5);
        ui->answer1->setStyleSheet("background-color: rgb(80, 231, 118)");
        _player.setRoomCount(_player.roomCount() + poeni);
        _player.setTotalCount(_player.totalCount() + poeni);
    }

    else if(poeni == 0){
        ui->answer1->setStyleSheet("background-color: red");
        if(ui->answer2->text()[0] == _question.correctAnswer())
            ui->answer2->setStyleSheet("background-color: rgb(80, 231, 118)");
        else if(ui->answer3->text()[0] == _question.correctAnswer())
            ui->answer3->setStyleSheet("background-color: rgb(80, 231, 118)");
        else if(ui->answer4->text()[0] == _question.correctAnswer())
            ui->answer4->setStyleSheet("background-color: rgb(80, 231, 118)");
    }
    delay(1);
    emit next();
}

void Question_scene::on_answer2_clicked()
{

    int poeni = _question.checkAnswer(ui->answer2->text());

    if(poeni > 0){
        delay(0.5);
        ui->answer2->setStyleSheet("background-color: rgb(80, 231, 118)");
        _player.setRoomCount(_player.roomCount() + poeni);
        _player.setTotalCount(_player.totalCount() + poeni);
    }

    else if(poeni == 0){
        ui->answer2->setStyleSheet("background-color: red");
        if(ui->answer1->text()[0] == _question.correctAnswer())
            ui->answer1->setStyleSheet("background-color: rgb(80, 231, 118)");
        else if(ui->answer3->text()[0] == _question.correctAnswer())
            ui->answer3->setStyleSheet("background-color: rgb(80, 231, 118)");
        else if(ui->answer4->text()[0] == _question.correctAnswer())
            ui->answer4->setStyleSheet("background-color: rgb(80, 231, 118)");
    }
    delay(1);
    emit next();
}

void Question_scene::on_answer3_clicked()
{
    int poeni = _question.checkAnswer(ui->answer3->text());

    if(poeni > 0){
        delay(0.5);
        ui->answer3->setStyleSheet("background-color: rgb(80, 231, 118)");
        _player.setRoomCount(_player.roomCount() + poeni);
        _player.setTotalCount(_player.totalCount() + poeni);
    }

    else if(poeni == 0){
        ui->answer3->setStyleSheet("background-color: red");
        if(ui->answer1->text()[0] == _question.correctAnswer())
            ui->answer1->setStyleSheet("background-color: rgb(80, 231, 118)");
        else if(ui->answer2->text()[0] == _question.correctAnswer())
            ui->answer2->setStyleSheet("background-color: rgb(80, 231, 118)");
        else if(ui->answer4->text()[0] == _question.correctAnswer())
            ui->answer4->setStyleSheet("background-color: rgb(80, 231, 118)");
    }
    delay(1);
    emit next();

}

void Question_scene::on_answer4_clicked()
{
    int poeni = _question.checkAnswer(ui->answer4->text());

    if(poeni > 0){
        delay(0.5);
        ui->answer4->setStyleSheet("background-color: rgb(80, 231, 118)");
        _player.setRoomCount(_player.roomCount() + poeni);
        _player.setTotalCount(_player.totalCount() + poeni);
    }

    else if(poeni == 0){
        ui->answer4->setStyleSheet("background-color: red");
        if(ui->answer1->text()[0] == _question.correctAnswer())
            ui->answer1->setStyleSheet("background-color: rgb(80, 231, 118)");
        else if(ui->answer2->text()[0] == _question.correctAnswer())
            ui->answer2->setStyleSheet("background-color: rgb(80, 231, 118)");
        else if(ui->answer3->text()[0] == _question.correctAnswer())
            ui->answer3->setStyleSheet("background-color: rgb(80, 231, 118)");
    }
    delay(1);
    emit next();
}

void Question_scene::whatNext(){

    if(_rbrPitanja < 3){

        // Vraca se na pocetno

        ui->question->clear();
        ui->answer1->setStyleSheet("background-color: rgb(236, 233, 216)");
        ui->answer2->setStyleSheet("background-color: rgb(236, 233, 216)");
        ui->answer3->setStyleSheet("background-color: rgb(236, 233, 216)");
        ui->answer4->setStyleSheet("background-color: rgb(236, 233, 216)");
        ui->answer3->hide();
        ui->answer4->hide();

        // Uzima se novo pitanje i postavlja

        _question = *_questions[_rbrPitanja];

        ui->question->setText(_question.askQuestion(++_rbrPitanja));

        if(_question.offeredAnswers().size() >= 3){
            ui->answer3->show();
        }
        if(_question.offeredAnswers().size() == 4){
            ui->answer4->show();
        }

    }
    else{           // Ako je pitao 3 pitanja, ide na izvestaj
        Report_scene rs(_player, _rbrSobe, _path);
        this->hide();
        rs.setModal(true);
        rs.exec();
    }

}
