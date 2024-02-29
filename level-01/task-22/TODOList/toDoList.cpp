#include <QVBoxLayout>
#include <QKeyEvent>
#include <QDebug>

#include "toDoList.h"

ToDoList::ToDoList(QWidget *parent)
    : QMainWindow(parent)
{
    this->init();
}


ToDoList::~ToDoList()
{
    delete taskLineEdit;
    delete taskListWidget;
    delete addButton;
    delete removeButton;
}

void ToDoList::init()
{
    // Create line edit for task input
    taskLineEdit = new QLineEdit;

    // Create list widget to display tasks
    taskListWidget = new QListWidget;

    // Create buttons for adding and removing tasks
    addButton = new QPushButton("Add");
    removeButton = new QPushButton("Remove");

    // Connect signals and slots
    connect(addButton, &QPushButton::clicked, this, &ToDoList::addTask);
    connect(removeButton, &QPushButton::clicked, this, &ToDoList::removeTask);

    // Set up layout
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(taskLineEdit);
    layout->addWidget(taskListWidget);
    layout->addWidget(addButton);
    layout->addWidget(removeButton);

    // Create central widget and set layout
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void ToDoList::addTask()
{
    QString task = taskLineEdit->text();
    if (!task.isEmpty())
    {
        taskListWidget->addItem(task);
        taskLineEdit->clear();
    }
}

void ToDoList::removeTask()
{
    int selectedIndex = taskListWidget->currentRow();
    if (selectedIndex != -1)
    {
        delete taskListWidget->takeItem(selectedIndex);
    }
}

void ToDoList::keyPressEvent(QKeyEvent* event)
{
    qDebug() << event->key();
    switch (event->key())
    {
        case Qt::Key_Enter:
        case Qt::Key_Return:
            addTask();
            break;
        case Qt::Key_Delete:
        case Qt::Key_Backspace:
            removeTask();
            break;

    }
}

