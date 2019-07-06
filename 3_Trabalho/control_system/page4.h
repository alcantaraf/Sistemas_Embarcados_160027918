#ifndef PAGE4_H
#define PAGE4_H

#include <QDialog>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <QDialog>
#include <QProcess>

namespace Ui {
class page4;
}

class page4 : public QDialog
{
    Q_OBJECT

public:
    explicit page4(QWidget *parent = 0);
    ~page4();

private slots:
    void on_play_pause_btn_clicked();

    void on_back_4_clicked();

private:
    Ui::page4 *ui;
    int n=0;
    pid_t child_pid;
};

#endif // PAGE4_H
