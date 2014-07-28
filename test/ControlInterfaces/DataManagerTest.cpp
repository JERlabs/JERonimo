#include <stdlib.h>
#include <iostream>
#include "ControlInterfaces.h"

using namespace jer;
using namespace std;

class FilePrinter: public Loadable, public Loopable
{
private:
    string name;
    FILE *fp;
    
public:
    FilePrinter(): fp(NULL) {};
    FilePrinter(const FilePrinter &other): name(other.name), fp(other.fp)
    {
        cout<<"Copying file handler: "<<name<<endl;
    };
    
    FilePrinter(const string &n): name(n), fp(NULL)
    {
        cout<<"File: "<<name<<endl;
    };
    
    ~FilePrinter()
    {
        if(isLoaded())
            unload();
        cout<<"File "<<name<<" has been removed"<<endl;
    };
    
public:
    const SUCCESS load()
    {
        cout<<"Opening "<<name<<endl;
        if((fp = fopen(name.c_str(), "r")) == NULL)
            return FAILED;
        
        cout<<"Opened "<<name<< " successfully!"<<endl;
        Loadable::load();
        return SUCCEEDED;
    };
    
    const SUCCESS unload()
    {
        if(!isLoaded())
            return FAILED;
        cout<<"Closing "<<name<<endl;
        if(fp != NULL)
            fclose(fp);
        fp = NULL;
        Loadable::unload();
        return SUCCEEDED;
    };
    
    const SUCCESS loop()
    {
        static char buffer[256];
        cout<<"showing "<<name<<endl;
        if(!isLoaded())
            return FAILED;
        while(fgets(buffer, 256, fp) != NULL)
        {
            puts(buffer);
        }
        
        cout<<"File, read"<<endl;
        return SUCCEEDED;
    };
};


int main(int argc, char **argv)
{
    EasyData myFiles;
    LoopEngine<FilePrinter *> myFileReads;
    for(int i = 1; i < argc; i++)
    {
        myFiles.push_back(*myFileReads.copyIn(FilePrinter(argv[i])));
    }
    if(myFiles.load() < 0)
    {
        cout<<"Bad File!"<<endl;
        return -1;
    }
    if(myFileReads.loop() < 0)
    {
        cout<<"Hasn't loaded!"<<endl;
        return -1;
    }
    /*if(myFiles.unload() < 0)
    {
        cout<<"Failed to unload!"<<endl;
        return -1;
    }*/
    return 0;
}
