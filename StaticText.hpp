#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include <../widgets.hpp>

using namespace std;

class StaticText : public Widget
{
protected:
    string _text;
    //vector<string>szoveg;
    //vector<string>szavak;
    //int elcsuszas=0;
    //int szoveghossz=0;
    bool le_van_nyomva=false;
    //int min_y_meret=100,min_x_meret=100;
    //mutable bool utolso_elem_is_kiirva=false;
    int betumeret=12;
public:
    StaticText(Application *parent,int,int,int,int,string,int);
    void rajzol() const override;
    void handle(genv::event) override;
    //bool huzgalo_folott(genv::event);
    void set_text(string);
};

#endif // STATICTEXT_HPP
