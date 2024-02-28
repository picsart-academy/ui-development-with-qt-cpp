#include "counterapplication.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CounterApplication w;
    w.show();
    return a.exec();
}
