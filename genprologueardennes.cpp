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
QString GenPrologueArdennes::PRIO_AVENTURIER = "Aventurier";
QString GenPrologueArdennes::PRIO_REVOLUTION = "Revolution";

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
QString GenPrologueArdennes::ID_EF_HISTOIRE_ERMITE = "Histoire ermite";
QString GenPrologueArdennes::ID_EF_APRES_HISTOIRE_ERMITE = "Après Histoire ermite";

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
    choixEviter->m_GoToEffetId = GenPrologueArdennes::ID_EF_HISTOIRE_ERMITE;// fin de l'événement

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
                 "Vous partez explorer au hasard", GenPrologueArdennes::PRIO_AVENTURIER, "1");
    choixExplorer->m_GoToEffetId = GenPrologueArdennes::ID_EF_HOMME_SAUVAGE;

    Choix* choixManger = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "Parons au plus pressé : vous cherchez si il y a trace de fruits comestibles dans les environs ou d'animaux à chasser",
                GenPrologueArdennes::PRIO_TRAVAILLEUR, "1");
    choixManger->m_GoToEffetId = "ChercherAManger";

    Choix* choixReflechir = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "Vous restez où vous êtes et réfléchissez pour comprendre ce qui a bien pu vous arriver", URevolution::INTELLIGENCE, "1");
    choixReflechir->m_GoToEffetId = "ResterReflechir";

    Choix* choixMonterArbre = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "Vous montez en haut d'un arbre pour y dormir en attendant la fin de la nuit", URevolution::HABILETE, "1");
    choixMonterArbre->m_GoToEffetId = "MonterSurArbre";


    return eveil;
}

Effet* GenPrologueArdennes::GenererHistoireErmite()
{
    QString txtErmite = "Vous vous éloignez et, sans vraiment savoir pourquoi ni vers où, vous vous remettez à vous enfoncer dans la forêt. Après quelques minutes seulement vous appercevez un feu au loin. Il s'agit d'un feu maîtrisé, sans doute allumé par un voyageur. Vous croyiez vous être élancé au hasard dans la forêt mais vos pas vous menaient droit vers ce feu avant même que vous ne le voyiez. Est-ce le froid, la solitude ou autre chose ? Vous ne pouvez résister à l'appel du feu de camps et vous approchez, en prenant le minimum de précautions.\n"
                  "Il semble en effet ne pas y avoir de risques : la seule personne assise près du modeste feu de fois est un très vieil homme barbu et frêle. Il est habillé à la manière rustique d'un forestier mais ses habits sont si abimés qu'il ressemble plutôt à un vagabond ou à un ermite.\n"
                  "À votre approche il ne vous dit pas un mot et se contente de vous tendre ce qui semble être son unique repas : une belle pomme bien mûre.\n"
                  "Ne prêtant aucun attention à votre réaction et ne vous regardant même pas dans les yeux il se contente de dire gravement : \"Vous avez une chance rare étranger. Vous vous tenez en face de la mémoire vivante de la forêt des ardennes. J'habite ces bois depuis plus de 2000 ans et rares sont les humains qui me trouvent. Assurément une force vous a mené ici. J'ignore pourquoi car je ne suis vraiment d'aucune utilité à un aventurier. Je ne suis rien d'autre qu'une mémoire qui raconte des histoires. Peut-être est-ce qu'il vous faut pour passer cette froide nuit. Voudriez vous en entendre une ?\"";
    Effet* effet = m_GenerateurEvt->AjouterEffetNarration(txtErmite, "", GenPrologueArdennes::ID_EF_HISTOIRE_ERMITE);

    // les choix
    Choix* choixHistoireCharlemagne = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "Avez vous cotoyé Charlemagne ? On dit qu'il a souvent chassé dans ces bois avec son neveu Roland.", GenPrologueArdennes::PRIO_ARISTOCRATIE, "1");
    choixHistoireCharlemagne->m_GoToEffetId = "histoireCharlemagne";

    Choix* choixFilsAymon = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "Racontez moi l'histoire des fils Aymon poursuivis par Charlemagne et de leur cheval fée Bayard.", GenPrologueArdennes::PRIO_AVENTURIER, "1");
    choixFilsAymon->m_GoToEffetId = "choixFilsAymon";

    Choix* choixPasHistoire = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "Peu m'importe le passé seul compte le présente et le futur qui en sera issu. Si vous ne pouvez m'aider je préfère dormir jusqu'au matin.", GenPrologueArdennes::PRIO_REVOLUTION, "1");
    choixPasHistoire->m_GoToEffetId = "pasHistoire";

    Choix* choixSaintLaurent = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "Avez vous rencontré le pieu Saint Laurent ? On dit qu'il a été ermite dans cette forêt.", GenPrologueArdennes::PRIO_PRETRE, "1");
    choixSaintLaurent->m_GoToEffetId = "histoireSaintLaurent";

    Choix* choixFees = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "On dit que ce bois est plein de fées. En êtes vous un ?", GenPrologueArdennes::PRIO_MAGICIEN, "1");
    choixFees->m_GoToEffetId = "choixFees";

    Choix* choixHistoire = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "Vous préférez lui poser des questions sur l'histoire ancestrale de la forêt", GenPrologueArdennes::PRIO_ERUDIT, "1");
    choixHistoire->m_GoToEffetId = "choixHistoire";

    Choix* choixChanson = m_GenerateurEvt->AjouterChoixAjouteurACarac(
                 "Vous préférez passer la nuit à chanter et danser.", GenPrologueArdennes::PRIO_ARTISTE, "1");
    choixChanson->m_GoToEffetId = "choixChanson";

    // effet choixFilsAymon
    QString txtAymon = "Afin d'être fait chevalier, Les fils Aymon Allard, Guichard, Renaud et Richard(et) partent à la cour de l'empereur et le servent honorablement. Mais à la suite d'une discussion qui survient au cours d'une partie d'échecs, Renaud blesse mortellement Bertolai, le neveu de Charlemagne.\n"
            "Pour fuir la colère de l'empereur, Renaud est obligé de s'éloigner de la cour. Il se refugie d'abord chez son père qui le chasse de la forteresse de Dordone. Monté avec ses trois frères sur leur unique cheval Bayard, ils s'enfoncent dans la mystérieuse forêt d'Ardenne et sèment rapidement leurs poursuivants grâce aux pouvoirs magiques de Bayard qui est capable de franchir une vallée d'un seul saut. Là, avec l'aide de leur cousin, Maugis, enchanteur et un peu voleur, ils construisent la forteresse de Montessor sur un rocher surplombant la Meuse.\n"
            "Mais au bout de sept ans Charlemagne connaît leur retraite et il fait le siège du château avec une troupe importante. A cause de la traitrise d'Hervé de Lausanne, qui profite de l'hospitalité des fils Aymon pour en ouvrir la herse durant la nuit, le château est sur le point d'être pris les quatre frères s'enfuient du château et se réfugient une nouvelle fois dans les profondeurs de la forêt ardennaise. Tous quatre, Renault, Allard, Richard et Guichard(et), sur leur cheval magique Bayard, fuient sans cesse et franchissent la Meuse d'un bond immense.\n"
            "Fuyant vers le sud Ils se mettent au service du roi Yvon de Gascogne. Ils sont une aide précieuse lors des combats qui opposent les troupes du roi Yvon de celles de l’émir Beges. En remerciement le roi donne à Renault la main de sa soeur Aélis et des terres. Renaud va y faire construire un château qu'il nomme Montauban « parce qu'il est construit sur une montagne de marbre ». Mais Charlemagne les retrouve. Il leur tend un piège en les envoyant affronter, désarmés, plusieurs armées durant la bataille de Vaucouleurs.\n"
            "Roland et les douze pairs négocient la paix entre les différents protagonistes. Charlemagne accorde le pardon aux quatre frères et à leurs familles. La colère de Charlemagne ne s'apaisera qu'avec le sacrifice de Bayard, précipité dans la Meuse mais le cheval parvient toutefois à s'enfuir dans la forêt. Et par les nuits sans lune, le fougueux destrier revient parfois hanter la forêt d'Ardenne.\n"
            "D'autre part Renaud doit renoncer au métier des armes et faire un pèlerinage à Jérusalem. A son retour il participe à la construction de la cathédrale de Cologne. Les ouvriers jaloux l’assassinent, car Renaud travaille plus que quiconque sans demander de salaire autre qu'un peu de nourriture. ";
    Effet* histoireAymon = m_GenerateurEvt->AjouterEffetNarration(txtAymon, "", "choixFilsAymon");
    histoireAymon->m_GoToEffetId = GenPrologueArdennes::ID_EF_APRES_HISTOIRE_ERMITE;

    return effet;
}

void GenPrologueArdennes::GenererEvtsAccueil()
{
    this->AjouterEvt("Debut", "Génération du perso par les choix");
    //GenererEveil();
    //GenererHommeSauvage();
    GenererHistoireErmite();

}
