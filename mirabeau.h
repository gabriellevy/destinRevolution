#ifndef MIRABEAU_H
#define MIRABEAU_H

#include "../destinLib/histoire.h"

class Mirabeau : public Histoire
{
    Q_OBJECT
public:
    explicit Mirabeau(QWidget *parent = nullptr);

    virtual void GenererHistoire();

    // callbacks spécifiques :
    //static void TempPasse(QString nbJoursStr);
    //static QString competence_armement;

private:
    //void GenererEvtsAccueil();

signals:

public slots:
};

#endif // MIRABEAU_H
