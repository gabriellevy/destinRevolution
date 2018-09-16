#include "politique.h"
#include "mirabeau.h"

Politique::Politique(QWidget *parent) :
    IPerso(parent)
{

}
void Politique::GenererPersos()
{
    DPerso politique;
    politique.m_Id = "Politique";
    politique.m_Nom = "Politique";
    /*politique.m_ImagePortrait.load(":/mekano.jpg");
    politique.m_CaracsAAfficher.append("competence_armement");*/
    m_Persos.push_back(politique);
}
