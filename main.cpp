#include "urevolution.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    URevolution universRev;
    universRev.LancerHistoire(URevolution::HIST_PROLOGUE_REVOLUTION);
    universRev.show();

    return a.exec();
}
