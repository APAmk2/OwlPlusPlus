#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "funcs.cpp"

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

int cnt = 1;

void MainWindow::on_Crypt_btn_clicked()
{
    string in = (ui->Input->toPlainText()).toStdString();
    for (int i = 1; i <= cnt; ++i)
    {
        in = crypt(in);
    }
    QString qstr = QString::fromStdString(in);
    ui->Output->setPlainText(qstr);
}

void MainWindow::on_Decrypt_btn_clicked()
{
    string in = (ui->Input->toPlainText()).toStdString();
    for (int i = 1; i <= cnt; ++i)
    {
        in = decrypt(in);
    }
    QString qstr = QString::fromStdString(in);
    ui->Output->setPlainText(qstr);
}

void MainWindow::on_cnt_box_valueChanged(int arg1)
{
    cnt = arg1;
}
