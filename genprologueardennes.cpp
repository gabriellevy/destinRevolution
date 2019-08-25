#include "genprologueardennes.h"
#include "../destinLib/gestionnairecarac.h"
#include "urevolution.h"
#include "../destinLib/aleatoire.h"
#include "../destinLib/perso.h"
#include "../destinLib/gestionnairecarac.h"
#include "../destinLib/execeffet.h"

QString GenPrologueArdennes::PRIO_ARISTOCRATIE = "Aristocratie";
QString GenPrologueArdennes::PRIO_BOURGEOIS = "Bourgeois";
QString GenPrologueArdennes::PRIO_GUERRIER = "Guerrier";
QString GenPrologueArdennes::PRIO_PRETRE = "Prêtre";
QString GenPrologueArdennes::PRIO_TRAVAILLEUR = "Travailleur";
QString GenPrologueArdennes::PRIO_ERUDIT = "Érudit";
QString GenPrologueArdennes::PRIO_ARTISTE = "Artiste";
QString GenPrologueArdennes::PRIO_MAGICIEN = "Magicien";
QString GenPrologueArdennes::PRIO_MALANDRIN = "Malandrin";

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

QString GenPrologueArdennes::ID_EF_ACCUEIL = "Eveil";
QString GenPrologueArdennes::ID_EF_HOMME_SAUVAGE = "Homme Sauvage";

Effet* GenPrologueArdennes::GenererEveil()
{
    Effet* eveil = m_GenerateurEvt->AjouterEffetNarration("Vous vous éveillez en plein forêt des ardennes et en pleine nuit, l'esprit enbrumé mais le corps hardi. Malgré le danger de votre situation il vous semble que tout vous est possible aujourd'hui et que cette forêt sombre et menaçante est la vôtre. Que faites vous ?",
                                                          "", GenPrologueArdennes::ID_EF_ACCUEIL);

    // les choix
    Choix* choixExplorer = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "Vous partez explorer au hasard", URevolution::VOLONTE, "1");
    choixExplorer->m_GoToEffetId = GenPrologueArdennes::ID_EF_HOMME_SAUVAGE;

    Choix* choixManger = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "Parons au plus pressé : vous cherchez si il y a trace de fruits comestibles dans les environs ou d'animaux à chasser", GenPrologueArdennes::PRIO_TRAVAILLEUR, "1");
    choixManger->m_GoToEffetId = "ChercherAManger";

    Choix* choixReflechir = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "Vous restez où vous êtes et réfléchissez pour comprendre ce qui a bien pu vous arriver", URevolution::INTELLIGENCE, "1");
    choixReflechir->m_GoToEffetId = "ResterReflechir";

    Choix* choixMonterArbre = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "Vous montez en haut d'un arbre pour y dormir en attendant la fin de la nuit", URevolution::HABILETE, "1");
    choixMonterArbre->m_GoToEffetId = "MonterSurArbre";


    return eveil;
}

void GenPrologueArdennes::GenererEvtsAccueil()
{
    /*Evt* Debut = */this->AjouterEvt("Debut", "Génération du perso par les choix");
    GenererEveil();

}
