#ifndef CHOOSE_PATH_SCENE_H
#define CHOOSE_PATH_SCENE_H

#include "player.h"

#include <QDialog>
#include <vector>

namespace Ui {
class Choose_path_scene;
}

class Choose_path_scene : public QDialog
{
    Q_OBJECT

public:
    explicit Choose_path_scene(Player& player, int rbrSobe, vector<int> putanja, QWidget *parent = 0);
    ~Choose_path_scene();

private slots:
    void on_leftButton_clicked();

    void on_rightButton_clicked();

private:
    Ui::Choose_path_scene *ui;
    Player _player;
    int _rbrSobe;
    vector<int> _putanja;
};

#endif // CHOOSE_PATH_SCENE_H
