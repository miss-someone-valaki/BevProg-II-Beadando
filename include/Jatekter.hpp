#ifndef JATEKTER_HPP
#define JATEKTER_HPP

#include <../widgets.hpp>
#include "Jatekmester.hpp"
#include <functional>

class Jatekmester;

class Jatekter : public Widget
{
public:
    Jatekter(Application*,int,int,int,int,int,function<void(int,int)>,Jatekmester*);
    void rajzol()const override;
    void handle(event ev)override;
    int melyik_negyzet_folott_x(int);
    int melyik_negyzet_folott_y(int);
protected:
    function<void(int,int)>f;
    int szdb,mdb,kockaszm=30;
    Jatekmester *jm;
};

#endif // JATEKTER_HPP
