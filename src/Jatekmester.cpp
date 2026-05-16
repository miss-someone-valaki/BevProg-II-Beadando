#include "Jatekmester.hpp"

Jatekmester::Jatekmester(int sz,int m):table(sz,vector<int>(m,0))
{
    /*for(int i=0;i<tabla.size();i++){
        for(int j=0;j<tabla[i].size();j++){
            tabla[i][j]=0;
        }
    }*/
    //tabla[0][5]=2;
}

Jatekmester::~Jatekmester()
{
}

bool Jatekmester::urese(int mx,int my)
{
    //if(mx>=0 && mx<=sz && my>=0 && my<=m)
        return table[mx][my]==0;
}

void Jatekmester::odarak(int mx,int my)
{
    if(melyik_jatekos==1){
        table[mx][my]=1;
        melyik_jatekos=2;
    }
    else if(melyik_jatekos==2){
        table[mx][my]=2;
        melyik_jatekos=1;
    }

}

int Jatekmester::get_table(int i,int j)
{
    return table[i][j];
}
