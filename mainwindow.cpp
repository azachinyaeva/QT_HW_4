#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pBar->setMinimum(0);
    ui->pBar->setMaximum(10);
    ui->pBar->setValue(0);

    ui->Progress->setCheckable(true);

    for (int i = 0; i < 6; ++i) {
        ui->cb_list->addItem("Element " + QString::number(i));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Progress_clicked()
{
    int progress = ui->pBar->value();
    ui->pBar->setValue(progress+1);
    if (progress >= 10)
        ui->pBar->setValue(0);
}


void MainWindow::on_Progress_toggled(bool checked)
{
    if(checked) {
        ui->Progress->setText("Clicked");
    }
    else {
        ui->Progress->setText("Not clicked");
    }

}

