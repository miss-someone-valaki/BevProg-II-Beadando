#include "Gomb.hpp"

using namespace std;
using namespace genv;

Gomb::Gomb(Application*_parent,int x_,int y_,int sx_,int sy_,string szoveg_):
    Widget(_parent,x_,y_,sx_,sy_),szoveg(szoveg_)
{
}

Gomb::~Gomb()
{}

void Gomb::rajzol() const
{
    if(rakattintottam)
    gout<<color(150,150,150)<<move_to(x,y)<<box(sz,m)<<move_to(x+5,y+15)<<color(0,0,0)<<text(szoveg);
    else{gout<<color(200,200,200)<<move_to(x,y)<<box(sz,m)<<move_to(x+5,y+15)<<color(0,0,0)<<text(szoveg);}
}

void Gomb::handle(event ev)
{
    if(ev.type==ev_mouse&&ev.button==btn_left){
        rakattintottam=true;
        parent->action(szoveg);
    }
    if(ev.type==ev_mouse&&ev.button==-btn_left)rakattintottam=false;
    //if(rakattintottam){parent->action(szoveg);}
}
