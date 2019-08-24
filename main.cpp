#include "urevolution.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    URevolution av;
    Hist* hist = av.ExecuterGenerateurHistoire();
    av.LancerHistoire(hist);
    av.show();

    return a.exec();
}
