#ifndef COUNTER_APPLICATION_H
#define COUNTER_APPLICATION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CounterApplication; }
QT_END_NAMESPACE

class CounterApplication : public QMainWindow
{
    Q_OBJECT

public:
    CounterApplication(QWidget *parent = nullptr);
    ~CounterApplication();

private slots:
    void incrementCount();

private:
    Ui::CounterApplication *ui;
    int m_count;
};
#endif // COUNTER_APPLICATION_H
