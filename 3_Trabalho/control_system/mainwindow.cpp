#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_plant1_clicked()
{
    main_form=new MainWindow;
    main_form->hide();
    form1=new page1;
    form1->show();
}
void MainWindow::on_plant2_clicked()
{
    main_form=new MainWindow;
    main_form->hide();
    form2=new page2;
    form2->show();
}

void MainWindow::on_plant3_clicked()
{
    main_form=new MainWindow;
    main_form->hide();
    form3=new page3;
    form3->show();
}



void MainWindow::on_plant4_clicked()
{
    main_form=new MainWindow;
    main_form->hide();
    form4=new page4;
    form4->show();
}
