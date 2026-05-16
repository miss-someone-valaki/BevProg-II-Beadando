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
    void odarak();
    int get_table(int,int);
protected:
    vector<vector<int>>tabla;
};

#endif // JATEKMESTER_HPP
