#include "heros.h"
#include "../destinLib/carac.h"
#include "../destinLib/gestionnairecarac.h"
#include "urevolution.h"
#include "genprologueardennes.h"

Heros::Heros(QString id, QString nom, QString description, QString CheminImagePortrait)
    :DPerso(id, nom, description, CheminImagePortrait)
{}

void Heros::InitialiserPerso()
{
    Carac* caracHABILETE = new Carac(URevolution::HABILETE,
                             URevolution::HABILETE,
                             "0",
                             "",
                             URevolution::HABILETE,
                             MODE_AFFICHAGE::ma_Nombre);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracHABILETE);
    m_CaracsAAfficher.push_back(URevolution::HABILETE);

    Carac* caracPUISSANCE = new Carac(URevolution::PUISSANCE,
                             URevolution::PUISSANCE,
                             "0",
                             "",
                             URevolution::PUISSANCE,
                             MODE_AFFICHAGE::ma_Nombre);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracPUISSANCE);
    m_CaracsAAfficher.push_back(URevolution::PUISSANCE);

    Carac* caracCHARISME = new Carac(URevolution::CHARISME,
                             URevolution::CHARISME,
                             "0",
                             "",
                             URevolution::CHARISME,
                             MODE_AFFICHAGE::ma_Nombre);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracCHARISME);
    m_CaracsAAfficher.push_back(URevolution::CHARISME);

    Carac* caracINTELLIGENCE = new Carac(URevolution::INTELLIGENCE,
                             URevolution::INTELLIGENCE,
                             "0",
                             "",
                             URevolution::INTELLIGENCE,
                             MODE_AFFICHAGE::ma_Nombre);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracINTELLIGENCE);
    m_CaracsAAfficher.push_back(URevolution::INTELLIGENCE);

    Carac* caracVolonte = new Carac(URevolution::VOLONTE,
                             URevolution::VOLONTE,
                             "0",
                             "",
                             URevolution::VOLONTE,
                             MODE_AFFICHAGE::ma_Nombre);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracVolonte);
    m_CaracsAAfficher.push_back(URevolution::VOLONTE);

    Carac* caracPerception = new Carac(URevolution::PERCEPTION,
                             URevolution::PERCEPTION,
                             "0",
                             "",
                             URevolution::PERCEPTION,
                             MODE_AFFICHAGE::ma_Nombre);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracPerception);
    m_CaracsAAfficher.push_back(URevolution::PERCEPTION);


    m_CaracsAAfficher.push_back(GenPrologueArdennes::ART);
    m_CaracsAAfficher.push_back(GenPrologueArdennes::RELIGION);
    m_CaracsAAfficher.push_back(GenPrologueArdennes::ORDRE);
    m_CaracsAAfficher.push_back(GenPrologueArdennes::FORCE);
    m_CaracsAAfficher.push_back(GenPrologueArdennes::NOBLESSE);
    m_CaracsAAfficher.push_back(GenPrologueArdennes::LUMIERE);
    m_CaracsAAfficher.push_back(GenPrologueArdennes::TRAVAIL);
    m_CaracsAAfficher.push_back(GenPrologueArdennes::INDIVIDUALISME);
    m_CaracsAAfficher.push_back(GenPrologueArdennes::SAVOIR);
    m_CaracsAAfficher.push_back(GenPrologueArdennes::FEERIE);
}

URevolution* Heros::GetURevolution()
{
    return static_cast<URevolution*>(Univers::ME);
}
