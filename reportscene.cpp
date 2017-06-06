#include "mainwindow.h"
#include "reportscene.h"
#include "ui_reportscene.h"

#include "player.h"

#include <QDebug>

ReportScene::ReportScene(){}

ReportScene::ReportScene(Player& player, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportScene)
{
    ui->setupUi(this);

    QPixmap bkgnd("C:\\Users\\Natalija\\Desktop\\Fakultet\\IV godina\\Razvoj softvera\\projekat\\labirinthGUI3\\labyrinth.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QString izvestaj = "Igrac ";
    izvestaj.append(player.name());
    izvestaj.append(" trenutno ima ");
    izvestaj.append(QString::number(player.lives()));
    izvestaj.append(" zivota. Nalazi se na ");
    izvestaj.append(QString::number(player.level()));
    izvestaj.append(". nivou. U ovoj sobi ima ");
    izvestaj.append(QString::number(player.roomCount()));
    izvestaj.append(" poena, a ukupno ");
    izvestaj.append(QString::number(player.totalCount()));
    izvestaj.append(" poena.\n");

    ui->Report->setText(izvestaj);

}

ReportScene::~ReportScene()
{
    delete ui;
}

void ReportScene::on_nextButton_clicked(Player& player)
{
    QuestionScene* qs = new QuestionScene(player);
    qs->show();
    this->hide();
}
