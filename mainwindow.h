#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "player.h"
#include "report_scene.h"

#include <QMainWindow>
#include <vector>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_connectButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::MainWindow *ui;
   // vector<QuestionABCD*> _questions;
};

#endif // MAINWINDOW_H
