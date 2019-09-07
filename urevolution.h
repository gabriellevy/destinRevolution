#ifndef UREVOLUTION_H
#define UREVOLUTION_H

#include "../destinLib/univers.h"
#include <QMainWindow>

class URevolution : public Univers
{
    Q_OBJECT

public:
    URevolution(ModeAffichage modeAffichage = ModeAffichage::ema_Jeu,
                QWidget *parent = nullptr);

    static QString HIST_PROLOGUE_REVOLUTION;

    // caractérisiques principales (au sens jdr)
    static QString HABILETE;
    static QString PUISSANCE;
    static QString CHARISME;
    static QString INTELLIGENCE;
    static QString VOLONTE;
    static QString PERCEPTION;

private:

};

#endif // UREVOLUTION_H
