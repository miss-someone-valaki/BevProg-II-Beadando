#include "Gomb.hpp"

using namespace std;
using namespace genv;

Gomb::Gomb(Application*_parent,int x_,int y_,int sx_,int sy_,string szoveg_,function<void()>f_,int betum):
    Widget(_parent,x_,y_,sx_,sy_),szoveg(szoveg_),f(f_),betumeret(betum)
{}

void Gomb::rajzol() const
{
    gout.load_font("LiberationSans-Regular.ttf", betumeret);
    if(rakattintottam)
    gout<<color(150,150,150)<<move_to(x,y)<<box(sz,m)<<move_to(x+5,y+15)<<color(0,0,0)<<text(szoveg);
    else{gout<<color(200,200,200)<<move_to(x,y)<<box(sz,m)<<move_to(x+(sz-gout.twidth(szoveg))/2,y+(m-gout.cascent())/2)<<color(0,0,0)<<text(szoveg);}
}

void Gomb::handle(event ev)
{
    if(ev.type==ev_mouse&&ev.button==btn_left){
        rakattintottam=true;
        f();
    }
    if(ev.type==ev_mouse&&ev.button==-btn_left)rakattintottam=false;
}
