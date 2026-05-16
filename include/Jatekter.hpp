#ifndef JATEKTER_HPP
#define JATEKTER_HPP

#include <../widgets.hpp>


class Jatekter : public Widget
{
public:
    Jatekter(Application*,int,int,int,int);
    virtual ~Jatekter();
    void rajzol()const override;
    void handle(event ev)override;
protected:
    int szdb,mdb,kockaszm=30;

};

#endif // JATEKTER_HPP
