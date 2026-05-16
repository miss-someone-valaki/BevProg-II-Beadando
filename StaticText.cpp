#include "StaticText.hpp"
#include <iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace genv; using namespace std;

StaticText::StaticText(Application *_parent,int _x,int _y,int sx,int sy,std::string t):Widget(_parent,_x,_y,sx,sy),_text(t)
{
    ifstream f(_text);
    if(!f.is_open()){
        cerr<<"Hiba!";
    }
    string sor;
    while(getline(f,sor,'\n')){
        stringstream ss(sor);
        string szo;
        while(ss>>szo){
            szavak.push_back(szo);
        }
    }
}

void StaticText::rajzol() const
{
    utolso_elem_is_kiirva=false;
    int sorszam=elcsuszas,eppenhol=x+5,hanyadik_szo=0;
    gout<<move_to(0,0)<<color(0,0,0)<<box(szel,hossz);
    gout<<move_to(x,y)<<color(255,255,255)<<box(sz,m)<<move_to(x+5,y+15)<<color(255,0,0);
    for(int i=0;i<szavak.size();i++){
        if(sorszam*20<m){
            if(eppenhol+gout.twidth(szavak[i])>x+sz-5){
                sorszam++;
                eppenhol=x+5;
                if(y+15+sorszam*20>=y+15 && y+15+sorszam*20<y+m)gout<<move_to(eppenhol,y+15+sorszam*20)<<text(szavak[i])<<text(" ");
                if(i==szavak.size()-1)utolso_elem_is_kiirva=true;
                eppenhol+=gout.twidth(szavak[i])+gout.twidth(" ");
            }
            else{
                if(y+15+sorszam*20>=y+15 && y+15+sorszam*20<y+m)gout<<move_to(eppenhol,y+15+sorszam*20)<<text(szavak[i])<<text(" ");
                eppenhol+=gout.twidth(szavak[i])+gout.twidth(" ");
                if(i==szavak.size()-1)utolso_elem_is_kiirva=true;
            }
        }
    }
    gout<<color(0,255,0)<<move_to(x+sz-3,y+m-3)<<box(6,6);
}

bool StaticText::huzgalo_folott(event ev)
{
    if(ev.pos_x>=x+sz-3 && ev.pos_x<=x+sz+3 && ev.pos_y>=y+m-3 && ev.pos_y<=y+m+3)return true;
    else return false;
}

void StaticText::handle(event ev)
{
    if(ev.type==ev_mouse){
        if(ev.button==btn_wheeldown && !utolso_elem_is_kiirva){
            elcsuszas--;
        }
        if(ev.button==btn_wheelup && elcsuszas<0){
            elcsuszas++;
        }
        if(huzgalo_folott(ev) && ev.button==btn_left){
            le_van_nyomva=true;
        }
        if(huzgalo_folott(ev) && ev.button==-btn_left){
            le_van_nyomva=false;
        }
        if(le_van_nyomva){
            if(ev.pos_x-x>min_x_meret)sz=ev.pos_x-x;
            if(ev.pos_y-y>min_y_meret)m=ev.pos_y-y;
        }
    }
}
