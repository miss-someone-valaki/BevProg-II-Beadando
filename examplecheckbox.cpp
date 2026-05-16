#include "examplecheckbox.hpp"
#include "graphics.hpp"
using namespace genv;

ExampleCheckBox::ExampleCheckBox(Application *_parent,int _x, int _y, int sx, int sy)
    : Widget(_parent,_x,_y,sx,sy)
{
    _checked=false;
}

void ExampleCheckBox::rajzol() const
{
    gout << move_to(x, y) << color(255,255,255) << box(sz, m);
    gout << move_to(x+2, y+2) << color(0,0,0) << box(sz-4, m-4);
    if (_checked) {
        gout << color(255,255,255);
        gout << move_to(x+4, y+4) << line(sz-8, m-8);
        gout << move_to(x+5, y+4) << line(sz-8, m-8);
        gout << move_to(x+sz-4, y+4) << line(-sz+8, m-8);
        gout << move_to(x+sz-5, y+4) << line(-sz+8, m-8);
    }
}

void ExampleCheckBox::handle(event ev)
{
    /*if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
            _checked = !_checked;
    }*/
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _checked = !_checked;
    }
}
bool ExampleCheckBox::is_checked()
{
    return _checked;
}
