#ifndef TEXTEDIT_HPP
#define TEXTEDIT_HPP

#include <../widgets.hpp>

using namespace std;
using namespace genv;

class TextEdit : public Widget
{
protected:
    string _text;
    int kurzorx,kurzorm=gout.cascent()+5;
    //genv::canvas vaszon;
public:
    TextEdit(Application *,int,int,int,int,std::string);
    virtual void rajzol() const override;
    virtual void handle(event) override;
    string value() const;
};

#endif // TEXTEDIT_HPP
