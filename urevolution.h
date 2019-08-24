#ifndef UREVOLUTION_H
#define UREVOLUTION_H

#include "../destinLib/univers.h"
#include <QMainWindow>

/**
 * @brief Univers revolution : all he base things of the universe in genberal are referenced here
 */
class URevolution : public Univers
{
    Q_OBJECT

public:
    URevolution(ModeAffichage modeAffichage = ModeAffichage::ema_Jeu,
                QWidget *parent = nullptr);

    Hist* ExecuterGenerateurHistoire();

private:

};

#endif // UREVOLUTION_H
