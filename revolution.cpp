#include "revolution.h"
#include "../destinLib/perso.h"
#include "ui_aventure.h"
#include "politique.h"
#include "mirabeau.h"

Revolution::Revolution(HistoireRevolution themeHistoire, QWidget *parent, QString premierEvt, QString premierEffet)
    : Aventure(parent), m_HistoireRevolution(themeHistoire)
{
    //
    switch (themeHistoire) {
    case HistoireRevolution::eh_Mirabeau : {
        m_Perso = new Politique(ui->persoWidget);
        m_Histoire = new Mirabeau(ui->histoireWidget);
        this->setWindowTitle("Vie de Mirabeau");

    }break;

    }

    // positionner l'interface
    ui->persoWidget->layout()->addWidget(m_Perso);
    //m_Perso->show();
    ui->histoireWidget->layout()->addWidget(m_Histoire);

    GenererAventure();

    if ( premierEvt != "" )
        m_Histoire->SetCurrentEvtId( premierEvt ) ;
    if ( premierEffet!= "" )
        m_Histoire->SetEffetIndex(m_Histoire->DeterminerIndexEffet(premierEffet) );

    m_EtatPartie = EP_Deroulement;
    LancerEvtEtOuEffetCourant();
}

Revolution::~Revolution()
{

}

void Revolution::GenererAventure()
{
    GenererCaracs();

    (static_cast<Politique*>(m_Perso))->GenererPersos();

    m_Histoire->GenererHistoire();

    m_Perso->RafraichirAffichage();
}

void Revolution::GenererCaracs()
{
    /*m_Perso->m_Caracs.append(new Carac(VieDunMekano::competence_armement, "Compétence en armes", "0",
                                       "",
                                       "", MODE_AFFICHAGE::ma_Nombre
                                       ));*/
}
