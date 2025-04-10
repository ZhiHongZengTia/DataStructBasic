#ifndef ARRAYM_H
#define ARRAYM_H

#include "object.h"
#include "exception.h"


namespace DTLib {

template <typename T>
class ArrayM : public Object
{
protected:
    T* m_array;
public:
    virtual bool set(int i, const T& e);
    virtual bool get(int i,  T& e) const;
    virtual int length() const = 0 ;

    T& operator[] (int i);
    T operator[] (int i) const ;

    T* array() const;
};

template <typename T>
bool ArrayM<T>::set(int i, const T& e)
{
    bool ret = ( (0<=i) && (i<length()));
    if(ret)
    {
        m_array[i] = e;
    }
    return ret;
}

template <typename T>
bool ArrayM<T>::get(int i,  T& e) const
{
    bool ret = ( (0<=i) && (i<length()));
    if(ret)
    {
        e = m_array[i];
    }
    return ret;
}

template <typename T>
T& ArrayM<T>::operator[] (int i)
{
    if( (0<=i) && (i<length())  )
    {
        return m_array[i];
    }
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException,"ArrayM parameter i is invalid ...");
    }
}

template <typename T>
T ArrayM<T>::operator[] (int i) const
{
    return const_cast<ArrayM<T>&>(*this)[i] ;
}

template <typename T>
T* ArrayM<T>::array() const
{
    return m_array;
}


}



#endif // ARRAYM_H
