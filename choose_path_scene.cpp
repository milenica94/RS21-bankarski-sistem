#include "choose_path_scene.h"
#include "ui_choose_path_scene.h"

#include "game.h"


Choose_path_scene::Choose_path_scene(Player& player, int rbrSobe, vector<int> path, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Choose_path_scene)
{
    ui->setupUi(this);


}

Choose_path_scene::~Choose_path_scene()
{
    delete ui;
}

void Choose_path_scene::on_leftButton_clicked()
{



}


void Choose_path_scene::on_rightButton_clicked()
{



}
