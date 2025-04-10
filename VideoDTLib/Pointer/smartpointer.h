#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
#include "object.h"
#include <iostream>
#include "pointer.h"

using namespace std;

namespace DTLib{
template <typename T>
class SmartPointer: public Pointer<T>
{
public:
    SmartPointer(T* p = NULL): Pointer<T>(p)
    {
    }

    ~SmartPointer()
    {
        cout<<"delete pointer:"<<this->m_pointer<<endl;
        delete this->m_pointer;
    }

    SmartPointer(const SmartPointer<T>& obj): Pointer<T>(nullptr)
    {
        this->m_pointer = obj.m_pointer;
        const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;


    }
    SmartPointer<T>& operator =(const SmartPointer<T>& obj)
    {
        if(this != &obj)
        {
            T* temp = this->m_pointer;

            this->m_pointer = obj.m_pointer;
            const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;

            delete temp;
        }
        return *this;
    }
};


}


#endif // SMARTPOINTER_H
