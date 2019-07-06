#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "page1.h"
#include "page2.h"
#include "page3.h"
#include "page4.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
   ~MainWindow();

private slots:
    void on_plant1_clicked();

    void on_plant2_clicked();

    void on_plant3_clicked();

    void on_plant4_clicked();

private:
    Ui::MainWindow *ui;
    page1 *form1;
    page2 *form2;
    page3 *form3;
    page4 *form4;
    MainWindow *main_form;

};

#endif // MAINWINDOW_H


