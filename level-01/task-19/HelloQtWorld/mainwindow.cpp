#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed); // Set the size policy to Fixed
    ui->label->setMinimumSize(200, 100); // Set minimum width to 200 pixels and minimum height to 100 pixels
    ui->label->setMaximumSize(200, 100); // Set maximum width to 200 pixels and maximum height to 100 pixels

    QFont font("Arial", 16); // Create a QFont object with Arial font and size 16
    ui->label->setFont(font); // Set the font for the QLabel


    ui->label->setText("Hello, Qt World!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

