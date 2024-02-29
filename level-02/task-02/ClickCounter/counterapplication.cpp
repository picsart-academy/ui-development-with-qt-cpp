#include "counterapplication.h"
#include "./ui_counterapplication.h"

CounterApplication::CounterApplication(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CounterApplication), m_count{}
{
    ui->setupUi(this);
    // Connect button click signal to slot
    connect(ui->pushButton, &QPushButton::clicked, this, &CounterApplication::incrementCount);
}

CounterApplication::~CounterApplication()
{
    delete ui;
}

void CounterApplication::incrementCount()
{
    ++m_count;
    ui->label->setText("Count: " + QString::number(m_count));
}
