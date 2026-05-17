//#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
//#include <vector>
//#include <fstream>
#include "StaticText.hpp"
#include "TextEdit.hpp"
#include "Application.hpp"
#include "kivalaszto.hpp"
#include "Gomb.hpp"
#include "szambeallito.hpp"
#include "Jatekter.hpp"

using namespace std;
//using namespace genv;

enum allapot{
    START,GAME,OVER
};

class MyApp:public Application
{
protected:
    /*kivalaszto *ki1;
    kivalaszto *ki2;
    Gomb *go1,*go2;
    //StaticText *te1;
    TextEdit *te2;
    ExampleCheckBox *cb;*/
    szambeallito *sz1;
    Jatekmester *jm;
    Jatekter *jt;
    int n=0;
    allapot all;
    Gomb *start;
    Gomb *uj_jatek;
    StaticText *start_szoveg;
    StaticText *jatek_vege_szoveg;
    int ki_jon=1;
    string jatekos="";
    StaticText *kijon_szoveg;
public:
    MyApp(int szel_,int hossz_):
        Application(szel_,hossz_),all(START),jm(nullptr),jt(nullptr),jatek_vege_szoveg(nullptr),uj_jatek(nullptr),kijon_szoveg(nullptr)
    {
        //all=START;
        /*ki1=new kivalaszto(this,10,10,70,20,{"egy","ketto","harom","negy","ot","hat","het"});
        ki2=new kivalaszto(this,100,10,70,20,{"a","be","ce","de","e","ef","ge"});
        go1=new Gomb(this,10,100,70,20,"elso");
        go2=new Gomb(this,100,100,70,20,"masodik");
        //te1=new StaticText(this,10,200,200,50,"valamit, k rlek");
        te2=new TextEdit(this,10,200,200,50,"valamit, k rlek");
        cb=new ExampleCheckBox(this,200,100,40,40);*/
        sz1=new szambeallito(this,275,250,100,30,30,1,20);
        start=new Gomb(this,250,350,100,50,"START",[=](){elindul();},20);
        //uj_jatek=new Gomb(this,10,200,70,20,"RESTART",[=](){elindul();},20);
        start_szoveg=new StaticText(this,250,150,100,80,"Choose Board Size (15x15 - 30x30)",25);
        kijon_szoveg=new StaticText(this,10,10,250,20,"Next player: Blue",20);

        lathatosag();
    }
    /*void action(string id)
    {
        string kiiratando="",fajlnev="";
        if(id=="enter"){
            kiiratando=te2->value();
            fajlnev=te1->value();
        }
        else if(cb->is_checked() && id=="space"){
            kiiratando=te1->value();
            fajlnev=te2->value();
        }
        write(kiiratando,fajlnev);
    }
    void write(string kiiratando, string fajlnev)
    {
        ofstream fajlba(fajlnev);
        fajlba<<kiiratando;
    */
    /*if(id=="enter"){
        //ki1->torles_listabol();
        n=sz1->get_szam();
    }
    }*/
    void update(int x,int y){
        if(all!=GAME)return;
        if(jm->urese(x,y)){
            jm->odarak(x,y);
            ki_jon=jm->melyik_jatekos_van();
            if(ki_jon==1)jatekos="Blue";
            else if(ki_jon==2)jatekos="Red";
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
        //if(sz1)
            sz1->set_lathato(all==START);
        //if(start)
        start->set_lathato(all==START);
        start_szoveg->set_lathato(all==START);
        if(jatek_vege_szoveg)jatek_vege_szoveg->set_lathato(all==OVER);
        if(jt)
        jt->set_lathato(all!=START);

        //vege_szoveg->set_lathato(all==OVER);
        if(uj_jatek)
            uj_jatek->set_lathato(all==OVER);
        if(kijon_szoveg)kijon_szoveg->set_lathato(all==GAME);
    }
    void elindul()
    {
        n=sz1->get_szam();
        ki_jon=1;
        if(kijon_szoveg){
            if(ki_jon==1)jatekos="Blue";
            else if(ki_jon==2)jatekos="Red";
            kijon_szoveg->set_text(jatekos);
        }
        //lathatosag();
        //if(jm)delete jm;
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
    //gout.open(400,400);
    //gout.load_font("LiberationSans-Regular.ttf", 28);
    MyApp a(600,600);
    a.event_loop();
    return 0;
}
