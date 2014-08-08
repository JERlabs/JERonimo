#ifndef _MAP_LIST_H_
#define _MAP_LIST_H_

#include <string>
#include <unordered_map>

#include "Declarations.h"


namespace jer
{
    using std::unordered_map;
    using std::string;
    
    template<class T, class MAP_TYPE = unordered_map<string, T> >
    class MapList: public T, public MAP_TYPE
    {
    public:
        typedef const SUCCESS (T:: * FOR_CALLBACK)();
        typedef const SUCCESS (T:: * FOR_CONST_CALLBACK)() const;
    protected:
        MAP_TYPE *ourList;
    public:
        MapList(): ourList(this) {};
        virtual ~MapList() {};
        
    public:
        const SUCCESS foreach(FOR_CALLBACK callBack)
        {
            SUCCESS ret = 0;
            for(auto i = this->begin(); i != this->end() && ret >= 0; i++)
            {
                ret |= (i->second.*callBack)();
            }
            
            return ret;
        };
        
        const SUCCESS foreach(FOR_CONST_CALLBACK callBack) const
        {
            SUCCESS ret = 0;
            for(auto i = this->begin(); i != this->end() && ret >= 0; i++)
            {
                ret |= (i->second.*callBack)();
            }
            
            return ret;
        };
    };
    
    template<class T, class MAP_TYPE>
    class MapList<T *, MAP_TYPE>: public T, public MAP_TYPE
    {
    public:
        typedef const SUCCESS (T:: * FOR_CALLBACK)();
        typedef const SUCCESS (T:: * FOR_CONST_CALLBACK)() const;
    protected:
        MAP_TYPE *ourList;
        
    public:
        MapList(): ourList(this) {};
        virtual ~MapList() {};
        
    public:
        const SUCCESS foreach(FOR_CALLBACK callBack)
        {
            SUCCESS ret = 0;
            for(auto i = this->begin(); i != this->end() && ret >= 0; i++)
            {
                if(i->second == nullptr)
                    ret = -1;
                else
                    ret |= ((*(i->second)).*callBack)();
            }
            
            return ret;
        };
        
        const SUCCESS foreach(FOR_CONST_CALLBACK callBack) const
        {
            SUCCESS ret = 0;
            for(auto i = this->begin(); i != this->end() && ret >= 0; i++)
            {
                if(i->second == nullptr)
                    ret = -1;
                else
                    ret |= ((*(i->second)).*callBack)();
            }   
            
            return ret;
        };
        
        const shared_ptr<T> add(const typename MAP_TYPE::key_type &k, T * const elem) // takes the pointer
        {
            if(this->count(k) == 0)
                return (*ourList)[k] = (shared_ptr<T>(elem));
            else
                return nullptr;
        };
        
        template<class U>
        const shared_ptr<T> copyIn(const typename MAP_TYPE::key_type &k, const U& elem) // copies the object
        {
            if(this->count(k) == 0)
                return (*ourList)[k] = std::make_shared<U>(elem);
            else
                return nullptr;
        };
    };
}

#endif /*_MAP_LIST_H_*/