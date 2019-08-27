#ifndef GENPROLOGUEARDENNES_H
#define GENPROLOGUEARDENNES_H

#include "../destinLib/genhistoire.h"

class URevolution;

class GenPrologueArdennes : public GenHistoire
{
public:
    GenPrologueArdennes(Hist* histoireGeneree);

    virtual Hist* GenererHistoire();

protected:
    // génère toutes les caracs qui peuvent être visualisées par le joueur (d'autres caracs peuvent être générées et invisibles n'importe quand dans l'aventure)
    virtual void GenererCaracs();
    virtual void GenererPersos();

    static QString ID_EF_ACCUEIL;
    static QString ID_EF_HOMME_SAUVAGE;
    static QString ID_EF_HISTOIRE_ERMITE;
    static QString ID_EF_APRES_HISTOIRE_ERMITE; // à renommer évidemment...

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
    static QString PRIO_AVENTURIER;
    static QString PRIO_REVOLUTION;

private:
    // génération de l'événement de base
    void GenererEvtsAccueil();

    // génération de tous les effets (mini événements)
    Effet* GenererEveil();
    Effet* GenererHommeSauvage();
    Effet* GenererHistoireErmite();

};

#endif // GENPROLOGUEARDENNES_H
