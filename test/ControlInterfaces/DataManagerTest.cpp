#include <stdlib.h>
#include <iostream>
#include "ControlInterfaces.h"

using namespace jer;
using namespace std;

class FilePrinter: public FileLoadable, public Loopable
{
private:
    FILE *fp;
    
public:
    FilePrinter(): fp(NULL) {};
    FilePrinter(const FilePrinter &other): FileLoadable(other), fp(other.fp)
    {
        cout<<"Copying file handler: "<<getFile()<<endl;
    };
    
    FilePrinter(const string &n): FileLoadable(n), fp(NULL)
    {
        cout<<"File: "<<getFile()<<endl;
    };
    
    ~FilePrinter()
    {
        if(isLoaded())
            unload();
        cout<<"File "<<getFile()<<" has been removed"<<endl;
    };
    
public:
    const SUCCESS load()
    {
        cout<<"Opening "<<getFile()<<endl;
        if((fp = fopen(getFile().c_str(), "r")) == NULL)
            return FAILED;
        
        cout<<"Opened "<<getFile()<< " successfully!"<<endl;
        Loadable::load();
        return SUCCEEDED;
    };
    
    const SUCCESS unload()
    {
        if(!isLoaded())
            return FAILED;
        cout<<"Closing "<<getFile()<<endl;
        if(fp != NULL)
            fclose(fp);
        fp = NULL;
        Loadable::unload();
        return SUCCEEDED;
    };
    
    const SUCCESS loop()
    {
        static char buffer[256];
        cout<<"showing "<<getFile()<<endl;
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
    DataManager<FileLoadable *> myFiles;
    LoopEngine<FilePrinter *> myFileReads;
    for(int i = 1; i < argc; i++)
    {
        myFiles.push_back(myFileReads.copyIn(FilePrinter(argv[i])));
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
