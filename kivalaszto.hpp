#ifndef KIVALASZTO_HPP
#define KIVALASZTO_HPP

#include <../widgets.hpp>
//#include "Application.hpp"
#include<vector>

using namespace std;
using namespace genv;

class kivalaszto : public Widget {
protected:
    vector<string> szovegek;
    bool kijelolve=false;
    int gombsz=18;
    int gorgosz=5;
    string kiirni;
    int tetelszam=2;
    int tol=0;
public:
    /*kivalaszto(vector<string> szovegek_);
    kivalaszto(vector<string> szovegek_,int x_,int _y);
    kivalaszto(vector<string> szovegek_,int x_,int _y,int sz_);
    kivalaszto(Application *,vector<string> szovegek_,int x_,int _y,int sz_,int tetelszam_);*/
    kivalaszto(Application *,int,int,int,int,vector<string>);
    void rajzol()const override;
    bool folotte_gomb(int,int);
    int folotte_i(int,int);
    void handle(event)override;
    bool is_selected(int,int);
    void torles_listabol();
    //string eppen_kijelolt_szoveg;
};

#endif // KIVALASZTO_HPP
