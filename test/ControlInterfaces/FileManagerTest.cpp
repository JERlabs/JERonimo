#include <stdlib.h>
#include <fstream>

#include "ControlInterfaces.h"

using namespace std;
using namespace jer;

class TextFile: public FileLoadable, public fstream
{
public:
    virtual ~TextFile()
    {
        if(isLoaded())
            unload();
        cout<<"File Handler Destroyed"<<endl;
    }
    
    TextFile(const string &name): FileLoadable(name)
    {
        cout<<"File handler "<<getFile()<<" created"<<endl;
    }
    
    TextFile()
    {
        cout<<"Empty file handler created"<<endl;
    }
    
    TextFile(const TextFile& other): FileLoadable(other)
    {
        cout<<"Copied file handler "<<getFile()<<endl;
    }
    
public:
    const SUCCESS load() override
    {
        cout<<"Opening stream for "<<getFile()<<endl;
        if(is_open())
            close();
        
        open(getFile());
        if(!is_open())
            return FAILED;
        
        cout<<"Opened stream "<<getFile()<<" successfully!"<<endl;
        Loadable::load();
        return SUCCEEDED;
    }
    
    const SUCCESS unload() override
    {
        cout<<"Closing "<<getFile()<<endl;
        if(isLoaded())
            close();
        
        return Loadable::unload();
    }
};

int main(int argc, char **argv)
{
    FileManager fm;
    TextFile& readme = *fm.access<TextFile>("README.md");
    
    if(fm.load() < 0)
    {
        cout<<"Couldn't load files"<<endl;
        return -1;
    }
    
    string temp;
    readme>>temp;
    cout<<temp<<endl;
}