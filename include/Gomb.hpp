#ifndef GOMB_HPP
#define GOMB_HPP

#include <../widgets.hpp>
#include <functional>

using namespace std;
using namespace genv;

class Gomb : public Widget
{
public:
    Gomb(Application*,int,int,int,int,string,function<void()>,int);
    void rajzol()const override;
    void handle(event ev)override;
private:
    string szoveg;
    bool rakattintottam=false;
    function<void()>f;
    int betumeret=12;
};

#endif // GOMB_HPP
