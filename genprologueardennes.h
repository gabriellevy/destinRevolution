#ifndef GENPROLOGUEARDENNES_H
#define GENPROLOGUEARDENNES_H

#include "../destinLib/genhistoire.h"

class URevolution;

class GenPrologueArdennes : public GenHistoire
{
public:
    GenPrologueArdennes();

    virtual Hist* GenererHistoire();

    // caracs temporaires qui calculent les priorités du personnages dans les diverses valeurs pour déterminer ses caracs à la fin du jeu
    static QString RELIGION;
    static QString ORDRE;
    static QString FORCE;
    static QString NOBLESSE;
    static QString LUMIERE;
    static QString TRAVAIL;
    static QString INDIVIDUALISME;
    static QString SAVOIR;
    static QString ART;
    static QString FEERIE;

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
    static QString ID_EF_REVE;
    static QString ID_EF_FIN;

    static QString ID_EF_PROCHAIN_EFFET;

private:
    // génération de l'événement de base
    void GenererEvtsAccueil();

    // génération de tous les effets (mini événements)
    void GenererEveil(QString idDebut, QString idFin);
    void GenererHommeSauvage(QString idDebut, QString idFin);
    void GenererHistoireErmite(QString idDebut, QString idFin);
    void GenererOieSauvage(QString idDebut, QString idFin);
    void GenererPerdu(QString idDebut, QString idFin);
    void GenererAuberon(QString idDebut, QString idFin);
    void GenererDolmen(QString idDebut, QString idFin);
    void GenererArbreSacre(QString idDebut, QString idFin);
    void GenererCocagne(QString idDebut, QString idFin);
    void GenererNuages(QString idDebut, QString idFin);
    void GenererReve(QString idDebut, QString idFin);
    void GenererCompteRendu(QString idDebut, QString idFin);

};

#endif // GENPROLOGUEARDENNES_H
