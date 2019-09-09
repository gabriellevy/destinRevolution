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
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCaracNombre(URevolution::HABILETE);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCaracNombre(URevolution::PUISSANCE);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCaracNombre(URevolution::CHARISME);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCaracNombre(URevolution::INTELLIGENCE);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCaracNombre(URevolution::VOLONTE);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCaracNombre(URevolution::PERCEPTION);

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
