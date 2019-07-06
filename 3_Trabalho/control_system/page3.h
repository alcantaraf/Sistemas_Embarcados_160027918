#ifndef PAGE3_H
#define PAGE3_H

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <QDialog>
#include <QProcess>

namespace Ui {
class page3;
}

class page3 : public QDialog
{
    Q_OBJECT

public:
    explicit page3(QWidget *parent = nullptr);
    ~page3();

private slots:
    void on_back_3_clicked();

    void on_play_pause_btn_clicked();


private:
    Ui::page3 *ui;
    int n=0;
    pid_t child_pid;
};

#endif // PAGE3_H
