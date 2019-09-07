#include "genprologueardennes.h"
#include "../destinLib/gestionnairecarac.h"
#include "urevolution.h"
#include "../destinLib/aleatoire.h"
#include "../destinLib/perso.h"
#include "../destinLib/gestionnairecarac.h"
#include "../destinLib/execeffet.h"
#include "heros.h"

QString GenPrologueArdennes::PRIO_NOBLESSE = "Aristocratie";
QString GenPrologueArdennes::PRIO_LUMIERE = "Bourgeois";
QString GenPrologueArdennes::PRIO_FORCE = "Guerrier";
QString GenPrologueArdennes::PRIO_RELIGION = "Prêtre";
QString GenPrologueArdennes::PRIO_TRAVAIL = "Travailleur";
QString GenPrologueArdennes::PRIO_SAVOIR = "Érudit";
QString GenPrologueArdennes::PRIO_ART = "Artiste";
QString GenPrologueArdennes::PRIO_FEERIE = "Magicien";
QString GenPrologueArdennes::PRIO_LIBERTE = "Aventurier";
QString GenPrologueArdennes::PRIO_ORDRE = "Ordre";

GenPrologueArdennes::GenPrologueArdennes():GenHistoire () {}

Hist* GenPrologueArdennes::GenererHistoire()
{
    GenererPersos();

    //GenererFonctionsCallback();

    GenererCaracs();

    GenererEvtsAccueil();

    FinGenerationHistoire();

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
QString GenPrologueArdennes::ID_EF_OIE = "Oie";
QString GenPrologueArdennes::ID_EF_PERDU = "Perdu";
QString GenPrologueArdennes::ID_EF_AUBERON = "Aubéron";
QString GenPrologueArdennes::ID_EF_DOLMEN = "Dolmen";
QString GenPrologueArdennes::ID_EF_ARBRE_SACRE = "Arbre sacré";
QString GenPrologueArdennes::ID_EF_COCAGNE = "Cocagne";
QString GenPrologueArdennes::ID_EF_NUAGES = "Mer de nuages";

QString GenPrologueArdennes::ID_EF_PROCHAIN_EFFET = "id prochain effet";

Effet* GenPrologueArdennes::GenererHommeSauvage(QString idDebut, QString idFin)
{
    Effet* effet = AjouterEffetNarration("Vous vous approchez discrètement. Le bruit que vous faites est de toute façon couvert par les cris de femmes qui redoublent au fur et à mesure que vous vous approchez. Enfin, après avoir passé un buisson vous appercevez à quelques centaines de mètres un bien étrange spectacle. C'est bien une femme qui crie. Une grande paysanne rousse grassouillette, et elle se trouve sur l'épaule d'un très grand homme apparemment nu mais extraordinairement poilu. C'est un homme sauvage ! Et la femme qui se débat désespérément est sans doute une pauvre villageoise qu'il a enlevé pour assouvir la lubricité typique de sa race.",
                                                          ":/Images/Ardennes/HommeSauvage.jpg", idDebut);
    // les choix
    /*Choix* choixCombat = */AjouterChoixAjouteurACarac(
                 "Vous sortez votre arme et le chargez", GenPrologueArdennes::PRIO_FORCE, "1", "combatHommeSauvage");

    /*Choix* choixInterpeller = */AjouterChoixAjouteurACarac(
                 "Vous interpelez le sauvage", GenPrologueArdennes::PRIO_LUMIERE, "1", "discussionHommeSauvage"); // bof...

    /*Choix* choixEmbuscade = */AjouterChoixAjouteurACarac(
                 "Vous tentez de le doubler discrètement pour dépasser sa position et lui tendre une embuscade", URevolution::HABILETE, "1", "embuscadeHommeSauvage");

    /*Choix* choixEviter = */AjouterChoixAjouteurACarac(
                 "Vous préférez ne pas vous en mêler. Ce n'est pas à vous de régler les conflits entre sauvages et civilisés", GenPrologueArdennes::PRIO_LIBERTE, "1", idFin);

    // embuscade
    Effet* embuscade = AjouterEffetNarration("Vous parvenez à le doubler rapidement. Il a beau être très grand il est très ralenti par son fardeau. Vous vous postez dans un arbre et, comme prévu, il va passer dessous dans une dizaine de secondes.",
                                                              "", "embuscadeHommeSauvage");
    embuscade->AjouterChangeurDeCarac("embuscadeHommeSauvage", "1"); // donne un avantage en cas de bagarre

    /*Choix* choixEmbuscade1 = */AjouterChoixGoToEffet(
                 "Vous l'interpelez tout en le tenant en joue avec votre arc", "discussionHommeSauvage");

    // discussionHommeSauvage
    /*Effet* discussionHommeSauvage = */AjouterEffetNarration("Quand vous l'interpellez l'homme sauvage réagit mollement, sans inquiétude ni agressivité et vous regarde. La femme, dans sa position sur son épaule ne peut pas vous voir mais appelle à l'aide et crie qu'un monstre l'a enlevée à son village et veut la manger. Le sauvage gromelle qu'il a déjà mangé mais qu'il a besoin d'une femme pour être son épouse. La femme est scandalisée et lui hurle de la lâcher ce qu'il refuse de faire. Que lui dites vous ?",
                                                              "", "discussionHommeSauvage");

    /*Choix* discussionRelache = */AjouterChoixGoToEffet(
                 "Vous lui dites qu'il est interdit d'enlever les femmes ainsi et qu'il doit la relâcher", "discussionHommeSauvageRelache");


    /*Effet* discussionHommeSauvageRelache = */AjouterEffetNarration("L'homme sauvage répond que quand un homem est assez fort pour prendre une femme il est normal qu'il la garde. Mais, tout en grognant, il articule tout de même que par générosité si il peut copuler une fois avec la femme il la laissera partir. Il ajoute bruyamment avec un sourire que bien sûr si après ça elle décide de rester elle sera la bienvenue. La villageoise proteste mollement qu'elle est déjà mariée.",
                                                              "", "discussionHommeSauvageRelache");
    Choix* discussionAttaque = AjouterChoixGoToEffet(
                 "Assez discuté vous l'attaquez", "combatHommeSauvage");
    discussionAttaque->AjouterAjouteurACarac(GenPrologueArdennes::PRIO_FORCE, "1");

    return effet;
}

Effet* GenPrologueArdennes::GenererEveil(QString idDebut, QString idFin)
{
    Effet* eveil = AjouterEffetNarration("Vous vous éveillez en plein forêt des ardennes et en pleine nuit, l'esprit enbrumé mais le corps hardi. Malgré le danger de votre situation il vous semble que tout vous est possible aujourd'hui et que cette forêt sombre et menaçante est la vôtre. Que faites vous ?",
                                                          "", idDebut);

    // les choix
    Choix* choixExplorer = AjouterChoixAjouteurACarac(
                 "Vous partez explorer au hasard", GenPrologueArdennes::PRIO_LIBERTE, "1");
    choixExplorer->m_GoToEffetId = idFin;

    Choix* choixManger = AjouterChoixAjouteurACarac(
                 "Parons au plus pressé : vous cherchez si il y a trace de fruits comestibles dans les environs ou d'animaux à chasser",
                GenPrologueArdennes::PRIO_TRAVAIL, "1");
    choixManger->m_GoToEffetId = "ChercherAManger";

    Choix* choixReflechir = AjouterChoixAjouteurACarac(
                 "Vous restez où vous êtes et réfléchissez pour comprendre ce qui a bien pu vous arriver", URevolution::INTELLIGENCE, "1");
    choixReflechir->m_GoToEffetId = "ResterReflechir";

    Choix* choixMonterArbre = AjouterChoixAjouteurACarac(
                 "Vous montez en haut d'un arbre pour y dormir en attendant la fin de la nuit", URevolution::HABILETE, "1");
    choixMonterArbre->m_GoToEffetId = "MonterSurArbre";


    return eveil;
}

Effet* GenPrologueArdennes::GenererHistoireErmite(QString idDebut, QString idFin)
{
    QString txtErmite = "Vous vous éloignez et, sans vraiment savoir pourquoi ni vers où, vous vous remettez à vous enfoncer dans la forêt. Après quelques minutes seulement vous appercevez un feu au loin. Il s'agit d'un feu maîtrisé, sans doute allumé par un voyageur. Vous croyiez vous être élancé au hasard dans la forêt mais vos pas vous menaient droit vers ce feu avant même que vous ne le voyiez. Est-ce le froid, la solitude ou autre chose ? Vous ne pouvez résister à l'appel du feu de camps et vous approchez, en prenant le minimum de précautions.\n"
                  "Il semble en effet ne pas y avoir de risques : la seule personne assise près du modeste feu de fois est un très vieil homme barbu et frêle. Il est habillé à la manière rustique d'un forestier mais ses habits sont si abimés qu'il ressemble plutôt à un vagabond ou à un ermite.\n"
                  "À votre approche il ne vous dit pas un mot et se contente de vous tendre ce qui semble être son unique repas : une belle pomme bien mûre.\n"
                  "Ne prêtant aucun attention à votre réaction et ne vous regardant même pas dans les yeux il se contente de dire gravement : \"Vous avez une chance rare étranger. Vous vous tenez en face de la mémoire vivante de la forêt des ardennes. J'habite ces bois depuis plus de 2000 ans et rares sont les humains qui me trouvent. Assurément une force vous a mené ici. J'ignore pourquoi car je ne suis vraiment d'aucune utilité à un aventurier. Je ne suis rien d'autre qu'une mémoire qui raconte des histoires. Peut-être est-ce qu'il vous faut pour passer cette froide nuit. Voudriez vous en entendre une ?\"";
    Effet* effet = AjouterEffetNarration(txtErmite, "", idDebut);

    // les choix
    Choix* choixHistoireCharlemagne = AjouterChoixAjouteurACarac(
                 "Avez vous cotoyé Charlemagne ? On dit qu'il a souvent chassé dans ces bois avec son neveu Roland.", GenPrologueArdennes::PRIO_NOBLESSE, "1");
    choixHistoireCharlemagne->m_GoToEffetId = "histoireCharlemagne";

    Choix* choixFilsAymon = AjouterChoixAjouteurACarac(
                 "Racontez moi l'histoire des fils Aymon poursuivis par Charlemagne et de leur cheval fée Bayard.", GenPrologueArdennes::PRIO_LIBERTE, "1");
    choixFilsAymon->m_GoToEffetId = "choixFilsAymon";

    Choix* choixPasHistoire = AjouterChoixAjouteurACarac(
                 "Peu m'importe le passé seul compte le présent et le futur qui en sera issu. Si vous ne pouvez m'aider je préfère dormir jusqu'au matin.",
                GenPrologueArdennes::PRIO_LUMIERE, "1");
    choixPasHistoire->m_GoToEffetId = idFin;

    Choix* choixSaintLaurent = AjouterChoixAjouteurACarac(
                 "Avez vous rencontré le pieu Saint Hubert ? On dit qu'il a été ermite dans cette forêt.", GenPrologueArdennes::PRIO_RELIGION, "1");
    choixSaintLaurent->m_GoToEffetId = "histoireSaintLaurent";

    Choix* choixFees = AjouterChoixAjouteurACarac(
                 "On dit que ce bois est plein de fées. En êtes vous un ?", GenPrologueArdennes::PRIO_FEERIE, "1");
    choixFees->m_GoToEffetId = "choixFees";

    Choix* choixHistoire = AjouterChoixAjouteurACarac(
                 "J'ai de nombreuses questions à vous poser sur la faune et la flore de cette forêt", GenPrologueArdennes::PRIO_SAVOIR, "1");
    choixHistoire->m_GoToEffetId = "choixHistoire";

    Choix* choixChanson = AjouterChoixAjouteurACarac(
                 "Je préférerai danser et chanter jusqu'au matin.", GenPrologueArdennes::PRIO_ART, "1");
    choixChanson->m_GoToEffetId = "choixChanson";

    // effet choixFilsAymon
    AjouterEffetNarration("Afin d'être fait chevalier, Les fils Aymon Allard, Guichard, Renaud et Richard(et) partent à la cour de l'empereur et le servent honorablement. Mais à la suite d'une discussion qui survient au cours d'une partie d'échecs, Renaud blesse mortellement Bertolai, le neveu de Charlemagne.\n"
                                           , "", "choixFilsAymon");
    AjouterEffetNarration("Pour fuir la colère de l'empereur, Renaud est obligé de s'éloigner de la cour. Il se refugie d'abord chez son père qui le chasse de la forteresse de Dordone. Monté avec ses trois frères sur leur unique cheval Bayard, ils s'enfoncent dans la mystérieuse forêt d'Ardenne et sèment rapidement leurs poursuivants grâce aux pouvoirs magiques de Bayard qui est capable de franchir une vallée d'un seul saut. Là, avec l'aide de leur cousin, Maugis, enchanteur et un peu voleur, ils construisent la forteresse de Montessor sur un rocher surplombant la Meuse.\n",
                                           ":/Images/Ardennes/Bayard.jpg");
    AjouterEffetNarration("Mais au bout de sept ans Charlemagne connaît leur retraite et il fait le siège du château avec une troupe importante. A cause de la traitrise d'Hervé de Lausanne, qui profite de l'hospitalité des fils Aymon pour en ouvrir la herse durant la nuit, le château est sur le point d'être pris les quatre frères s'enfuient du château et se réfugient une nouvelle fois dans les profondeurs de la forêt ardennaise. Tous quatre, Renault, Allard, Richard et Guichard(et), sur leur cheval magique Bayard, fuient sans cesse et franchissent la Meuse d'un bond immense.\n");
    AjouterEffetNarration("Fuyant vers le sud Ils se mettent au service du roi Yvon de Gascogne. Ils sont une aide précieuse lors des combats qui opposent les troupes du roi Yvon de celles de l’émir Beges. En remerciement le roi donne à Renault la main de sa soeur Aélis et des terres. Renaud va y faire construire un château qu'il nomme Montauban « parce qu'il est construit sur une montagne de marbre ». Mais Charlemagne les retrouve. Il leur tend un piège en les envoyant affronter, désarmés, plusieurs armées durant la bataille de Vaucouleurs.\n");
    AjouterEffetNarration("Roland et les douze pairs négocient la paix entre les différents protagonistes. Charlemagne accorde le pardon aux quatre frères et à leurs familles. La colère de Charlemagne ne s'apaisera qu'avec le sacrifice de Bayard, précipité dans la Meuse mais le cheval parvient toutefois à s'enfuir dans la forêt. Et par les nuits sans lune, le fougueux destrier revient parfois hanter la forêt d'Ardenne.\n",
                                           "");
    Effet* histoireAymon = AjouterEffetNarration("D'autre part Renaud doit renoncer au métier des armes et faire un pèlerinage à Jérusalem. A son retour il participe à la construction de la cathédrale de Cologne. Les ouvriers jaloux l’assassinent, car Renaud travaille plus que quiconque sans demander de salaire autre qu'un peu de nourriture. ",
                                                                  "", "choixFilsAymon");
    histoireAymon->m_GoToEffetId = idFin;

    // effet Saint Hubert
    AjouterEffetNarration("Depuis le XVe siècle on dit que le seigneur Hubert était si passionné de chasse qu'il en oubliait ses devoirs. La légende rapporte qu'il n'avait pu résister à sa passion un Vendredi saint, et n'ayant trouvé personne pour l'accompagner, était parti chasser sans aucune compagnie. À cette occasion, il se trouva face à un cerf extraordinaire7. En effet, celui-ci était blanc et portait une croix lumineuse au milieu de ses bois."
                                           , "", "histoireSaintLaurent");
    AjouterEffetNarration("Hubert se mit à pourchasser le cerf mais celui-ci parvenait toujours à le distancer sans pour autant se fatiguer. Ce n’est qu’au bout d’un long moment que l'animal s’arrêta et qu’une voix tonna dans le ciel en s’adressant à Hubert en ces termes :\n\" Hubert ! Hubert ! Jusqu'à quand poursuivras-tu les bêtes dans les forêts ? Jusqu'à quand cette vaine passion te fera-t-elle oublier le salut de ton âme ? \". Hubert, saisi d'effroi, se jeta à terre et humblement, il interrogea la vision :\n \n Seigneur ! Que faut-il que je fasse ? \"");
    AjouterEffetNarration("La voix reprit :\n\" Va donc auprès de Lambert, mon évêque, à Maastricht. Convertis-toi. Fais pénitence de tes péchés, ainsi qu'il te sera enseigné. Voilà ce à quoi tu dois te résoudre pour n'être point damné dans l'éternité. Je te fais confiance, afin que mon Église, en ces régions sauvages, soit par toi grandement fortifiée. \"");
    Effet* effetFinHubert = AjouterEffetNarration("Et Hubert de répondre, avec force et enthousiasme :\n« Merci, ô Seigneur. Vous avez ma promesse.\nJe ferai pénitence, puisque vous le voulez.\nJe saurai en toutes choses me montrer digne de vous ! »", ":/Images/Ardennes/SaintHubert.jpg");
    effetFinHubert->m_GoToEffetId = idFin;

    return effet;
}

Effet* GenPrologueArdennes::GenererOieSauvage(QString idDebut, QString idFin)
{
    Effet* effet = AjouterEffetNarration("Vous reprenez votre exploration au petit mâtin. Vous approchez d'une claière où vous espérez avoir une meilleure vue des environ quand, au bord d'un étang,"
                                                          "vous appercevez une oie bernache qui semble blessée. En vous approchant et en la voyant boiter il vous paraît clair qu'elle est gravement blessée.",
                                                          ":/Images/Ardennes/bernache.du.canada.auau.3g.jpg", idDebut);

    /*Choix* choix1 = */AjouterChoixGoToEffet(
                 "Justement vous avez grand faim. Vous la tuez immédiatement.", "mangerOie");

    Choix* choixEspritAnimal = AjouterChoixAjouteurACarac(
                 "Vous invoquez son esprit animal et priez pour elle.", GenPrologueArdennes::PRIO_RELIGION, "1");
    choixEspritAnimal->m_GoToEffetId = "espritAnimal";

    Choix* choixParler = AjouterChoixAjouteurACarac(
                 "Vous tentez de lui parler.", GenPrologueArdennes::PRIO_FEERIE, "1");
    choixParler->m_GoToEffetId = "parlerOie";

    // "espritAnimal"
    /*Effet* espritAnimal = */AjouterEffetNarration("Après un recours recueillement il vous semble sentir que l'oie souffre énormément.",
                                                                 "", "espritAnimal");

    AjouterChoixGoToEffet("Vous la tuez le plus rapidement et humainement possible.",
                                           "tuerOieGentiment");
    AjouterChoixGoToEffet("Vous la tuez le plus rapidement et humainement possible, puis la mangez",
                                           "mangerOie");
    AjouterChoixGoToEffet("Vous la soignez autant que possible puis vous partez", "soignerOie");

    // "mangerOie"
    /*Effet* mangerOie = */AjouterEffetNarration("Vous tuez facielement l'oie qui semblait à peine capable de marcher.",
                                                              "", "mangerOie");
    AjouterChoixGoToEffet("Vous essayez de faire un bon feu pour la cuire.", "cuireOie");
    AjouterChoixAjouteurACarac("Vous être un cuisiner expert. Trouver les herbes dans les environs et faire un feu va être un jeu d'enfant.",
                                                GenPrologueArdennes::PRIO_TRAVAIL, "1", "cuireOie");
    AjouterChoixAjouteurACarac("Vous la mangez crue", URevolution::VOLONTE, "1", "mangerOieCrue");

    // "parlerOie"
    Effet* effetParlerOie =  AjouterEffetNarration("Elle ne répond rien. C'est une oie.", "", "parlerOie");
    effetParlerOie->m_GoToEffetId = GenPrologueArdennes::ID_EF_OIE;

    // "cuireOie"
    /*Effet* efMangerOie = */AjouterEffetNarration("C'était un délice, surtout après une si longue errance en forêt. Une oie est cependant beaucoup trop de nourriture pour une personne seule.",
                                                                "", "cuireOie");
    AjouterChoixAjouteurACarac("Pas pour vous. Vous mangerJusqu'à finir l'oie toute entière !",
                                                URevolution::PUISSANCE, "1", idFin);
    AjouterChoixAjouteurACarac("Vous stockez aussi proprement que possible la viande qui vous reste dans votre sac à dos.",
                                                GenPrologueArdennes::PRIO_ORDRE, "1", idFin);
    AjouterChoixGoToEffet("Vous repartez l'estomac bien rempli et le coeur léger.",
                                                idFin);

    return effet;
}

Effet* GenPrologueArdennes::GenererPerdu(QString idDebut, QString idFin)
{

    Effet* effet = AjouterEffetNarration("Après des heures à errer dans la forêt force vous est de reconnaître que non seulement vous ne parvenez pas à vous repérer mais vous ne parvenez même pas à appercevoir le ciel tant la forêt est dense. Et l'aube tarde. Vous avez pourtant le sentiment d'avoir marché tout une nuit. Le désespoir vous gagne.",
                                                          "", idDebut);

    Choix* choixArduinna = AjouterChoixAjouteurACarac(
                 "Vous priez Arduinna la divinité du monde sauvage et de la forêt des ardennes.", GenPrologueArdennes::PRIO_RELIGION, "1");
    choixArduinna->AjouterAjouteurACarac(GenPrologueArdennes::PRIO_FEERIE, "1");
    choixArduinna->m_GoToEffetId = "prieresEntendues";

    Choix* choixHubert = AjouterChoixAjouteurACarac(
                 "Vous priez Saint Hubert, saint patron de la forêt et de la chasse.", GenPrologueArdennes::PRIO_RELIGION, "1");
    choixHubert->m_GoToEffetId = "prieresEntendues";

    Choix* choixErrer = AjouterChoixAjouteurACarac(
                 "Vous continuez à errer infatigablement.", URevolution::PUISSANCE, "1");
    choixErrer->m_GoToEffetId = idFin;

    Choix* choixSavoir = AjouterChoixAjouteurACarac(
                "Vous réfléchissez profondément à vos études et vos connaissances. Peut-être que vos connaissance en biologie, géologie et astronomie pourront vous sortir d'ici.",
                PRIO_SAVOIR, "1");
    choixSavoir->m_GoToEffetId = "reflexion";

    /*Choix* choixRager = */AjouterChoixAjouteurACarac(
                "Vous ragez contre le chaos de la forêt. Cela ne serait pas arrivé dans un endroit civilisé.",
                PRIO_ORDRE, "1");
    choixSavoir->m_GoToEffetId = idFin;

    Choix* choixEcouter = AjouterChoixAjouteurACarac(
                "Vous faites une pause pour vous concentrer sur votre en vironnement. Tout écouter, tout regarder, tout percevoir.",
                URevolution::PERCEPTION, "1");
    choixEcouter->m_GoToEffetId = idFin;

    Choix* choixChanter = AjouterChoixAjouteurACarac(
                "Vous sifflez une chanson pour vous donner du courage.",
                PRIO_ART, "1");
    choixChanter->m_GoToEffetId = idFin;


    return effet;
}

Effet* GenPrologueArdennes::GenererAuberon(QString idDebut, QString idFin)
{
    Effet* effet = AjouterEffetNarration("Au détour d'un petit sentier vous croisez un grotesque nain contrefait et bossu. "
           "Il marche en plein milieu du sentier et vous repousse ostensiblement sur le côté en criant de lui laisser la place à lui qui est Aubéron, le seigneur fée de la forêt des ardennes.",
           "", idDebut);

    Choix* choixImposteur = AjouterChoixAjouteurACarac(
                 "Vous le traitez d'imposteur. Il n'y a pas de fées.", GenPrologueArdennes::PRIO_LUMIERE, "1");
    choixImposteur->m_GoToEffetId = "imposteur";

    Choix* choixDuel = AjouterChoixAjouteurACarac(
                 "Vous le défiez de prouver qui il est en vous affrontant dans une épreuve.",
                GenPrologueArdennes::PRIO_NOBLESSE, "1");
    choixDuel->m_GoToEffetId = "duel";

    Choix* choixFeerie = AjouterChoixAjouteurACarac(
                 "Vous le croyez sur parole et le laissez passer respectueusement.",
                GenPrologueArdennes::PRIO_FEERIE, "1");
    choixFeerie->m_GoToEffetId = idFin;

    Choix* choixFlatterie = AjouterChoixAjouteurACarac(
                 "Vous le charmer par un clin d'oeil complice et une flatterie recherchée.",
                URevolution::CHARISME, "1");
    choixFlatterie->m_GoToEffetId = "choixFlatterie";

    Choix* choixFonce = AjouterChoixAjouteurACarac(
                 "Vous foncez droit sur lui sans vous arrêter.",
                URevolution::VOLONTE, "1");
    choixFonce->m_GoToEffetId = "choixFonce";

    /*Choix* choixRien =*/ AjouterChoixGoToEffet(
                 "Vous le laissez passer pour ne pas créer d'histoire.", idFin);

    return effet;
}

Effet* GenPrologueArdennes::GenererArbreSacre(QString idDebut, QString idFin)
{
    Effet* effet = AjouterEffetNarration("En suivant la meuse vous finissez par arriver à un endroit où les arbres sont beaucoup moins nombreux et où se trouvent quelques champs. Quelques habitations se trouvent à quelques centaines de mètres. Mais ue fois que vous les avez atteintes c'est pour constater qu'un paysan s'y dispute violemment avec son voisin. Le paysan énervé vous explique que son voisin s'apprête à abattre un très vieil arbre. Très contrarié il vous explique qu'il s'agit d'un arbre sacré et que les esprits des forêts cesseraient de favoriser sa récolte si on le coupait. Il se pourrait même qu'ils veuillent se venger. L'autre paysan trouve cette histoire ridicule et explique que cet arbre est de toute façon si vieux que des branches en tombent régulièrement ce qui est dangereux.",
           "", idDebut);

    Choix* choixCouper = AjouterChoixAjouteurACarac(
                 "Couper cet arbre sera le moyen de montrer que ces histoires de fées sont grotesques.", GenPrologueArdennes::PRIO_LUMIERE, "1");
    choixCouper->m_GoToEffetId = idFin;

    Choix* choixOrdre = AjouterChoixAjouteurACarac(
                 "Vous cherchez à savoir à qui appartient le terrain. C'est lui qui doit décider.", GenPrologueArdennes::PRIO_ORDRE, "1");
    choixOrdre->m_GoToEffetId = idFin;

    Choix* choixFeerie = AjouterChoixAjouteurACarac(
                 "Vous protégez l'arbre sacré.", GenPrologueArdennes::PRIO_FEERIE, "1");
    choixFeerie->m_GoToEffetId = idFin;

    Choix* choixReligion = AjouterChoixAjouteurACarac(
                 "Vous insistez non seulement pour que l'arbre soit coupé mais aussi brûlé et remplacé par une croix.", GenPrologueArdennes::PRIO_RELIGION, "1");
    choixReligion->m_GoToEffetId = idFin;

    Choix* choixTailler = AjouterChoixAjouteurACarac(
                 "Vous proposez de tailler le vieil arbre pour qu'il reste majestueux mais sans branche abimée.", GenPrologueArdennes::PRIO_TRAVAIL, "1");
    choixTailler->m_GoToEffetId = idFin;


    return effet;
}

Effet* GenPrologueArdennes::GenererDolmen(QString idDebut, QString idFin)
{
    Effet* effet = AjouterEffetNarration("Soudain vous entendez un violent coup de tonnerre. Trente secondes plus tard il pleut à verse. Heureusement vous appercevez non loin de là une petite clairière où se trouve un étrange empilemenet de pierres où vous devriez pouvoir vous abriter.",
           "", idDebut);

    Choix* choixRien = AjouterChoixAjouteurACarac(
                 "Vous vous réfugiez vite dessous avant que toutes vos affaires soient trempées et inutilisable.", GenPrologueArdennes::PRIO_LUMIERE, "1");
    choixRien->m_GoToEffetId = idFin;

    Choix* choixPeur = AjouterChoixAjouteurACarac(
                 "C'est un dolmen féérique. Hors de question de prendre le risque de les courroucer.", GenPrologueArdennes::PRIO_FEERIE, "1");
    choixPeur->m_GoToEffetId = idFin;

    Choix* choixPriere = AjouterChoixAjouteurACarac(
                 "Ces endroits païnens sont certes dangereux mais votre coeur pur ainsi qu'une humble prière vous protègeront.", GenPrologueArdennes::PRIO_NOBLESSE, "1");
    choixPriere->m_GoToEffetId = idFin;

    Choix* choixAmi = AjouterChoixAjouteurACarac(
                 "Féées ou pas, vous ne doutez pas qu'elles sauront apprécier votre présence charmante.", URevolution::CHARISME, "1");
    choixAmi->m_GoToEffetId = idFin;

    Choix* choixErudit = AjouterChoixAjouteurACarac(
                 "Formidable c'est l'occasion d'obeserver des structures païennes anciennes tout en s'abritant.", GenPrologueArdennes::PRIO_SAVOIR, "1");
    choixErudit->m_GoToEffetId = idFin;

    return effet;
}

Effet* GenPrologueArdennes::GenererCocagne(QString idDebut, QString idFin)
{
    Effet* effet = AjouterEffetNarration("Vous débouchez dans une vaste clairière. Alors qu'il y a deux pas vous étiez trempé par une pluie assourdissante vous êtes maintenant au sec bercé par une douce musique. Alors que vous étiez seul et entouré de bêtes sauvages voilà que vous êtes environné de jeunes gens beaux et joyeux. Le vin jaillit des fontaines.",
           "", idDebut);

    AjouterChoixAjouteurACarac(
                 "Cela ne se peut. La faim et la soif on du vous faire délirer.",
                GenPrologueArdennes::PRIO_LUMIERE, "1", idFin);

    Choix* choixAbstinence = AjouterChoixAjouteurACarac(
                 "Quel pays de débauchés molassons. Vous prenez juste de quoi vous restaurer puis reprenez votre route.",
                GenPrologueArdennes::PRIO_ORDRE, "1", idFin);
    choixAbstinence->AjouterAjouteurACarac(URevolution::VOLONTE, "1");

    AjouterChoixAjouteurACarac(
                 "Les jeunes gens n'ont pas l'air farouche. Après vous être bien restauré vous cherchez quelqu'un avec qui batifoler.",
                GenPrologueArdennes::PRIO_LIBERTE, "1", idFin);

    AjouterChoixGoToEffet(
                 "Le pays de cocagne ! Vous vous jetez sur vos mets préférés en vous chauffant au soleil de ce pays enchanteur.", idFin);

    return effet;
}

Effet* GenPrologueArdennes::GenererNuages(QString idDebut, QString idFin)
{
    Effet* effet = AjouterEffetNarration("Après une âpre escalade d'un mont du haut duquel vous pourrez mieux évaluer votre situation vous vous retrouvez au dessus d'une mer de nuages. Quels sont vos sentiments à ce spectacle grandiose ?",
           ":/Images/Ardennes/Mer de nuages.jpg", idDebut);

    AjouterChoixAjouteurACarac(
                 "Un sentiment de puissance vous submerge. Vous avez vaincu la montagne. En observant les alentours vous vaincrez la forêt.",
                URevolution::PUISSANCE, "1", idFin);
    AjouterChoixAjouteurACarac(
                 "Gloire à Dieu qui seul à pu créer une telle beauté.",
                GenPrologueArdennes::PRIO_RELIGION, "1", idFin);
    AjouterChoixAjouteurACarac(
                 "Et ainsi la supériorité de l'homme dompte la nature.",
                GenPrologueArdennes::PRIO_LUMIERE, "1", idFin);
    AjouterChoixAjouteurACarac(
                 "Vous êtes ébahi par la beauté. Vous aimeriez avoir le temps et les moyens de la rendre immortelle par un tableau ou un poème.",
                GenPrologueArdennes::PRIO_ART, "1", idFin);

    return effet;
}

void GenPrologueArdennes::GenererEvtsAccueil()
{
    this->AjouterEvt("Debut", "Génération du perso par les choix");
    GenererEveil(           ID_EF_ACCUEIL,          ID_EF_HOMME_SAUVAGE);
    GenererHommeSauvage     (ID_EF_HOMME_SAUVAGE,   ID_EF_PERDU);
    GenererPerdu            (ID_EF_PERDU,           ID_EF_HISTOIRE_ERMITE);
    // 1ère nuit à l'abri
    GenererHistoireErmite   (ID_EF_HISTOIRE_ERMITE, ID_EF_OIE);
    // très faim
    GenererOieSauvage       (ID_EF_OIE,             ID_EF_AUBERON);
    GenererAuberon          (ID_EF_AUBERON,         ID_EF_DOLMEN);
    // il pleut
    GenererDolmen          (ID_EF_DOLMEN,         ID_EF_COCAGNE);
    GenererCocagne          (ID_EF_COCAGNE,         ID_EF_NUAGES);
    // repérage montagne
    GenererNuages          (ID_EF_NUAGES,         ID_EF_ARBRE_SACRE);
    // clairière habitations
    GenererArbreSacre      (ID_EF_ARBRE_SACRE,         ID_EF_PROCHAIN_EFFET);

}
