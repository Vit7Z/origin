#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  ui->rBtn_1->setText("Опция 1");
  ui->rBtn_2->setText("Опция 2");

  int counter = 7;
  for(int i = 0; i < counter; ++i) {
    ui->list_1->addItem("Элемент " + QString::number(i+1));
  }

  ui->pBtn_1->setText("Кнопка");
  ui->pBtn_1->setCheckable(true);

  ui->pBar_1->setMinimum(0);
  ui->pBar_1->setMaximum(10);
  ui->pBar_1->setValue(0);

  ui->pBar_1->setStyleSheet(
    "QProgressBar {text-align: center;}"
    "QProgressBar::chunk {background-color: green;}");
    ui->gb_main->setTitle("");
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pBtn_1_clicked(bool checked) {
  if (ui->pBar_1->value() < ui->pBar_1->maximum()) {
    ui->pBar_1->setValue(ui->pBar_1->value() + 1);
  }
  else {
    ui->pBar_1->setValue(0);
  }
}
