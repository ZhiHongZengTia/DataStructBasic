#ifndef SEQLIST_H
#define SEQLIST_H

#include "list.h"
#include "exception.h"

using namespace DTLib;

namespace DTLib {

template <typename T>
class SeqList : public ListM<T>
{
   protected:
    T* m_array;  // 顺序存储空间
    int m_length;  // 当前线性表长度
    public:
    SeqList(){}
    bool insert(const T& e);
    bool insert(int i, const T& e);
    bool remove(int i);
    bool set(int i, const T& e);
    bool get(int i, T& e) const ;
    int find(const T& e) const;
    int length() const;
    void clear();
    T& operator[] (int i);  // 【】数组访问方式
    T operator[] (int i) const;
    virtual int capacity() const = 0 ;	// 顺序存储空间的容量
};

template <typename T>
bool SeqList<T>::insert(const T& e)
{
    return insert(m_length,e);
//    bool ret =  (m_length < capacity());
//    if(ret)
//    {
//        m_array[m_length] = e;
//        m_length ++;
//    }
//    return ret;
}

template <typename T>
bool SeqList<T>::insert(int i, const T& e)
{
    bool ret = ( (0<=i) && (i<=m_length) );
    ret = ret && (m_length < capacity());
    if(ret)
    {
        for(int p = m_length-1; p>=i; p--)
        {
            m_array[p+1] = m_array[p];
        }
        m_array[i] = e;
        m_length ++;
    }
    return ret;
}

template <typename T>
 bool SeqList<T>::remove(int i)
 {
     bool ret = (i>=0) && (i<m_length) ;
    if( ret)
    {
        for(int p = i; p< m_length; p++)
        {
            m_array[p] = m_array[p+1];
        }
        m_length--;
    }
    return ret;
 }

 template <typename T>
 bool SeqList<T>::set(int i, const T& e)
 {
    bool ret = (i>=0) && (i<m_length) ;
    if(ret)
    {
        m_array[i] = e;
    }
    return ret;
 }

 template <typename T>
 bool SeqList<T>::get(int i, T& e) const
 {
    bool ret = (i>=0) && (i<m_length) ;
    if(ret)
    {
        e = m_array[i];
    }
    return ret;
 }

 template <typename T>
 int SeqList<T>::find(const T& e) const
 {
     for(int i=0; i<this->m_length; ++i)
     {
         if(e == m_array[i])
         {
             return i;    // 返回第一次出现的位置
         }
     }
     return -1;
 }

 template <typename T>
 int SeqList<T>::length() const
 {
    return m_length;
 }

 template <typename T>
 void SeqList<T>::clear()
 {
    m_length = 0 ;
 }

 template <typename T>
 T& SeqList<T>::operator[] (int i)  // 【】数组访问方式
 {
     bool ret = ((i>=0) && (i<m_length) );
     if(ret)
     {
         return m_array[i];
     }
     else
     {
         THROW_EXCEPTION(IndexOutOfBoundsException,"parameter i is invalid...");
     }
 }

 template <typename T>
 T SeqList<T>::operator[] (int i) const
 {
     return const_cast<SeqList<T>&> (*this)[i];
 }



}



#endif // SEQLIST_H
