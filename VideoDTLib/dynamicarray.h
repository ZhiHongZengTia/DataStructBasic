#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "object.h"
#include "arraym.h"

namespace DTLib {

template< typename T>
class DynamicArray:public ArrayM<T>
{
protected:
    int m_length;
    T* copy(T* array1, int length, int newLength);
    void init(T* array, int length);

    void update(T* array, int length);
public:
    DynamicArray(int length);
    DynamicArray(const DynamicArray<T>& obj);
    DynamicArray<T>& operator= (const DynamicArray<T>& obj);

    int length() const override;
    void resize(int length);

    ~DynamicArray();
};

template< typename T>
T* DynamicArray<T>::copy(T* array1, int length,int newLength)
{
    T* ret = new T[newLength];
    {
        if(ret != nullptr)
        {
            int size = (length < newLength) ? length: newLength;
            for(int i =0; i<size; ++i)
            {
                ret[i] = array1[i];
            }
        }
    }
    return ret;
}

template< typename T>
void DynamicArray<T>::init(T* array, int length)
{
    if(array != nullptr)
    {
        this->m_array = array;
        this->m_length = length;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException,"DynamicArray no enough memory to init object...");
    }
}

template< typename T>
void DynamicArray<T>::update(T* array, int length)
{
    if(array != nullptr)
    {
        T* temp = this->m_array;
        this->m_array = array;
        this->m_length = length;
        delete[] temp;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException,"DynamicArray no enough memory to update object...");
    }
}

template< typename T>
DynamicArray<T>::DynamicArray(int length)
{
    init(new T[length],length);

//    this->m_array = new T(length);
//    if(this->m_array != nullptr)
//    {
//        this->m_length = length;
//    }
//    else
//    {
//        THROW_EXCEPTION(NoEnoughMemoryException,"DynamicArray no enough memory to create object...");
//    }
}

template< typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& obj)
{
    T* array = copy(obj,obj.length(), obj.length());
    init(array,obj.length());


//    this->m_array = new T[obj.m_length];
//    if(this->m_array != nullptr)
//    {
//        this->m_length = obj.m_length;
//        for(int i = 0 ; i<this->m_length; ++i)
//        {
//            this->m_array[i] = obj.m_array[i];
//        }
//    }
//    else
//    {
//        THROW_EXCEPTION(NoEnoughMemoryException,"DynamicArray no enough memory to create object...");
//    }
}

template< typename T>
DynamicArray<T>& DynamicArray<T>::operator= (const DynamicArray<T>& obj)
{
    if(this != &obj)
    {
        T* array = copy(obj.m_array, obj.m_length, obj.m_length);

        update(array,obj.m_length);


//        T* newarray = new T[obj.m_length];
//        for(int i = 0 ; i<obj.m_length; ++i)
//        {
//            newarray[i] = obj.m_array[i];
//        }
//        T* temp = this->m_array;

//        this->m_array = newarray;
//        this->m_length = obj.m_length;

//        delete[] temp;
//    }
//    else
//    {
//        THROW_EXCEPTION(NoEnoughMemoryException,"DynamicArray no enough memory to create object...");
//    }
    }
    return *this;
}

template< typename T>
int DynamicArray<T>::length() const
{
    return this->m_length;
}

template< typename T>
void DynamicArray<T>::resize(int length)
{
    T* array = copy(this->m_array,m_length,length);
    update(array,length);

//    if(length != m_length)
//    {
//        T* newarray = new T[length];

//        if(newarray!= nullptr)
//        {
//            int size = (length < this->m_length) ? length : this->m_length;
//            for(int i =0; i<size; ++i)
//            {
//                newarray[i] = this->m_array[i];
//            }

//            T* temp = this->m_array;
//            this->m_array = newarray;
//            this->m_length = length;
//            delete[] temp;
//        }
//        else
//        {
//            THROW_EXCEPTION(NoEnoughMemoryException,"DynamicArray no enough memory to resize object...");
//        }

//    }
}

template< typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] this->m_array;
}

}


#endif // DYNAMICARRAY_H
