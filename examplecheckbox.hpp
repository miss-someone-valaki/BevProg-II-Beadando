#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class ExampleCheckBox : public Widget {
protected:
    bool _checked;
public:
    ExampleCheckBox(Application *,int, int, int, int);
    virtual void rajzol() const override ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() ;
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
