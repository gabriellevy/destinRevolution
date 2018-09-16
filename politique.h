#ifndef POLITIQUE_H
#define POLITIQUE_H

#include "../destinLib/perso.h"

class Politique : public IPerso
{
    Q_OBJECT
public:
    explicit Politique(QWidget *parent = nullptr);

    virtual void GenererPersos();

signals:

public slots:
};

#endif // POLITIQUE_H
