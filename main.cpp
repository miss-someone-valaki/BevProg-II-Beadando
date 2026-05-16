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

class MyApp:public Application
{
protected:
    /*kivalaszto *ki1;
    kivalaszto *ki2;
    Gomb *go1,*go2;
    //StaticText *te1;
    TextEdit *te2;
    ExampleCheckBox *cb;
    szambeallito *sz1;*/
    Jatekter *jt;
public:
    MyApp(int szel_,int hossz_):Application(szel_,hossz_)
    {
        /*ki1=new kivalaszto(this,10,10,70,20,{"egy","ketto","harom","negy","ot","hat","het"});
        ki2=new kivalaszto(this,100,10,70,20,{"a","be","ce","de","e","ef","ge"});
        go1=new Gomb(this,10,100,70,20,"elso");
        go2=new Gomb(this,100,100,70,20,"masodik");
        //te1=new StaticText(this,10,200,200,50,"valamit, kérlek");
        te2=new TextEdit(this,10,200,200,50,"valamit, kérlek");
        cb=new ExampleCheckBox(this,200,100,40,40);
        sz1=new szambeallito(this,10,50,70,20,150,-25);*/
        jt=new Jatekter(this,10,10,15,15);
    }
    void action(string id)
    {/*
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
    if(id=="elsõ"){
        //ki1->torles_listabol();
    }
    }
};

int main()
{
    //gout.open(400,400);
    MyApp a(500,500);
    a.event_loop();
    return 0;
}
