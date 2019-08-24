#include "genprologueardennes.h"
#include "../destinLib/gestionnairecarac.h"
#include "urevolution.h"
#include "../destinLib/aleatoire.h"
#include "../destinLib/perso.h"
#include "../destinLib/gestionnairecarac.h"
#include "../destinLib/execeffet.h"

GenPrologueArdennes::GenPrologueArdennes(Hist* histoireGeneree):GenHistoire (histoireGeneree) {}

Hist* GenPrologueArdennes::GenererHistoire()
{
    GenererPersos();

    //GenererFonctionsCallback();

    GenererCaracs();

    GenererEvtsAccueil();

    return m_HistoireGeneree;
}

void GenPrologueArdennes::GenererPersos()
{
    QString nom = "pas encore déterminé";
    DPerso* perso = new DPerso(nom, nom, nom, "");
    perso->InitialiserPerso();
    IPerso::AjouterPersoJouable(perso);
}

void GenPrologueArdennes::GenererCaracs()
{
    //GetUniversSkaven()->GenererTousLesClans();
    // initilisée via le perso
}

void GenPrologueArdennes::GenererEvtsAccueil()
{
    /*Evt* Debut = */this->AjouterEvt("Debut", "Génération du eprso par les choix");

    m_GenerateurEvt->AjouterEffetNarration("Bonjour à vous qui arrivez dans la forêt des ardennes !");
}
