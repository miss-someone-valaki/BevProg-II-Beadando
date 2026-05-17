#include "StaticText.hpp"
#include <vector>

using namespace genv;
using namespace std;

StaticText::StaticText(Application *_parent,int _x,int _y,int sx,int sy,string t,int betum):
    Widget(_parent,_x,_y,sx,sy),_text(t),betumeret(betum)
{}

void StaticText::rajzol() const
{

    gout.load_font("LiberationSans-Regular.ttf", betumeret);
    gout<<move_to(x,y)<<color(0,0,0)<<box(sz,m);
    gout<<move_to(x+(sz-gout.twidth(_text))/2,y+(m-gout.cascent()+gout.cdescent())/2)<<color(255,255,255)<<text(_text);
}

void StaticText::handle(event ev)
{
}

void StaticText::set_text(string uj)
{
    _text=uj;
}
