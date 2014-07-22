#include "ControlInterfaces.h"
#include <string>
#include <iostream>

using namespace std;
using namespace jer;

class DoCrap: public Loopable
{
private:
    string name;
public:
    DoCrap(const string &n, LoopEngine<Loopable *> * const engine = NULL): Loopable(engine), name(n)
    {
        cout<<"Making crap "<<name<<endl;
    };
    
    ~DoCrap()
    {
        cout<<"Destroying crap "<<name<<endl;
    };
    
public:
    const SUCCESS loop()
    {
        cout<<name<<" Crap!"<<endl;
        return 0;
    };
};

class DoShit: public Loopable
{
private:
    string name;
    
public:
    DoShit(const string &n, LoopEngine<Loopable *> * const engine = NULL): Loopable(engine), name(n)
    {
        cout<<"Making shit "<<name<<endl;
    };
    
    ~DoShit()
    {
        cout<<"Destroying shit "<<name<<endl;
    };
    
public:
    const SUCCESS loop()
    {
        cout<<name<<" Shit!"<<endl;
        return 0;
    };
};

int main(int argc, char **argv)
{
    DoCrap myCrap("a");
    DoShit myShit("b");
    DoCrap *myDynamicCrap = new DoCrap("c");
    
    LoopEngine<Loopable *> combinedList;
    
    myCrap.addSelfToEngine(&combinedList);
    myShit.addSelfToEngine(&combinedList);
    myDynamicCrap->addSelfToEngine(&combinedList);
    
    cout<<"combinedList: "<<endl;
    combinedList.loop();
    
    delete myDynamicCrap;
    
    cout<<"combinedList: "<<endl;
    combinedList.loop();
    
    cout<<"combinedList: "<<endl;
    combinedList.loop();
    
    return 0;
}