#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleSubmitButtonClick();

private:
    QLineEdit *m_email;
    QLineEdit *m_password;
    QPushButton *m_submitButton;
};

#endif // MAINWINDOW_H
