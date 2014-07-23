#include "ControlInterfaces.h"
#include <string>
#include <iostream>

using namespace std;
using namespace jer;

class DoCrap: public ListElement<PriorityElement<Loopable> >
{
private:
    char name;
public:
    DoCrap(const char n, LoopEngine<Loopable *, true> * const engine): ListElement<PriorityElement<Loopable> >(engine), name(n)
    {
        cout<<"Making crap "<<name<<endl;
        setPriority(name - 'b');
    };
    
    DoCrap(const char n): name(n)
    {
        cout<<"Making crap "<<name<<endl;
        setPriority(name - 'b');
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

class DoShit: public ListElement<PriorityElement<Loopable> >
{
private:
    char name;
    
public:
    DoShit(const char n, LoopEngine<Loopable *, true> * const engine): ListElement<PriorityElement<Loopable> >(engine), name(n)
    {
        cout<<"Making shit "<<name<<endl;
        setPriority(name - 'b');
    };
    
    DoShit(const char n): name(n)
    {
        cout<<"Making shit "<<name<<endl;
        setPriority(name - 'b');
    }
    
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
    DoCrap myCrap('c');
    DoShit myShit('b');
    DoCrap *myDynamicCrap = new DoCrap('a');
    
    LoopEngine<Loopable *, true> combinedList;
    
    myCrap.addSelfToList(&combinedList);
    myShit.addSelfToList(&combinedList);
    myDynamicCrap->addSelfToList(&combinedList);
        
    cout<<"combinedList: "<<endl;
    combinedList.loop();
    
    delete myDynamicCrap;
    
    cout<<"combinedList: "<<endl;
    combinedList.loop();
    
    combinedList.add(new DoShit('d', NULL));
    new DoCrap('e', &combinedList);
    
    cout<<"combinedList: "<<endl;
    combinedList.loop();
    
    return 0;
}