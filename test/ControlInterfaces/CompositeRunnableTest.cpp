#include "ControlInterfaces.h"
#include <stdio.h>
#include <iostream>



using namespace jer;
using namespace std;

class FileWriter: public CompositeRunnable
{
public:
    virtual ~FileWriter() {};
    FileWriter(): count(0) {};
    FileWriter(Loadable * const loadPart, Loopable * const loopPart, Displayable * const displayPart):
        CompositeRunnable(loadPart, loopPart, displayPart) {};
    
private:
    int count;
public:
    const SUCCESS load() override {count = 0; return CompositeRunnable::load();};
    const SUCCESS loop() override {if(count++ >= 20) running = false; return CompositeRunnable::loop();};
};

class FileEntity: public Loadable, public Loopable, public Displayable
{
private:
    string name;
    string lastLine;
    FILE *fp;
    enum {AEIOU, JOHN_MADDEN, FOOTBALL, HOLLA} current;
    
public:
    virtual ~FileEntity() 
    {
        if(isLoaded()) 
            unload();
        cout<<"File, "<<name<<", is now closed"<<endl;
    };
    
    FileEntity(const FileEntity &other): name(other.name), fp(other.fp)
    {
        cout<<"Copying file "<<name<<endl;
    };
    
    FileEntity(const string& f): name(f)
    {
        cout<<"Constructor file handler for "<<name<<endl;
    };
    
public:
    const SUCCESS load() override
    {
        cout<<"Opening "<<name<<endl;
        if((fp = fopen(name.c_str(), "w")) == NULL)
            return FAILED;
        
        cout<<"Opened "<<name<< " successfully!"<<endl;
        Loadable::load();
        return SUCCEEDED;
    }
    
    const SUCCESS unload() override
    {
        if(!isLoaded())
            return FAILED;
        cout<<"Closing "<<name<<endl;
        Loadable::unload();
        if(fp != NULL)
            return fclose(fp);
        fp = NULL;
        return SUCCEEDED;
    };
    
    const SUCCESS loop() override
    {
        switch(current)
        {
        case AEIOU:
            lastLine = "aeiou";
            current = JOHN_MADDEN;
            break;
            
        case JOHN_MADDEN:
            lastLine = "John Madden";
            current = FOOTBALL;
            break;
            
        case FOOTBALL:
            lastLine = "Football!";
            current = HOLLA;
            break;
            
        case HOLLA:
            lastLine = "Holla Holla Get $";
            current = AEIOU;
            break;
        }
        
        return fputs(lastLine.c_str(), fp);
    };
    
    const SUCCESS display() const override
    {
        cout<<"Writing "<<lastLine<<" to "<<name<<endl;
        return SUCCEEDED;
    };
    
};

int main(int argc, char **argv)
{
    EasyData *loadList;
    EasyLoop *loopList;
    EasyDisplay *displayList;
    
    FileWriter fw(loadList = new EasyData, loopList = new EasyLoop, displayList = new EasyDisplay);
    for(int i = 1; i < argc; i++)
    {
        shared_ptr<FileEntity> fe(new FileEntity(argv[i]));
        loadList->push_back(fe);
        loopList->push_back(fe);
        displayList->push_back(fe);
    }
    
    return fw.run();
}


