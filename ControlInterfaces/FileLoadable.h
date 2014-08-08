#ifndef _FILE_LOADABLE_H_
#define _FILE_LOADABLE_H_

#include <iostream>

#include "Loadable.h"

namespace jer
{
    using std::string;
    class FileLoadable: public Loadable
    {
    private:
        string fileName;
        
    public:
        virtual ~FileLoadable() {};
        FileLoadable(const string &name): fileName(name) {};
        FileLoadable() {};
        FileLoadable(const FileLoadable& other): fileName(other.fileName) {};
        
    public:
        void setFile(const string& name) {fileName = name;};
        const string &getFile() const {return fileName;};
    };
}

#endif /*_FILE_LOADABLE_H_*/