#ifndef PAGE1_H
#define PAGE1_H

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <QDialog>
#include <QProcess>

namespace Ui {
class page1;
}

class page1 : public QDialog
{
    Q_OBJECT

public:
    explicit page1(QWidget *parent = nullptr);
    ~page1();

private slots:
    void on_back_clicked();
    void on_play_pause_btn_clicked();


private:
    Ui::page1 *ui;
    int n=0;
    pid_t child_pid;
};

#endif // PAGE1_H
