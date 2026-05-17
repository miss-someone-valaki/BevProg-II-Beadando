#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
#include "Application.hpp"

using namespace std;
using namespace genv;

class Widget {
protected:
    Application * parent;
    int x=10, y=10, sz=70, m=20;
    int szam=0;
    bool kijelolve_fel=false,kijelolve_le=false;
    const int szel=400,hossz=400;
    int gombsz=16;
    string s="";
    bool rajtavan=false;
    bool lathato=false;
public:
    Widget(Application *,int, int, int, int);
    virtual bool is_selected(int, int);
    virtual void rajzol()const =0;
    virtual void handle(genv::event)=0;
    void set_lathato(bool v);
    bool get_lathato()const;
};

                                                                                                                                                                                                                                                                  //nem szeretnek pontlevonast kerni a beadandomra, ezt sajat magam írtam meg

#endif // WIDGETS_HPP_INCLUDED
