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
                gout<<move_to(x+i*kockaszm+1,y+j*kockaszm+1)<<color(200,200,200)<<box(kockaszm-2,kockaszm-2);
            }
            else if(jm->get_table(i,j)==1){
                gout<<move_to(x+i*kockaszm+1,y+j*kockaszm+1)<<color(200,200,200)<<box(kockaszm-2,kockaszm-2);
                gout<<move_to(x+i*kockaszm+3,y+j*kockaszm+3)<<color(0,0,255)<<line(kockaszm-6,kockaszm-6);
                gout<<move_to(x+i*kockaszm+kockaszm-3,y+j*kockaszm+3)<<color(0,0,255)<<line(-kockaszm+6,kockaszm-6);
            }
            else if(jm->get_table(i,j)==2){
                gout<<move_to(x+i*kockaszm+1,y+j*kockaszm+1)<<color(200,200,200)<<box(kockaszm-2,kockaszm-2);
                int r=(kockaszm-6)/2;
                //r=kockaszm;
                for(int k=-r;k<r;k++){
                    for(int l=-r;l<r;l++){
                        if(k*k+l*l<=(r-1)*(r-1)){
                            gout<<color(200,200,200)<<move_to(x+i*kockaszm+kockaszm/2+k,y+j*kockaszm+kockaszm/2+l)<<dot;
                        }
                        else if(k*k+l*l<=r*r){
                            gout<<color(255,0,0)<<move_to(x+i*kockaszm+kockaszm/2+k,y+j*kockaszm+kockaszm/2+l)<<dot;
                        }
                    }
                }

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

int Jatekter::melyik_negyzet_folott_x(int mx)
{
    return (mx-x)/kockaszm;
}

int Jatekter::melyik_negyzet_folott_y(int my)
{
    return (my-y)/kockaszm;
}

void Jatekter::handle(event ev)
{
    if(ev.type==ev_mouse && ev.button==btn_left && is_selected(ev.pos_x,ev.pos_y)){
        int mx=melyik_negyzet_folott_x(ev.pos_x);
        int my=melyik_negyzet_folott_y(ev.pos_y);
        if(mx>=0 && my>=0 && mx<szdb && my<mdb)
            f(mx,my);
        //Jatekmester::handle(ev.pos_x,ev.pos_y);
    }
}
