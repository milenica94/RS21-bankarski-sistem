#include "rebus_scene.h"
#include "ui_rebus_scene.h"

#include "player.h"
#include "rebus.h"
#include "report_scene.h"

#include <QPixmap>
#include <QPalette>
#include <QDebug>
#include <QTime>

void delay(int n)           // n je broj sekundi
{
    QTime dieTime= QTime::currentTime().addSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

Rebus_scene::Rebus_scene(Player& player, vector<Rebus*> questions, int rbrSobe, int rbrPitanja, vector<int> path, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rebus_scene)
{
    ui->setupUi(this);


    QFont font("Segoe Print", 10);
    ui->question->setFont(font);
    ui->rebusAnswer->setFont(font);

    connect(this, SIGNAL(next()), this, SLOT(whatNext()));

    _player = player;
    _questions = questions;
    _rbrPitanja = rbrPitanja;
    _rebus = *_questions[_rbrPitanja];
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

    ui->question->setText(_rebus.askQuestion(++_rbrPitanja));

}

Rebus_scene::~Rebus_scene()
{
    delete ui;
}


void Rebus_scene::on_inputButton_clicked()
{
    int poeni = 0;

    poeni = _rebus.checkAnswer(ui->rebusAnswer->text());

    if(poeni > 0){
        delay(0.5);
        ui->rebusAnswer->setStyleSheet("background-color: rgb(80, 231, 118)");

        _player.setRoomCount(_player.roomCount() + poeni);
        _player.setTotalCount(_player.totalCount() + poeni);
    }
    else if (poeni == 0){
        ui->rebusAnswer->setStyleSheet("background-color: red");
        ui->question->setText("Tacan odgovor je \n" + _rebus.correctAnswer());
    }
    delay(1);
    emit next();
}


void Rebus_scene::whatNext(){

    if(_rbrPitanja < 3){

        // Vraca se na pocetno

        ui->question->clear();
        ui->rebusAnswer->clear();
        ui->rebusAnswer->setStyleSheet("QLabel { background-color: rgb(236, 233, 216); color : blue; }");

        // Uzima se novo pitanje i postavlja

        _rebus = *_questions[_rbrPitanja];

        ui->question->setText(_rebus.askQuestion(++_rbrPitanja));

     }
     else{          // Ako je pitao 3 pitanja, ide na izvestaj
         Report_scene rs(_player, _rbrSobe, _path);
         this->hide();
         rs.setModal(true);
         rs.exec();
     }
}

