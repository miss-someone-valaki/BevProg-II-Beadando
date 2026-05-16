#include <iostream>
#include "TextEdit.hpp"
#include <fstream>

using namespace genv;
using namespace std;

TextEdit::TextEdit(Application *_parent,int _x,int _y,int sx,int sy,std::string t):Widget(_parent,_x,_y,sx,sy),_text(t)
{
    kurzorx=_text.length();
}

void TextEdit::rajzol() const
{
    gout<<move_to(x,y)<<color(255,255,255)<<box(sz,m);
    gout<<move_to(x+5,y+m/2+gout.cascent()/2)<<color(255,0,0)<<text(_text);
    gout<<move_to(x+5+gout.twidth(_text.substr(0,kurzorx)),y+m/2-kurzorm/2)<<color(0,0,0)<<line(0,kurzorm);
}

void TextEdit::handle(event ev)
{
        if(ev.keycode==key_left && kurzorx>0){
            kurzorx--;
        }
        else if(ev.keycode==key_right && kurzorx< _text.length()){
            kurzorx++;
        }
        else if(ev.keycode==key_backspace&&kurzorx>0){
            _text.erase(kurzorx-1,1);
            kurzorx--;
        }
        else if(ev.keycode>0&&ev.keycode!=key_backspace&&ev.keycode!=key_left&&ev.keycode!=key_right&&ev.keycode!=key_enter){
            _text.insert(kurzorx,ev.keyutf8);
            kurzorx++;
        }
}

string TextEdit::value() const
{
    return _text;
}

