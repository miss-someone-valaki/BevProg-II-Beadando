#include "widgets.hpp"
#include "StaticText.hpp"
#include "Application.hpp"
#include "Gomb.hpp"
#include "szambeallito.hpp"
#include "Jatekter.hpp"

using namespace std;

enum allapot{
    START,GAME,OVER
};

class MyApp:public Application
{
protected:
    szambeallito *sz1;
    Jatekmester *jm;
    Jatekter *jt;
    Gomb *start;
    Gomb *uj_jatek;
    StaticText *start_szoveg;
    StaticText *jatek_vege_szoveg;
    StaticText *kijon_szoveg;
    int n=0;
    allapot all;
    int ki_jon=1;
    string jatekos="";
public:
    MyApp(int szel_,int hossz_):
        Application(szel_,hossz_),all(START),jm(nullptr),jt(nullptr),jatek_vege_szoveg(nullptr),uj_jatek(nullptr),kijon_szoveg(nullptr)
    {
        sz1=new szambeallito(this,275,250,50,30,30,15,20);
        start=new Gomb(this,250,350,100,50,"START",[=](){elindul();},20);
        start_szoveg=new StaticText(this,250,150,100,80,"Choose Board Size (15x15 - 30x30)",25);
        kijon_szoveg=new StaticText(this,10,10,250,20,"Next player: Blue",20);

        lathatosag();
    }
    void update(int x,int y){
        if(all!=GAME)return;
        if(jm->urese(x,y)){
            jm->odarak(x,y);
            ki_jon=jm->melyik_jatekos_van();
            if(ki_jon==1)jatekos="Next player: Blue";
            else if(ki_jon==2)jatekos="Next player: Red";
            kijon_szoveg->set_text(jatekos);
        }
        if(jm->ellenorzes(x,y)){
            all=OVER;
            jatek_vege_szoveg=new StaticText(this,175,100,250,100,"GAME OVER",30);
            uj_jatek=new Gomb(this,225,250,150,100,"RESTART",[=](){startra();},30);
            lathatosag();
        }
    }
    void lathatosag() {
        sz1->set_lathato(all==START);
        start->set_lathato(all==START);
        start_szoveg->set_lathato(all==START);
        if(jatek_vege_szoveg)jatek_vege_szoveg->set_lathato(all==OVER);
        if(jt)jt->set_lathato(all!=START);
        if(uj_jatek)uj_jatek->set_lathato(all==OVER);
        if(kijon_szoveg)kijon_szoveg->set_lathato(all==GAME);
    }
    void elindul()
    {
        n=sz1->get_szam();
        ki_jon=1;
        if(kijon_szoveg){
            if(ki_jon==1)jatekos="Next player: Blue";
            else if(ki_jon==2)jatekos="Next player: Red";
            kijon_szoveg->set_text(jatekos);
        }
        if (jm) delete jm;
        jm=new Jatekmester(n,n);
        jt=new Jatekter(this,30,40,530,530,n,[=](int x,int y){update(x,y);},jm);
        all=GAME;
        lathatosag();
    }
    void startra()
    {
        all=START;
        lathatosag();
    }
};

int main()
{
    MyApp a(600,600);
    a.event_loop();
    return 0;
}
