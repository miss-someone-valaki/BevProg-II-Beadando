#include "Jatekter.hpp"

using namespace genv;

Jatekter::Jatekter(Application *parent_,int x_,int y_,int sz_,int m_,int n_,function<void(int,int)>f_,Jatekmester*jm_):
    Widget(parent_,x_,y_,sz_,m_),f(f_),szdb(n_),mdb(n_),jm(jm_)
{
    kockaszm=sz/szdb;
}

Jatekter::~Jatekter()
{
}

void Jatekter::rajzol()const
{
    for(int i=0;i<szdb;i++){
        for(int j=0;j<mdb;j++){
            if(jm->get_table(i,j)==0){
                gout<<move_to(x+i*kockaszm+1,y+j*kockaszm+1)<<color(250,200,200)<<box(kockaszm-2,kockaszm-2);
            }

        }
    }
    /*for(int i=0;i<szdb;i++){
        for(int j=0;j<mdb;j++){
            //if(tabla[i][j]==0){
                gout<<move_to(x+i*kockaszm+1,y+j*kockaszm+1)<<color(200,200,200)<<box(kockaszm-2,kockaszm-2);
            //}
        }
    }*/
}

void Jatekter::handle(event ev)
{
    if(ev.type==ev_mouse && ev.button==btn_left){
        //Jatekmester::handle(ev.pos_x,ev.pos_y);
    }
}
