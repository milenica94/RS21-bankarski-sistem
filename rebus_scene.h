#ifndef REBUS_SCENE_H
#define REBUS_SCENE_H

#include <QDialog>

#include "player.h"
#include "rebus.h"

namespace Ui {
class Rebus_scene;
}

class Rebus_scene : public QDialog
{
    Q_OBJECT

public:
    explicit Rebus_scene(Player& player, vector<Rebus*> questions, int rbrSobe, int rbrPitanja, vector<int> path, QWidget *parent = 0);
    ~Rebus_scene();
    void whatNext(Player& player, vector<Rebus*> questions, int rbrSobe, int rbrPitanja);

signals:
    void next();

private slots:
    void on_inputButton_clicked();
    void whatNext();

private:
    Ui::Rebus_scene *ui;
    int _rbrPitanja;
    int _rbrSobe;
    vector<Rebus*> _questions;
    Rebus _rebus;
    Player _player;
    vector<int> _path;
};

#endif // REBUS_SCENE_H
