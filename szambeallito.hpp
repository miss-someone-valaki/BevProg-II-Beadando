#ifndef SZAMBEALLITO_HPP
#define SZAMBEALLITO_HPP

#include "widgets.hpp"


class szambeallito : public Widget{
protected:
    int maxi,mini;
    //int szam=0;
public:
    //szambeallito(int, int);
    szambeallito(Application *,int,int,int ,int,int,int);
    bool folotte_fel(int,int);
    bool folotte_le(int ,int);
    void rajzol()const override;
    void handle(event)override;
    int get_szam();
};

#endif // SZAMBEALLITO_HPP
