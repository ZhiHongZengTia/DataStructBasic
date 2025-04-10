#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H

#include "object.h"
#include "Pointer/pointer.h"
#include <cstdlib>
#include "exception.h"

namespace DTLib {

template <typename T>
class SharedPointer: public Pointer<T>
{
protected:
    int* m_ref;  // 计数机制成员指针，用来保存计数值
    void assign(const SharedPointer<T>& obj);

public:
    SharedPointer(T* p = nullptr);
    SharedPointer(const SharedPointer<T>& obj);

    SharedPointer<T>& operator= (const SharedPointer<T>& obj);

    void clear();  // 将当前指针置为空
    ~SharedPointer();
};

template <typename T>
void SharedPointer<T>::assign(const SharedPointer<T>& obj)
{
    this->m_ref = obj.m_ref;
    this->m_pointer = obj.m_pointer;
    if(this->m_ref)
    {
        (*this->m_ref)++;
    }
}


template <typename T>
SharedPointer<T>::SharedPointer(T* p): m_ref(nullptr)
{
    if( p )
    {
        this->m_ref = static_cast<int*>(std::malloc(sizeof(int)));
        if(this->m_ref)
        {
            *(this->m_ref) = 1;
            this->m_pointer = p;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"no enough memory to SharedPointer::SharedPointer(T* p)...");
        }
    }
}

template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T>& obj):Pointer<T>(nullptr)
{
    assign(obj);
}

template <typename T>
SharedPointer<T>& SharedPointer<T>::operator= (const SharedPointer<T>& obj)
{
    if(this != &obj)
    {
        clear();

        assign(obj);

    }
    return *this;
}

template <typename T>
void SharedPointer<T>::clear()  // 将当前指针置为空
{
    T* toDel = this->m_pointer;
    int* ref = this->m_ref;

    this->m_pointer = nullptr;
    this->m_ref = nullptr;
    if(this->m_ref)
    {
        (*this->m_ref)--;
        if(*this->m_ref == 0)
        {
            free(ref);
            delete toDel;
        }
    }
}

template <typename T>
SharedPointer<T>::~SharedPointer()
{
    clear();
}

template< typename T>
bool operator== (const SharedPointer<T>& obj1,const SharedPointer<T>& obj2)
{
    return (obj1.get() == obj2.get());
}

template< typename T>
bool operator!= (const SharedPointer<T>& obj1,const SharedPointer<T>& obj2)
{
    return !(obj1 == obj2);
}



}

#endif // SHAREDPOINTER_H
