#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include <../widgets.hpp>

using namespace std;

class StaticText : public Widget
{
protected:
    string _text;
    bool le_van_nyomva=false;
    int betumeret=12;
public:
    StaticText(Application *parent,int,int,int,int,string,int);
    void rajzol() const override;
    void handle(genv::event) override;
    void set_text(string);
};

#endif // STATICTEXT_HPP
