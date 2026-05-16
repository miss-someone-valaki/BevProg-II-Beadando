#ifndef ALAKZAT_HPP
#define ALAKZAT_HPP

#include <../widgets.hpp>

using namespace genv;

class Alakzat : public Widget
{
public:
    Alakzat(Application*,int,int,int,int);
    virtual ~Alakzat();
    void rajzol()const override;
    void handle(event ev)override;
protected:
    bool melyik_jatekos=false;
};

#endif // ALAKZAT_HPP
