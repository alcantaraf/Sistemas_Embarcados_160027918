#include "page3.h"
#include "ui_page3.h"

//int n=0;

page3::page3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::page3)
{
    ui->setupUi(this);
    ui->run_btn->hide();
}

page3::~page3()
{
    delete ui;
}

void page3::on_back_3_clicked()
{
    page3::close();
}

void page3::on_play_pause_btn_clicked()
{
    if(n==0)
    {
        ui->play_pause_btn->setText("Parar");
        ui->run_btn->show();
        n=1;
        QString command = "/home/pi/Documents/Projeto/control_system/planta 3";
        child_pid = fork();

        if(child_pid==0)
        {
            system(qPrintable(command));
            system("/home/pi/Documents/Projeto/control_system/planta 3");
            exit(1);
        }
    }
    else
    {
        n=0;
        ui->play_pause_btn->setText("Iniciar");
        ui->run_btn->hide();
        while (n<3) {
            n++;
            system("killall planta");
        }
        n=0;

    }

}

