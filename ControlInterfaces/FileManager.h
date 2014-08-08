#ifndef _FILE_MANAGER_H_
#define _FILE_MANAGER_H_

#include "DataManager.h"
#include "FileLoadable.h"
#include "MapList.h"

namespace jer
{
    class FileManager: public DataManager<FileLoadable *, MapList<FileLoadable *, unordered_map<string, shared_ptr<FileLoadable> > > >
    {
    public:
        //typedef FileLoadable * (*FACTORY_FUNC)(const string&);
        
    private:
        const shared_ptr<FileLoadable> add(const string &k, FileLoadable * const elem) // takes the pointer
        {
            return MapList<FileLoadable *, unordered_map<string, shared_ptr<FileLoadable> > >::add(k, elem);
        };
        
        template<class U>
        const shared_ptr<FileLoadable> copyIn(const string &k, const U& elem) // copies the object
        {
            return MapList<FileLoadable *, unordered_map<string, shared_ptr<FileLoadable> > >::copyIn(k, elem);
        };
        
        shared_ptr<FileLoadable> &operator[] (const string& name) {return unordered_map<string, shared_ptr<FileLoadable> >::operator[](name);};
        
    public:
        template<class T>
        const shared_ptr<T> access(const string &name)//, T * (*factory)(const string&))
        {
            if(this->count(name))
                return std::dynamic_pointer_cast<T>(this->at(name));
            else
            {
                FileLoadable *file = new T(name);
                if(file == NULL)
                    return nullptr;
                return std::dynamic_pointer_cast<T>(add(name, file));
            }
        };
    };
}

#endif /*_FILE_MANAGER_H_*/