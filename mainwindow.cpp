#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "game.h"
#include "player.h"

#include <QDesktopWidget>
#include <QMessageBox>
#include <QDebug>
#include <QFont>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QPixmap bkgnd("C:\\Users\\Natalija\\Desktop\\Fakultet\\IV godina\\Razvoj softvera\\projekat\\labirinthGUI3\\labyrinth.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ui->labelName->palette();
    palette.setColor(ui->labelName->backgroundRole(), Qt::white);
    palette.setColor(ui->labelName->foregroundRole(), Qt::white);
    ui->labelName->setPalette(palette);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connectButton_clicked()
{

    // Kada se igrac poveze, prvo se napravi igra i kreira se putanja

    Game game;

    // Kreira se novi igrac;

    QString name = ui->lineEditName->text();

    if (name == "")
    {
        QMessageBox::warning(this, "Neispravan unos",
                             "Naziv predmeta ne moze biti prazan!", QMessageBox::Ok);
        return;
    }

   // if(name != ""){

        Player player1(name);

        Report_scene rs(player1, 1, game.getPutanja());
        this->hide();
        rs.setModal(true);
        rs.exec();


  //  else
    //    this->close();
}

void MainWindow::on_cancelButton_clicked()
{
    this->close();
}
