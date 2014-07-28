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
                this->unload();
        };
        
    public:
        virtual const SUCCESS load() override // contiguous array in this specialization
        {
            SUCCESS ret = this->foreach(&Loadable::load);
            if(ret >= 0)
                Loadable::load();   // keeps track of loaded and unload
            
            return ret;
        };
        
        virtual const SUCCESS unload() override     // contiguous array in this specialization
        {
            Loadable::unload();
            return this->foreach(&Loadable::unload);
        };
    };
    
    using EasyData = DataManager<Loadable *>;
    
}


#endif