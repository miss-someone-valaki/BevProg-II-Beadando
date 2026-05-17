#include "szambeallito.hpp"

using namespace genv;
using namespace std;


/*szambeallito::szambeallito(int maxi_,int mini_):
    Widget(),
    maxi(maxi_),mini(mini_)
{
    if(mini_>0)szam = mini_;
    if(maxi_<0)szam=maxi_;
    sz=50;
}*/

szambeallito::szambeallito(Application *parent_,int x_,int y_,int sz_,int m_,int maxi_,int mini_,int betum):
    Widget(parent_,x_,y_,sz_,m_),
    maxi(maxi_),mini(mini_),betumeret(betum)
{
    if(mini_>0)szam = mini_;
    if(maxi_<0)szam=maxi_;
    sz=50;
    //gout.load_font("LiberationSans-Regular.ttf", 12);
}

void szambeallito::rajzol()const
{
    gout.load_font("LiberationSans-Regular.ttf", betumeret);
    //szamb=true;
    string s=to_string(szam);
    gout<<move_to(x,y)<<color(255,255,255)<<box(sz,m);
    gout<<move_to(x+5,y+(m-gout.cascent())/2)<<color(0,0,0)<<text(s);
    if(kijelolve_le){
        gout<<move_to(x+sz-gombsz,y)<<color(200,200,200)<<box_to(x+sz-1,y+m/2)
        <<move_to(x+sz-gombsz,y+m/2)<<color(150,150,150)<<box_to(x+sz-1,y+m-1)
        <<move_to(x+sz-gombsz,y)<<color(0,0,0)<<line(0,m)
        <<move_to(x+sz-gombsz,y+m/2)<<line(gombsz,0)
        <<move_to(x+sz-3,y+m/2-3)
        <<line_to(x+sz-gombsz/2,y+3)<<line_to(x+sz-gombsz+3,y+m/2-3)
        <<move_to(x+sz-3,y+m/2+3)
        <<line_to(x+sz-gombsz/2,y+m-3)<<line_to(x+sz-gombsz+3,y+m/2+3);
    }
    else if(kijelolve_fel){
        gout<<move_to(x+sz-gombsz,y)<<color(150,150,150)<<box_to(x+sz-1,y+m/2)
        <<move_to(x+sz-gombsz,y+m/2)<<color(200,200,200)<<box_to(x+sz-1,y+m-1)
        <<move_to(x+sz-gombsz,y)<<color(0,0,0)<<line(0,m)
        <<move_to(x+sz-gombsz,y+m/2)<<line(gombsz,0)
        <<move_to(x+sz-3,y+m/2-3)
        <<line_to(x+sz-gombsz/2,y+3)<<line_to(x+sz-gombsz+3,y+m/2-3)
        <<move_to(x+sz-3,y+m/2+3)
        <<line_to(x+sz-gombsz/2,y+m-3)<<line_to(x+sz-gombsz+3,y+m/2+3);
    }
    else{
        gout<<move_to(x+sz-gombsz,y)<<color(200,200,200)<<box_to(x+sz-1,y+m-1)
        <<move_to(x+sz-gombsz,y)<<color(0,0,0)<<line(0,m)
        <<move_to(x+sz-gombsz,y+m/2)<<line(gombsz,0)
        <<move_to(x+sz-3,y+m/2-3)
        <<line_to(x+sz-gombsz/2,y+3)<<line_to(x+sz-gombsz+3,y+m/2-3)
        <<move_to(x+sz-3,y+m/2+3)
        <<line_to(x+sz-gombsz/2,y+m-3)<<line_to(x+sz-gombsz+3,y+m/2+3);
    }
    //Widget::rajzol()const;
}

bool szambeallito::folotte_fel(int px,int py){
    if(px>=x+sz-gombsz && px<=x+sz && py>=y && py<=y+m/2)return true;
    else return false;
}

bool szambeallito::folotte_le(int px,int py){
    if(px>=x+sz-gombsz && px<=x+sz && py>=y+m/2 && py<=y+m)return true;
    else return false;
}

void szambeallito::handle(event ev)
{
    //widget::kezel(ev);
    if(ev.type==ev_mouse && ev.button==btn_left){
        if(folotte_fel(ev.pos_x,ev.pos_y)){
            kijelolve_fel=true;
            if(szam<maxi)szam++;
        }
        else if(folotte_le(ev.pos_x,ev.pos_y)){
            kijelolve_le=true;
            if(szam>mini)szam--;
        }
    }
    if(ev.type==ev_mouse && ev.button==-btn_left){
        kijelolve_fel=false;
        kijelolve_le=false;
    }
    if(ev.type==ev_key){ //&& is_selected(ev.pos_x,ev.pos_y)){
        if(ev.keycode==key_up){if(szam<maxi)szam++;}
        if(ev.keycode==key_down){if(szam>mini)szam--;}
        if(ev.keycode==key_pgdn){if(szam-10>=mini)szam=szam-10;}
        if(ev.keycode==key_pgup){if(szam+10<=maxi)szam=szam+10;}
    }
}

int szambeallito::get_szam()
{
    return szam;
}
