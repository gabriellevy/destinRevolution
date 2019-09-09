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

    Carac* caracPUISSANCE = new Carac(URevolution::PUISSANCE,
                             URevolution::PUISSANCE,
                             "0",
                             "",
                             URevolution::PUISSANCE,
                             MODE_AFFICHAGE::ma_Nombre);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracPUISSANCE);

    Carac* caracCHARISME = new Carac(URevolution::CHARISME,
                             URevolution::CHARISME,
                             "0",
                             "",
                             URevolution::CHARISME,
                             MODE_AFFICHAGE::ma_Nombre);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracCHARISME);

    Carac* caracINTELLIGENCE = new Carac(URevolution::INTELLIGENCE,
                             URevolution::INTELLIGENCE,
                             "0",
                             "",
                             URevolution::INTELLIGENCE,
                             MODE_AFFICHAGE::ma_Nombre);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracINTELLIGENCE);

    Carac* caracVolonte = new Carac(URevolution::VOLONTE,
                             URevolution::VOLONTE,
                             "0",
                             "",
                             URevolution::VOLONTE,
                             MODE_AFFICHAGE::ma_Nombre);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracVolonte);

    Carac* caracPerception = new Carac(URevolution::PERCEPTION,
                             URevolution::PERCEPTION,
                             "0",
                             "",
                             URevolution::PERCEPTION,
                             MODE_AFFICHAGE::ma_Nombre);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracPerception);

    // temporaire :
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCaracNombre(GenPrologueArdennes::ART);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCaracNombre(GenPrologueArdennes::RELIGION);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCaracNombre(GenPrologueArdennes::ORDRE);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCaracNombre(GenPrologueArdennes::FORCE);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCaracNombre(GenPrologueArdennes::NOBLESSE);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCaracNombre(GenPrologueArdennes::LUMIERE);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCaracNombre(GenPrologueArdennes::TRAVAIL);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCaracNombre(GenPrologueArdennes::INDIVIDUALISME);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCaracNombre(GenPrologueArdennes::SAVOIR);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCaracNombre(GenPrologueArdennes::FEERIE);
}

URevolution* Heros::GetURevolution()
{
    return static_cast<URevolution*>(Univers::ME);
}
