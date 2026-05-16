#include "Jatekmester.hpp"

Jatekmester::Jatekmester(int sz,int m):tabla(sz,vector<int>(m,0))
{
    /*for(int i=0;i<tabla.size();i++){
        for(int j=0;j<tabla[i].size();j++){
            tabla[i][j]=0;
        }
    }*/
    //tabla[0][0]=1;
}

Jatekmester::~Jatekmester()
{
}

bool Jatekmester::urese(int x,int y)
{

}

void Jatekmester::odarak()
{
    //tabla[0][0]=1;
}

int Jatekmester::get_table(int i,int j)
{
    return tabla[i][j];
}
