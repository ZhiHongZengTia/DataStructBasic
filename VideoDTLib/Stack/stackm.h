#ifndef STACKM_H
#define STACKM_H

#include "object.h"

namespace DTLib {

template < typename T>
class StackM: public Object
{
public:
    virtual void push(const T& e) = 0;
    virtual void pop() = 0;
    virtual T top() const = 0 ;
    virtual void clear() = 0 ;
    virtual int size() const = 0;
};

}


#endif // STACKM_H
