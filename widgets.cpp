#include "widgets.hpp"
#include "graphics.hpp"
#include "Application.hpp"

using namespace genv;

Widget::Widget(Application *_parent,int _x, int _y, int _sx, int _sy) : x(_x), y(_y), sz(_sx), m(_sy),parent(_parent)
{
    if(parent)parent->register_widget(this);
}

bool Widget::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>x && mouse_x<x+sz && mouse_y>y && mouse_y<y+m;
}

void Widget::set_lathato(bool v)
{
    lathato=v;
}

bool Widget::get_lathato()const
{
    return lathato;
}




