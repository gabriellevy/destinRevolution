#ifndef REVOLUTION_H
#define REVOLUTION_H

#include <QMainWindow>
#include "../destinLib/aventure.h"

enum HistoireRevolution {
    eh_Mirabeau
};

class Revolution : public Aventure
{
    Q_OBJECT
private:
    HistoireRevolution m_HistoireRevolution;

protected:
    // pour les aventures qui n'utilisent pas le json mais du code :surclasser aventure et développer cette fonction
    virtual void GenererAventure();
    // génère toutes les caracs qui peuvent être visualisées par le joueur (d'autres caracs peuvent être générées et invisibles n'importe quand dans l'aventure)
    virtual void GenererCaracs();

public:
    Revolution(HistoireRevolution themeHistoire, QWidget *parent = nullptr, QString premierEvt = "", QString premierEffet = "");
    ~Revolution();
};

#endif // REVOLUTION_H
