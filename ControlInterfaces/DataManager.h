#ifndef _DATA_MANAGER_H_
#define _DATA_MANAGER_H_

#include "GameList.h"

namespace jer
{
    template<class T>
    class DataManager: public GameList<T>
    {
    protected:
        GameList<T> *loadList;
        
    public:
        DataManager(): loadList(NULL) {};
        virtual ~DataManager() {
            if(Loadable::isLoaded())
                loadList->unload();
        };
        
    public:
        virtual const SUCCESS load() // contiguous array in this specialization
        {
            SUCCESS ret = 0;
            T *data = loadList->data();
            int n = loadList->size();
            for(int i = this->getFirst(); i < this->getLast() && ret >= 0; i++)
            {
                ret |= data[i].load();
            }
            
            if(ret >= 0)
                Loadable::load();   // keeps track of loaded and unload
            
            return ret;
        };
        
        virtual const SUCCESS unload() // contiguous array in this specialization
        {
            SUCCESS ret = 0;
            T *data = loadList->data();
            int n = loadList->size();
            for(int i = this->getFirst(); i < this->getLast() && ret >= 0; i++)
            {
                ret |= data[i].unload();
            }
            
            Loadable::unload();
            
            return ret;
        };
    };
    
    template<class T>
    class DataManager<T *>: public GameList<T *>
    {
    private:
        GameList<T *> *loadList;
        
    public:
        DataManager(): loadList(this) {};
        virtual ~DataManager() {};
        
    public:
        virtual const SUCCESS load() override
        {
            SUCCESS ret = 0;
            for(int i = this->getFirst(); i < this->getLast() && ret >= 0; i++)
            {
                if(loadList->at(i) == NULL)
                    ret = -1;
                else
                    ret |= loadList->at(i)->load();
            }
            
            if(ret >= 0)
                Loadable::load();
            
            return ret;
        };
        
        virtual const SUCCESS unload() override
        {
            SUCCESS ret = 0;
            for(int i = this->getFirst(); i < this->getLast() && ret >= 0; i++)
            {
                if(loadList->at(i) == NULL)
                    ret = -1;
                else
                    ret |= loadList->at(i)->unload();
            }
            Loadable::unload();
            
            return ret;
        };
    };
    
}


#endif