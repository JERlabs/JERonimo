#ifndef _DATA_MANAGER_H_
#define _DATA_MANAGER_H_

#include "GameList.h"
#include "Loadable.h"
#include "SortList.h"

namespace jer
{
    template<class T, template<class U> class LIST_TYPE = GameList>
    class DataManager: public LIST_TYPE<T>
    {
    protected:
        LIST_TYPE<T> *loadList;
        
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
    using EasySortData = DataManager<Loadable *, SortList>;
}


#endif