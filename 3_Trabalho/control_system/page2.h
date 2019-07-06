#ifndef PAGE2_H
#define PAGE2_H

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <QDialog>
#include <QProcess>

namespace Ui {
class page2;
}

class page2 : public QDialog
{
    Q_OBJECT

public:
    explicit page2(QWidget *parent = nullptr);
    ~page2();

private slots:
    void on_back_2_clicked();

    void on_play_pause_btn_clicked();


private:
    Ui::page2 *ui;
    int n=0;
    pid_t child_pid;
};

#endif // PAGE2_H
