#include "widgets.hpp"
#include "graphics.hpp"
#include "Application.hpp"

using namespace genv;

Widget::Widget(Application *_parent,int _x, int _y, int _sx, int _sy) : x(_x), y(_y), sz(_sx), m(_sy),parent(_parent)
{
    if(parent)parent->register_widget(this);
}

Widget::~Widget(){}

/*Widget::Widget(int x_, int y_, int sz_,int m_) : x(x_),y(y_),sz(sz_),m(m_)
{
    //_parent->register_widget(this);
}*/

bool Widget::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>x && mouse_x<x+sz && mouse_y>y && mouse_y<y+m;
}

/*Widget::Widget()
{
}

Widget::Widget(int x_,int y_):
    x(x_),y(y_)
{
}

Widget::Widget(int x_,int y_,int sz_):
    x(x_),y(y_),sz(sz_)
{
}*/

/*bool Widget::rajta(int mx,int my)
{
    if(mx>=x && mx<=x+sz && my>=y && my<=y+m)return true;
    else return false;
}*/

/*void Widget::handle(event ev)
{
    if(ev.type==ev_mouse && ev.button==btn_left){
        if(is_selected(ev.pos_x,ev.pos_y))rajtavan=true;
    }
    if(ev.type==ev_mouse && ev.button==btn_left && !is_selected(ev.pos_x,ev.pos_y))rajtavan=false;
}*/

/*void Widget::rajzol(int m,int sz)
{
    if(rajtavan){
        gout<<move_to(x-1,y-1)<<color(255,0,0)
        <<line(-1,m+2)<<line(sz+2,0)<<line(0,-m-2)<<line(-sz-2,0);
    }
    else{gout<<move_to(x-1,y-1)<<color(0,0,0)
        <<line(-1,m+2)<<line(sz+2,0)<<line(0,-m-2)<<line(-sz-2,0);}
}*/

/*bool Widget::szame()
{
    return szamb;
}

bool Widget::kive()
{
    return kiv;
}

int Widget::getszam()
{
    return szam;
}

string Widget::getszoveg()
{
    return s;
}
*/
/*void Widget::rajzol()
{
    //gout<<move_to(10,10)<<color(255,255,255)<<box(10,10);
}*/

void Widget::set_lathato(bool v)
{
    lathato=v;
}

bool Widget::get_lathato()const
{
    return lathato;
}




