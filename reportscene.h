#ifndef REPORTSCENE_H
#define REPORTSCENE_H

#include <QWidget>

#include "mainwindow.h"
#include "questionscene.h"
#include "player.h"


namespace Ui {
class ReportScene;
}

class ReportScene : public QWidget
{
    Q_OBJECT

public:
    ReportScene();
    explicit ReportScene(Player& player, QWidget *parent = 0);
    ~ReportScene();

private slots:
    void on_nextButton_clicked(Player& );

private:
    Ui::ReportScene *ui;
};

#endif // REPORTSCENE_H
