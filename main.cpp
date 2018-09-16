#include "revolution.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Revolution* av = new Revolution(eh_Mirabeau);
    av->show();

    return a.exec();
}
