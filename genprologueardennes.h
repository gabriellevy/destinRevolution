#ifndef GENPROLOGUEARDENNES_H
#define GENPROLOGUEARDENNES_H

#include "../destinLib/genhistoire.h"

class URevolution;

class GenPrologueArdennes : public GenHistoire
{
public:
    GenPrologueArdennes(Hist* histoireGeneree);

    virtual Hist* GenererHistoire();

    Effet* GenererEveil();

protected:
    // génère toutes les caracs qui peuvent être visualisées par le joueur (d'autres caracs peuvent être générées et invisibles n'importe quand dans l'aventure)
    virtual void GenererCaracs();
    virtual void GenererPersos();

    static QString ID_EF_ACCUEIL;
    static QString ID_EF_HOMME_SAUVAGE;

    // caracs temporaires qui calculent les priorités du joueur pour en déterminer ses caracs à la fin du jeu
    static QString PRIO_ARISTOCRATIE;
    static QString PRIO_BOURGEOIS;
    static QString PRIO_GUERRIER;
    static QString PRIO_PRETRE;
    static QString PRIO_TRAVAILLEUR;
    static QString PRIO_ERUDIT;
    static QString PRIO_ARTISTE;
    static QString PRIO_MAGICIEN;
    static QString PRIO_MALANDRIN;

private:
    void GenererEvtsAccueil();

};

#endif // GENPROLOGUEARDENNES_H
