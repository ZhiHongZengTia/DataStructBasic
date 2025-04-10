#ifndef POINTER_H
#define POINTER_H

#include "object.h"

namespace DTLib {

template <typename T>
class Pointer : public Object
{
protected:
    T* m_pointer;
public:
    Pointer(T* p = nullptr);
    T* operator-> ();
    T& operator* ();
    const T* operator-> () const;
    const T& operator* () const;

    bool isNull() const;
    T* get() const;
//    ~Pointer() = 0;
};

template <typename T>
Pointer<T>::Pointer(T* p )
{
    m_pointer = p;
}

template <typename T>
T* Pointer<T>::operator-> ()
{
    return m_pointer;
}

template <typename T>
T& Pointer<T>::operator* ()
{
    return *m_pointer;
}

template <typename T>
const T* Pointer<T>::operator-> () const
{
    return m_pointer;
}

template <typename T>
const T& Pointer<T>::operator* () const
{
    return *m_pointer;
}


template <typename T>
bool Pointer<T>::isNull() const
{
    return (m_pointer == nullptr);
}

template <typename T>
T* Pointer<T>::get() const
{
    return m_pointer;
}


}


#endif // POINTER_H
