#include "Application.hpp"
#include "../widgets.hpp"
#include <vector>

using namespace genv;

Application::Application(int _szel,int _hossz):szel(_szel),hossz(_hossz)
{
    gout.open(szel,hossz);
}

Application::~Application()
{
    for(Widget * w:widget)delete w;
}

void Application::event_loop()
{
    for(Widget*w:widget){
        if(w->get_lathato())
            w->rajzol();
    }
    gout<<refresh;
    event ev;
    int focus = -1;
    while(gin >> ev && ev.keycode!=key_escape) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widget.size();i++) {
                if (widget[i]->get_lathato() && widget[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        /*if(ev.type==ev_key){
            if(ev.keycode==key_enter){
                action("enter");
            }
            else if(ev.keycode==key_space){
                action("space");
            }
        }*/
        if(focus!=-1 && !widget[focus]->get_lathato())focus=-1;
        if (focus!=-1) {
            widget[focus]->handle(ev);
        }
        gout<<move_to(0,0)<<color(0,0,0)<<box(szel,hossz);
        for (Widget * w : widget) {
            if(w->get_lathato())w->rajzol();
        }
        gout << refresh;
    }
}

void Application::register_widget(Widget *w)
{
    widget.push_back(w);
}

/*void Application::torles_listabol(string kiirni)
{
    _widget.erase(kiirni);
}*/
