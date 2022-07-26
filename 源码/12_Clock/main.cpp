#include "TweClock.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TweClock w;
    w.show();

    return a.exec();
}
