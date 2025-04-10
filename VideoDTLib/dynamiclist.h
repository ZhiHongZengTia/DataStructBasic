#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H


#include "seqlist.h"
#include <cstdlib>

namespace DTLib {

template <typename T>
class DynamicList : public SeqList<T>
{
protected:
    int m_capacity;  // 顺序存储空间的大小
public:
    DynamicList(int capacity);  // 申请空间
    int capacity() const;  // 重新设置存储空间的大小
    void resize(int capacity);  // 归还空间
    ~DynamicList();
};

template <typename T>
DynamicList<T>::DynamicList(int capacity)  // 申请空间
{
    this->m_array = new T[capacity];
    if(this->m_array!= NULL)
    {
        this->m_length = 0;
        this->m_capacity = capacity;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException,"no memory to create dynamicList object...");
    }
}

template <typename T>
int DynamicList<T>::capacity() const
{
    return m_capacity;
}// 重新设置存储空间的大小

template <typename T>
void DynamicList<T>::resize(int capacity)  // 归还空间
{
    if(capacity != m_capacity)
    {
        T* array = new T[capacity];
        if(array!= NULL)
        {
            int length = (this->m_length < capacity ? this->m_length: capacity);
            for(int i = 0; i<length; ++i)
            {
                array[i] = this->m_array[i];
            }
            T* temp = this->m_array;  // if delete this->m_array ; may recall xigou function( may case exception)
            this->m_array = array;
            this->m_length = length;
            this->m_capacity = capacity;
            delete[] temp;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"no memory to resize dynamicList object...");
        }
    }

}

template <typename T>
DynamicList<T>::~DynamicList()
{
    delete[] this->m_array;

}

}


#endif // DYNAMICLIST_H
