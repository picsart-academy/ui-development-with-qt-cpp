#include "mainwindow.h"
#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create line edits
    m_email = new QLineEdit;
    m_password = new QLineEdit;

    // Create submit button
    m_submitButton = new QPushButton("Submit");
    connect(m_submitButton, &QPushButton::clicked, this, &MainWindow::handleSubmitButtonClick);

    // Set up layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_email);
    layout->addWidget(m_password);
    layout->addWidget(m_submitButton);

    // Create central widget and set layout
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::handleSubmitButtonClick()
{
    // Validation logic
    if (m_email->text().isEmpty() || m_password->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "Fields cannot be empty!");
    }
    else
    {
        QMessageBox::information(this, "Success", "Form submitted successfully!");
    }
}
