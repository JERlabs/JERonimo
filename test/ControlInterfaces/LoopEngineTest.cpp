#include "ControlInterfaces.h"
#include <string>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::remove;
using namespace jer;

class DoCrap: public Loopable
{
private:
    char name;
public:
    DoCrap(const char n): name(n)
    {
        cout<<"Making crap "<<name<<endl;
        //setPriority(name - 'b');
    };
    
    DoCrap(const DoCrap& other): name(other.name) {cout<<"Copying crap "<<name<<endl;};
    
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
    char name;
    
public:
    DoShit(const char n): name(n)
    {
        cout<<"Making shit "<<name<<endl;
        //setPriority(name - 'b');
    }
    
    DoShit(const DoShit& other): name(other.name) {cout<<"Copying shit "<<name<<endl;};
    
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
    EasyLoop combinedList;
    
    auto myCrap = combinedList.copyIn(DoCrap('a'));
    auto myShit = combinedList.copyIn(DoShit('b'));
    auto myDynamicCrap = combinedList.add(new DoCrap('c'));
    
    cout<<"combinedList: "<<endl;
    combinedList.loop();
    
    combinedList.erase(remove(combinedList.begin(), combinedList.end(), *myDynamicCrap), combinedList.end());
    
    cout<<"combinedList: "<<endl;
    combinedList.loop();
    
    combinedList.add(new DoShit('d'));
    combinedList.add(new DoCrap('e'));
    
    cout<<"combinedList: "<<endl;
    combinedList.loop();
    
    return 0;
}