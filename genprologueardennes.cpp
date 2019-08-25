#include "genprologueardennes.h"
#include "../destinLib/gestionnairecarac.h"
#include "urevolution.h"
#include "../destinLib/aleatoire.h"
#include "../destinLib/perso.h"
#include "../destinLib/gestionnairecarac.h"
#include "../destinLib/execeffet.h"
#include "heros.h"

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
    Heros* perso = new Heros(nom, nom, nom, "");
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

Effet* GenPrologueArdennes::GenererHommeSauvage()
{
    Effet* effet = m_GenerateurEvt->AjouterEffetNarration("Vous vous approchez discrètement. Le bruit que vous faites est de toute façon couvert par les cris de femmes qui redoublent au fur et à mesure que vous vous approchez. Enfin, après avoir passé un buisson vous appercevez à quelques centaines de mètres un bien étrange spectacle. C'est bien une femme qui crie. Une grande paysanne rousse grassouillette, et elle se trouve sur l'épaule d'un très grand homme apparemment nu mais extraordinairement poilu. C'est un homme sauvage ! Et la femme qui se débat désespérément est sans doute une pauvre villageoise qu'il a enlevé pour assouvir la lubricité typique de sa race.",
                                                          ":/Images/Ardennes/HommeSauvage.jpg", GenPrologueArdennes::ID_EF_HOMME_SAUVAGE);
    // les choix
    Choix* choixCombat = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "Vous sortez votre arme et le chargez", GenPrologueArdennes::PRIO_GUERRIER, "1");
    choixCombat->m_GoToEffetId = "combatHommeSauvage";

    Choix* choixInterpeller = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "Vous interpelez le sauvage", GenPrologueArdennes::PRIO_BOURGEOIS, "1"); // bof...
    choixInterpeller->m_GoToEffetId = "discussionHommeSauvage";

    Choix* choixEmbuscade = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "Vous tentez de le doubler discrètement pour dépasser sa position et lui tendre une embuscade", GenPrologueArdennes::PRIO_MALANDRIN, "1");
    choixEmbuscade->m_GoToEffetId = "embuscadeHommeSauvage";

    Choix* choixEviter = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "Vous préférez ne pas vous en mêler. Ce n'est pas à vous de régler les conflits entre sauvages et civilisés", GenPrologueArdennes::PRIO_MALANDRIN, "1");
    choixEviter->m_GoToEffetId = "eviterHommeSauvage";

    // embuscade
    Effet* embuscade = m_GenerateurEvt->AjouterEffetNarration("Vous parvenez à le doubler rapidement. Il a beau être très grand il est très ralenti par son fardeau. Vous vous postez dans un arbre et, comme prévu, il va passer dessous dans une dizaine de secondes.",
                                                              "", "embuscadeHommeSauvage");
    embuscade->AjouterChangeurDeCarac("embuscadeHommeSauvage", "1"); // donne un avantage en cas de bagarre

    Choix* choixEmbuscade1 = m_GenerateurEvt->AjouterChoixGoToEffet(
                 "Vous l'interpelez tout en le tenant en joue avec votre arc", "discussionHommeSauvage");

    // discussionHommeSauvage
    Effet* discussionHommeSauvage = m_GenerateurEvt->AjouterEffetNarration("Quand vous l'interpellez l'homme sauvage réagit mollement, sans inquiétude ni agressivité et vous regarde. La femme, dans sa position sur son épaule ne peut pas vous voir mais appelle à l'aide et crie qu'un monstre l'a enlevée à son village et veut la manger. Le sauvage gromelle qu'il a déjà mangé mais qu'il a besoin d'une femme pour être son épouse. La femme est scandalisée et lui hurle de la lâcher ce qu'il refuse de faire. Que lui dites vous ?",
                                                              "", "discussionHommeSauvage");

    Choix* discussionRelache = m_GenerateurEvt->AjouterChoixGoToEffet(
                 "Vous lui dites qu'il est interdit d'enlever les femmes ainsi et qu'il doit la relâcher", "discussionHommeSauvageRelache");


    Effet* discussionHommeSauvageRelache = m_GenerateurEvt->AjouterEffetNarration("L'homme sauvage répond que quand un homem est assez fort pour prendre une femme il est normal qu'il la garde. Mais, tout en grognant, il articule tout de même que par générosité si il peut copuler une fois avec la femme il la laissera partir. Il ajoute bruyamment avec un sourire que bien sûr si après ça elle décide de rester elle sera la bienvenue. La villageoise proteste mollement qu'elle est déjà mariée.",
                                                              "", "discussionHommeSauvageRelache");
    Choix* discussionAttaque = m_GenerateurEvt->AjouterChoixGoToEffet(
                 "Assez discuté vous l'attaquez", "combatHommeSauvage");
    discussionAttaque->AjouterAjouteurACarac(GenPrologueArdennes::PRIO_GUERRIER, "1");

    return effet;
}

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
    GenererHommeSauvage();

}
