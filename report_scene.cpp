#include "report_scene.h"
#include "ui_report_scene.h"

#include "question_scene.h"
#include "rebus_scene.h"
#include "room.h"

#include <map>
#include <QDebug>
#include <QPixmap>
#include <QPalette>
#include <unistd.h>

map<int, string> kategorija = {{1,"igraonica"},{2,"istorija"},{3,"nauka"},{4,"umetnost"},{5,"igraonica"}};

Report_scene::Report_scene(Player& player, int rbrSobe, vector<int> path, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Report_scene)
{
    ui->setupUi(this);

    QFont font("Segoe Print", 10);
    ui->Report->setFont(font);

    ui->leftButton->hide();
    ui->rightButton->hide();

    QPixmap bkgnd("C:\\Users\\Natalija\\Desktop\\Fakultet\\IV godina\\Razvoj softvera\\projekat\\labirinthGUI3\\labyrinth.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ui->Report->setStyleSheet("QLabel{ background-color : white; color : black; }");
    ui->Report->setAlignment(Qt::AlignCenter);

    connect(this, SIGNAL(youWon()), this, SLOT(gameWon()));
    connect(this, SIGNAL(youLost()), this, SLOT(gameLost()));

  /*  QPixmap pix("C:\\Users\\Natalija\\Desktop\\Fakultet\\IV godina\\Razvoj softvera\\projekat\\labirinthGUI3\\cloud.jpg");
    ui->Report->setPixmap(pix);
    ui->Report->setScaledContents(true);
    ui->Report->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );*/

    _player = player;
    _rbrSobe = rbrSobe;
    _path = path;

    QString izvestaj = "";

    if(_rbrSobe == 1){

        izvestaj.append("Dobrodosli u Lavirint!");
    }

    else if(_rbrSobe != 1){

        izvestaj.append(_player.name());
        izvestaj.append(", u ovoj sobi ste osvojili ");
        izvestaj.append(QString::number(_player.roomCount()));
        izvestaj.append(" poena, a ukupno za sada imate ");
        izvestaj.append(QString::number(_player.totalCount()));
        izvestaj.append(".\n");

        if(_player.roomCount() == 30){
            izvestaj.append("Kako imate 30 poena u ovoj sobi, birate da li zelite da idete levo ili desno.\n");

            ui->nextBtn->hide();
            ui->leftButton->show();
            ui->rightButton->show();

        }

        else if(_player.roomCount() > 30){
            _player.setLevel(_player.level() + 1);
            izvestaj.append("Prelazite na ");
            izvestaj.append(QString::number(_player.level()));
            izvestaj.append(". nivo!\n");
            izvestaj.append("Trenutno imate ");
            izvestaj.append(QString::number(_player.lives()));
            izvestaj.append(" zivota.\n");

        }

        else{
            _player.setLives(_player.lives() - 1);
            izvestaj.append("Nazalost, gubite zivot.\nOstajete na ");
            izvestaj.append(QString::number(_player.level()));
            izvestaj.append(". nivou.\n");
            izvestaj.append("Trenutno imate ");
            switch (_player.lives()) {
            case 1:
                izvestaj.append(QString::number(_player.lives()));
                izvestaj.append(" zivot.\n");
                break;
            default:
                izvestaj.append(QString::number(_player.lives()));
                izvestaj.append(" zivota.\n");
                break;
            }

        }
    }

    if(_player.lives() == 0){
        izvestaj.clear();
        izvestaj.append("Zao nam je, izgubili ste sve zivote. Ostajete zarobljeni u lavirintu!");
    }

    if(_rbrSobe == 6 && _player.lives() > 0){
        izvestaj.clear();
        izvestaj.append("Cestitamo! Uspeli ste da pronadjete izlaz iz lavirinta!");
    }

    ui->Report->setText(izvestaj);

}

Report_scene::~Report_scene()
{
    delete ui;
}

void Report_scene::on_nextBtn_clicked()
{

    if(ui->Report->text().startsWith("Cestitamo"))
        emit youWon();
    if(ui->Report->text().startsWith("Zao"))
        emit youLost();

    if(_rbrSobe <= 5 && _player.lives() > 0){

        Room room(kategorija, _rbrSobe);
        _player.setRoomCount(0);

        if(_rbrSobe == 1 || _rbrSobe == 5){

            Rebus_scene rs(_player, room.rebus(), ++_rbrSobe, 0, _path);
            this->hide();
            rs.setModal(true);
            rs.exec();
        }

        else{
            Question_scene qs(_player, room.questions(), ++_rbrSobe, 0, _path);
            this->hide();
            qs.setModal(true);
            qs.exec();
        }
    }

}

void Report_scene::on_leftButton_clicked()
{
    // 1 je oznaka za levo, 0 za desno

    qDebug() << QString::number(_path[_rbrSobe-1]);
    qDebug() << QString::number(_rbrSobe);

    QString izvestaj = "";

    if(_path[_rbrSobe - 1] == 1){

        _player.setLevel(_player.level() + 1);
        izvestaj.append("Prelazite na ");
        izvestaj.append(QString::number(_player.level()));
        izvestaj.append(". nivo!\n");
        izvestaj.append("Trenutno imate ");
        izvestaj.append(QString::number(_player.lives()));
        izvestaj.append(" zivota.\n");

    }

    else{

        _player.setLives(_player.lives() - 1);
        izvestaj.append("Nazalost, gubite zivot.\nOstajete na ");
        izvestaj.append(QString::number(_player.level()));
        izvestaj.append(". nivou.\n");
        izvestaj.append("Trenutno imate ");
        izvestaj.append(QString::number(_player.lives()));
        izvestaj.append(" zivota.\n");
    }

    ui->Report->setText(izvestaj);

    ui->leftButton->hide();
    ui->rightButton->hide();
    ui->nextBtn->show();
}

void Report_scene::on_rightButton_clicked()
{

    qDebug() << QString::number(_path[_rbrSobe-1]);
    qDebug() << QString::number(_rbrSobe);

    QString izvestaj = "";

    if(_path[_rbrSobe - 1] == 0){

        _player.setLevel(_player.level() + 1);
        izvestaj.append("Prelazite na ");
        izvestaj.append(QString::number(_player.level()));
        izvestaj.append(". nivo!\n");
        izvestaj.append("Trenutno imate ");
        izvestaj.append(QString::number(_player.lives()));
        izvestaj.append(" zivota.\n");

    }

    else{

        _player.setLives(_player.lives() - 1);
        izvestaj.append("Nazalost, gubite zivot.\nOstajete na ");
        izvestaj.append(QString::number(_player.level()));
        izvestaj.append(". nivou.\n");
        izvestaj.append("Trenutno imate ");
        izvestaj.append(QString::number(_player.lives()));
        izvestaj.append(" zivota.\n");
    }

    ui->Report->setText(izvestaj);

    ui->leftButton->hide();
    ui->rightButton->hide();
    ui->nextBtn->show();
}

void Report_scene::gameWon(){

    this->close();
}

void Report_scene::gameLost(){

    this->close();
}


