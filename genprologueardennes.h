#ifndef GENPROLOGUEARDENNES_H
#define GENPROLOGUEARDENNES_H

#include "../destinLib/genhistoire.h"

class URevolution;

class GenPrologueArdennes : public GenHistoire
{
public:
    GenPrologueArdennes();

    virtual Hist* GenererHistoire();

protected:
    // génère toutes les caracs qui peuvent être visualisées par le joueur (d'autres caracs peuvent être générées et invisibles n'importe quand dans l'aventure)
    virtual void GenererCaracs();
    virtual void GenererPersos();

    static QString ID_EF_ACCUEIL;
    static QString ID_EF_HOMME_SAUVAGE;
    static QString ID_EF_HISTOIRE_ERMITE;
    static QString ID_EF_OIE;
    static QString ID_EF_PERDU;
    static QString ID_EF_AUBERON;
    static QString ID_EF_DOLMEN;
    static QString ID_EF_ARBRE_SACRE;
    static QString ID_EF_COCAGNE;
    static QString ID_EF_NUAGES;

    static QString ID_EF_PROCHAIN_EFFET;

    // caracs temporaires qui calculent les priorités du personnages dans les diverses valeurs pour déterminer ses caracs à la fin du jeu
    static QString PRIO_RELIGION;
    static QString PRIO_ORDRE;
    static QString PRIO_FORCE;
    static QString PRIO_NOBLESSE;
    static QString PRIO_LUMIERE;
    static QString PRIO_TRAVAIL;
    static QString PRIO_LIBERTE;
    static QString PRIO_SAVOIR;
    static QString PRIO_ART;
    static QString PRIO_FEERIE;

private:
    // génération de l'événement de base
    void GenererEvtsAccueil();

    // génération de tous les effets (mini événements)
    Effet* GenererEveil(QString idDebut, QString idFin);
    Effet* GenererHommeSauvage(QString idDebut, QString idFin);
    Effet* GenererHistoireErmite(QString idDebut, QString idFin);
    Effet* GenererOieSauvage(QString idDebut, QString idFin);
    Effet* GenererPerdu(QString idDebut, QString idFin);
    Effet* GenererAuberon(QString idDebut, QString idFin);
    Effet* GenererDolmen(QString idDebut, QString idFin);
    Effet* GenererArbreSacre(QString idDebut, QString idFin);
    Effet* GenererCocagne(QString idDebut, QString idFin);
    Effet* GenererNuages(QString idDebut, QString idFin);

};

#endif // GENPROLOGUEARDENNES_H
