#ifndef SZAMBEALLITO_HPP
#define SZAMBEALLITO_HPP

#include "widgets.hpp"


class szambeallito : public Widget{
protected:
    int maxi,mini;
public:
    //szambeallito(int, int);
    szambeallito(Application *,int,int,int ,int,int,int);
    bool folotte_fel(int,int);
    bool folotte_le(int ,int);
    void rajzol()const override;
    void handle(event)override;

};

#endif // SZAMBEALLITO_HPP
