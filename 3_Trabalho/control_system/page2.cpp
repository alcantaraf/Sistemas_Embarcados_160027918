#include "page2.h"
#include "ui_page2.h"

//int n=0;

page2::page2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::page2)
{
    ui->setupUi(this);
    ui->run_btn->hide();
}

page2::~page2()
{
    delete ui;
}

void page2::on_back_2_clicked()
{
    page2::close();
}

void page2::on_play_pause_btn_clicked()
{
    if(n==0)
    {
        ui->play_pause_btn->setText("Parar");
        ui->run_btn->show();
        n=1;
        QString command = "/home/pi/Documents/Projeto/control_system/planta 2";
        child_pid = fork();

        if(child_pid==0)
        {
            system(qPrintable(command));
            system("/home/pi/Documents/Projeto/control_system/planta 2");
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

