#include "urevolution.h"
#include "ui_univers.h"
#include "genprologueardennes.h"

QString URevolution::PERCEPTION = "Perception";
QString URevolution::HABILETE = "Habileté";
QString URevolution::PUISSANCE = "Puissance";
QString URevolution::CHARISME = "Charisme";
QString URevolution::INTELLIGENCE = "Intelligence";
QString URevolution::VOLONTE = "Volonté";

QString URevolution::HIST_PROLOGUE_REVOLUTION = "Prologue des ardennes";

URevolution::URevolution(ModeAffichage modeAffichage,
                         QWidget *parent)
    : Univers(parent, modeAffichage)
{
    this->AppliquerTheme(QColor(240, 214, 113));

    m_GensHistoire[URevolution::HIST_PROLOGUE_REVOLUTION] = new GenPrologueArdennes();
}
