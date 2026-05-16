#include "kivalaszto.hpp"
#include<vector>
#include<algorithm>

using namespace std;
using namespace genv;

/*kivalaszto::kivalaszto(vector<string> szovegek_):
    //Widget(),
    szovegek(szovegek_)
{
    kiirni=szovegek[0];
}

kivalaszto::kivalaszto(vector<string> szovegek_,int x_,int y_):
    widget(x_,y_),
    szovegek(szovegek_)
{
    kiirni=szovegek[0];
}

kivalaszto::kivalaszto(vector<string> szovegek_,int x_,int y_,int sz_):
    widget(x_,y_,sz_),
    szovegek(szovegek_)
{
    kiirni=szovegek[0];
}*/

kivalaszto::kivalaszto(Application *parent_,int x_,int y_,int sz_,int m_,vector<string> szovegek_):
    Widget(parent_,x_,y_,sz_,m_),
    szovegek(szovegek_)
    //tetelszam(tetelszam_)
{
    kiirni=szovegek[0];
}

void kivalaszto::rajzol() const
{
    //kiv=true;
    string s=kiirni;
    if(kijelolve){
        for(int i=0;i<tetelszam;i++){
            if(tol+i<szovegek.size()){
                gout<<move_to(x,y+(i+1)*m)<<color(255,255,255)<<box(sz,m)
                <<move_to(x,y+(i+1)*m)<<color(0,0,0)<<line(sz-gorgosz,0)
                <<move_to(x+5,y+(i+1)*m+m/2+gout.cascent()/2)
                <<color(0,0,0)<<text(szovegek[tol+i]);
            }
        }
        if (szovegek.size()>tetelszam) {
            gout<<move_to(x+sz-gorgosz,y+m+(tetelszam*m-15)*tol/(szovegek.size()-tetelszam))
            <<color(150,150,150)<<box(gorgosz,15);
        }
        gout<<move_to(x,y)<<color(255,255,255)<<box(sz,m)
        <<move_to(x+5,y+m/2+gout.cascent()/2)<<color(0,0,0)<<text(s)
        <<move_to(x+sz-gombsz,y)<<color(150,150,150)<<box_to(x+sz-1,y+m-1)
        <<move_to(x+sz-gombsz,y)<<color(0,0,0)<<line(0,m)
        <<move_to(x+sz-3,y+m/2-3)
        <<line_to(x+sz-gombsz/2,y+m/2+3)<<line_to(x+sz-gombsz+3,y+m/2-3)
        <<move_to(x,y+m)<<color(0,0,0)<<line_to(x+sz,y+m);

    }
    else{
        gout<<move_to(x,y+m)<<color(0,0,0)<<box(x+sz,y+tetelszam*m)
        <<move_to(x,y)<<color(255,255,255)<<box(sz,m)
        <<move_to(x+5,y+m/2+gout.cascent()/2)<<color(0,0,0)<<text(s)
        <<move_to(x+sz-gombsz,y)<<color(200,200,200)<<box_to(x+sz-1,y+m-1)
        <<move_to(x+sz-gombsz,y)<<color(0,0,0)<<line(0,m)
        <<move_to(x+sz-3,y+m/2-3)
        <<line_to(x+sz-gombsz/2,y+m/2+3)<<line_to(x+sz-gombsz+3,y+m/2-3);
    }
    //Widget::rajzol();
}

bool kivalaszto::is_selected(int mx,int my){
    if(kijelolve){
        return mx>=x && mx<=x+sz && my>=y && my<=y+m+(tetelszam*m);
    }
    return mx>=x && mx<=x+sz && my>=y && my<=y+m;
}

bool kivalaszto::folotte_gomb(int px,int py)
{
    if(px>=x+sz-gombsz && px<=x+sz && py>=y && py<=y+m)return true;
    else return false;
}

int kivalaszto::folotte_i(int px,int py)
{
    for(int i=0;i<tetelszam;i++){
        if(px>=x && px<=x+sz && py>=y+(i+1)*m && py<=y+(i+2)*m && kijelolve)return tol+i;
    }
    return -1;
}

void kivalaszto::handle(event ev)
{
    //Widget::handle(ev);
    if(ev.type==ev_mouse && ev.button==btn_left){
        if(!is_selected(ev.pos_x,ev.pos_y)){
            kijelolve=false;
        }
        else if(folotte_gomb(ev.pos_x, ev.pos_y)){
            kijelolve=!kijelolve;
            if(!kijelolve)tol=0;
        }
        else if(kijelolve){
            if (folotte_i(ev.pos_x,ev.pos_y)!=-1){
                kiirni=szovegek[folotte_i(ev.pos_x,ev.pos_y)];
                kijelolve=false;
                tol=0;
            }
        }
    }
    if(ev.type==ev_mouse && ev.button==btn_wheeldown && kijelolve)if(tol+tetelszam<szovegek.size())tol++;
    if(ev.type==ev_mouse && ev.button==btn_wheelup && kijelolve)if(tol>0)tol--;
}
/*string kivalaszto::eppen_kijelolt_szoveg()
{
    return kiirni;
}*/

void kivalaszto::torles_listabol()
{
    //int a=find(szovegek.begin(),szovegek.end(),kiirni);
    szovegek.erase(find(szovegek.begin(),szovegek.end(),kiirni));
}
