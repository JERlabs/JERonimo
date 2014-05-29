#ifndef _DELTA_H_
#define _DELTA_H_

#include "Declarations.h"

namespace jer
{

    template<class T>
    class Delta: public T
    /** Class representing derivatives of certain scalars/vectors.
     * The rate of change itself is of the same type (ie, an increment)
     * Class will have a function for a change across t time-units which is up to the user
     * Will also have a function for an increment across 1 time-unit (iterations maybe) for ease
     * Someone may want the velocity of a point as so
     * <code>Delta\<Vector\> velocity</code>
     * they could get the position using the current() function
     * Someone may want the acceleration of a point as so
     * <code>Delta\<Delta\<Vector\> \> accleration</code>
     * they could get the velocity using the current(1) function where 1 represents how many integrals you take
     * they could get the current position using current(2) OR current(). 
     * current() will be specialized to recursively call current for Delta\<Delta\<T\> \>
     */
    {
	private:
		typedef BASE_TYPE T;
    private:
        T value;
        T *delta;
        
    public:
        Delta(const T &increment, const T &init): T(increment), value(init), delta(this) {};
        Delta(const T &increment): T(increment), value(), delta(this) {};
        Delta(): T(), value(), delta(this) {};
        
    public:
        const BASE_TYPE *get(int i=0) const {return &value;};
        const T current() const {return value;};
        void increment(const double iterations) {value += iterations*(*delta);};
        void increment() {increment(1.0);};
    };
    
    template<>
    class Delta<Delta<T> >: public Delta<T>
    {
	private:
		typedef BASE_TYPE Delta<T>::BASE_TYPE;
    private:
        Delta<T> value;
        Delta<T> *delta;
        
    public:
        Delta(const Delta<T> &increment, const Delta<T> &init): Delta<T>(increment), value(init), delta(this) {};
        Delta(const Delta<T> &increment): Delta<T>(increment), value(), delta(this) {};
        Delta(): Delta<T>(), value(), delta(this) {};
        
    public:
        const BASE_TYPE *get(int i=0) const {if(i == 1) return &value; else return value.get(i-1);};        
    };
    
}


#endif