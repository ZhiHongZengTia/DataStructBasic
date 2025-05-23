#ifndef LIST_H
#define LIST_H

#include "object.h"

namespace DTLib
{
template <typename T>
class ListM: public Object
{
protected:
    ListM(const ListM &) ;
    ListM& operator= (const ListM&) ;
public:
    ListM() {}
    virtual bool insert(const T& e) = 0;  // insert to tail
    virtual bool insert(int i, const T& e) = 0;
    virtual bool remove(int i) =0;
    virtual bool set(int i, const T& e) = 0 ;
    virtual bool get(int i, T& e) const  = 0 ;
    virtual int length() const = 0;
    virtual void clear() = 0 ;

};

}




#endif // LIST_H
