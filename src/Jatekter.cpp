#include "Jatekter.hpp"

using namespace genv;

Jatekter::Jatekter(Application *parent_,int x_,int y_,int szdb_,int mdb_):
    Widget(parent_,x_,y_,szdb_*20,mdb_*20),szdb(szdb_),mdb(mdb_)
{
}

Jatekter::~Jatekter()
{
}

void Jatekter::rajzol()const
{
    for(int i=0;i<szdb;i++){
        for(int j=0;j<mdb;j++){
            gout<<move_to(x+i*kockaszm+1,y+j*kockaszm+1)<<color(200,200,200)<<box(kockaszm-2,kockaszm-2);
        }
    }
}

void Jatekter::handle(event ev)
{

}
