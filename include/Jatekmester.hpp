#ifndef JATEKMESTER_HPP
#define JATEKMESTER_HPP

//#include "Jatekter.hpp"
//#include "Alakzat.hpp"
#include <vector>

using namespace std;

//class Application;

class Jatekmester
{
public:
    Jatekmester(int,int);
    virtual ~Jatekmester();
    bool urese(int,int);
    void odarak(int,int);
    int get_table(int,int);
protected:
    vector<vector<int>>table;
    int melyik_jatekos=1;
};

#endif // JATEKMESTER_HPP
