#include "page1.h"
#include "ui_page1.h"


page1::page1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::page1)
{
    ui->setupUi(this);
    ui->run_btn->hide();



}

page1::~page1()
{
    delete ui;
}

void page1::on_back_clicked()
{
    page1::close();

}

void page1::on_play_pause_btn_clicked()
{
    if(n==0)
    {
        ui->play_pause_btn->setText("Parar");
        ui->run_btn->show();
        n=1;
        QString command = "/home/pi/Documents/Projeto/control_system/planta 1";
        child_pid = fork();

        if(child_pid==0)
        {
            system(qPrintable(command));
            system("/home/pi/Documents/Projeto/control_system/planta 1");
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
