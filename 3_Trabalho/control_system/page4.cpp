#include "page4.h"
#include "ui_page4.h"

page4::page4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::page4)
{
    ui->setupUi(this);
    ui->run_btn->hide();
}

page4::~page4()
{
    delete ui;
}

void page4::on_play_pause_btn_clicked()
{
    if(n==0)
    {
        ui->play_pause_btn->setText("Parar");
        ui->run_btn->show();
        n=1;
        QString command = "/home/pi/Documents/Projeto/control_system/planta 4";
        child_pid = fork();

        if(child_pid==0)
        {
            system(qPrintable(command));
            system("/home/pi/Documents/Projeto/control_system/planta 4");
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

void page4::on_back_4_clicked()
{
    page4::close();
}
