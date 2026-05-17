#include "Jatekmester.hpp"

Jatekmester::Jatekmester(int sz,int m):
    table(sz,vector<int>(m,0)),tabla_tele(0)
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
        tabla_tele++;
        ellenorzes(mx,my);
        melyik_jatekos=2;
    }
    else if(melyik_jatekos==2){
        table[mx][my]=2;
        tabla_tele++;
        ellenorzes(mx,my);
        melyik_jatekos=1;
    }
    //ellenorzes(mx,my);
}

/*void Jatekmester::ellenorzes(int akt_alak_x,int akt_alak_y)
{

}*/

bool Jatekmester::ellenorzes(int x,int y){
    if(tabla_tele==table.size()*table[0].size()){megtelt=true;return true;}
    int jatekos=table[x][y];
    int dx[]={1,0,1,1};
    int dy[]={0,1,1,-1};

    for(int i=0;i<4;i++){
        gyoztes.clear(); // Minden iránynál tiszta lappal indulunk
        gyoztes.push_back({x,y});
        int db=1;
        int nx=x+dx[i];
        int ny=y+dy[i];
        while(nx>=0 && nx<table.size() && ny>=0 && ny<table[0].size() && table[nx][ny]==jatekos){
            gyoztes.push_back({nx, ny});
            db++;
            nx+=dx[i];
            ny+=dy[i];
        }
        nx=x-dx[i];
        ny=y-dy[i];
        while(nx>=0 && nx<table.size() && ny>=0 && ny<table[0].size() && table[nx][ny]==jatekos){
            gyoztes.push_back({nx, ny});
            db++;
            nx-=dx[i];
            ny-=dy[i];
        }
        if(db>=5){valaki_nyert=true;return true;}
    }
    return false;
}

int Jatekmester::get_table(int i,int j)
{
    return table[i][j];
}
bool Jatekmester::gyoztese(int i, int j)
{
    if(valaki_nyert){
        for(const auto& p:gyoztes){
            if(p.first==i && p.second==j){
                return true;
            }
        }
    }
    return false;
}

int Jatekmester::melyik_jatekos_van()
{
    return melyik_jatekos;
}
