#ifndef APPLICATION_HPP
#define APPLICATION_HPP

class Widget;

#include<vector>
#include<string>

using namespace std;

class Application
{
protected:
    std::vector<Widget *> widget;
    int szel,hossz;
public:
    Application(int,int);
    virtual ~Application();
    void event_loop();
    void register_widget(Widget *);
};

#endif // APPLICATION_HPP
