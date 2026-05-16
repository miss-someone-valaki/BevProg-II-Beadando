#ifndef GOMB_HPP
#define GOMB_HPP

#include <../widgets.hpp>

using namespace std;
using namespace genv;

class Gomb : public Widget
{
public:
    Gomb(Application*,int,int,int,int,string);
    virtual ~Gomb();
    void rajzol()const override;
    void handle(event ev)override;
private:
    string szoveg;
    bool rakattintottam=false;
};

#endif // GOMB_HPP
