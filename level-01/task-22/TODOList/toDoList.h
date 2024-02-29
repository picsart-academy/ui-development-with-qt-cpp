#ifndef TODOLIST_H
#define TODOLIST_H

#include <QMainWindow>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>

class ToDoList : public QMainWindow
{
    Q_OBJECT

public:
    ToDoList(QWidget *parent = nullptr);
    ~ToDoList();

protected:
    void keyPressEvent(QKeyEvent*) override; // For use keyborad

private slots:
    void addTask();
    void removeTask();
    void init();
private:
    QLineEdit* taskLineEdit;
    QListWidget* taskListWidget;
    QPushButton* addButton;
    QPushButton* removeButton;
};

#endif // TODOLIST_H
