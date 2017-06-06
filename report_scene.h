#ifndef REPORT_SCENE_H
#define REPORT_SCENE_H

#include <QDialog>

#include "player.h"

namespace Ui {
class Report_scene;
}

class Report_scene : public QDialog
{
    Q_OBJECT

public:
    Report_scene(Player& player, int rbrSobe, vector<int> path, QWidget *parent = 0);
    ~Report_scene();

signals:
    void youWon();
    void youLost();

private slots:
    void on_nextBtn_clicked();
    void gameWon();
    void gameLost();

    void on_leftButton_clicked();

    void on_rightButton_clicked();

private:
    Ui::Report_scene *ui;
    Player _player;
    int _rbrSobe;
    vector<int> _path;
};

#endif // REPORT_SCENE_H
