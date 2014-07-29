#include "ControlInterfaces.h"
#include <string>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::remove;
using namespace jer;

class DoCrap: public PriorityLoopable
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
    
    const int getPriority() const override {return name-'a';}; 
};

class DoShit: public PriorityLoopable
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
    
    const int getPriority() const override {return name-'a';};
};

int main(int argc, char **argv)
{
    EasyPriorityLoop combinedList;
    
    auto myCrap = combinedList.copyIn(DoCrap('c'));
    auto myShit = combinedList.copyIn(DoShit('a'));
    auto myDynamicCrap = combinedList.add(new DoCrap('b'));
    
    combinedList.sort();
    
    cout<<"combinedList: "<<endl;
    combinedList.loop();
    
    combinedList.erase(remove(combinedList.begin(), combinedList.end(), *myDynamicCrap), combinedList.end());
    
    cout<<"combinedList: "<<endl;
    combinedList.loop();
    
    combinedList.add(new DoShit('e'));
    combinedList.add(new DoCrap('d'));
    
    cout<<"combinedList: "<<endl;
    combinedList.sort();
    combinedList.loop();
    
    return 0;
}