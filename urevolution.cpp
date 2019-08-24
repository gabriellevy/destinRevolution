#include "urevolution.h"
#include "ui_univers.h"
#include "genprologueardennes.h"

URevolution::URevolution(ModeAffichage modeAffichage,
                         QWidget *parent)
    : Univers(parent, modeAffichage)
{
    this->AppliquerTheme(QColor(240, 214, 113));
}

Hist* URevolution::ExecuterGenerateurHistoire()
{
    // structure typoqie à copier dans votre fonction surclassée ExecuterGenerateurHistoire :
    m_Histoire = new Hist("titre inconu : vous devriez surclasser 'ExecuterGenerateurHistoire'");
    m_GenHistoire = new GenPrologueArdennes(m_Histoire);
    m_GenHistoire->GenererHistoire();
    return m_Histoire;
}
