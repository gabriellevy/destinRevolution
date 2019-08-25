#ifndef HEROS_H
#define HEROS_H

#include "../destinLib/perso.h"
#include "../destinLib/gestionnairecarac.h"

class URevolution;

class Heros : public DPerso
{
public:
    Heros(QString id, QString nom, QString description, QString CheminImagePortrait);

    void InitialiserPerso();

    URevolution* GetURevolution();
};

#endif // HEROS_H
