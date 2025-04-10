#ifndef LINKLIST_H
#define LINKLIST_H

#include "object.h"
#include "list.h"
#include "exception.h"
#include <iostream>
//#include "Pointer/smartpointer.h"


using namespace std;

namespace DTLib {

template <typename T>
class LinkList: public ListM<T>
{
protected:
        struct Node : public Object
        {
                T value;
                Node* next;
//                SmartPointer<Node> next;
        };
//        mutable Node m_header;
        mutable struct: public Object{
            char reserved[sizeof(T)];
            Node* next;
//            SmartPointer<Node> next;
        } m_header;
        int m_length;
        int m_step;
        Node* m_current;
//        SmartPointer<Node> m_current;


        virtual Node* create()
        {
            return new Node();
        }
        virtual void destory(Node* pn)
        {
            delete pn;
        }

public:
        LinkList();

         bool insert(const T& e) override;  // insert to tail
         bool insert(int i, const T& e) override;
         bool remove(int i) override;
         bool set(int i, const T& e) override ;
         bool get(int i, T& e) const  override;
         T get(int i) const;
         int length() const override;
         void clear() override;

         Node* position(int i) const
         {
//             SmartPointer<Node> ret = reinterpret_cast<Node *>(&this->m_header);
             Node* ret = reinterpret_cast<Node *>(&this->m_header);
             for(int p = 0 ; p< i; ++p)
             {
                 ret = ret->next;
             }
//             return ret.get();
             return ret;
         }

         int find(const T& e) const;

         bool move(int i, int step = 1);
         bool end();
         T current();
         bool next();

         ~LinkList();
};


//template <typename T>
// Node* LinkList<T>::position(int i) const
// {
//     Node* ret = &this->m_header;
//     for(int p = 0 ; p< i; ++p)
//     {
//         ret = ret->next;
//     }
//     return ret;
// }

template <typename T>
int LinkList<T>::find(const T& e) const
{
    int ret = -1;
    int i =0 ;
//    SmartPointer<Node> node = reinterpret_cast<Node *>(&this->m_header);
    Node* node = reinterpret_cast<Node *>(&(this->m_header));
//    while(node.isNull())
     while(node)
    {
        if(node->value == e)
        {
            ret = i;
            break;
        }
        else
        {
            node = node->next;
            i++;
        }
    }
    return ret;
}

template <typename T>
bool LinkList<T>::move(int i, int step)
{
    bool ret = ( (i>=0) && (i< m_length) && (step>0) );
    if(ret)
    {
        m_current = position(i)->next;
        m_step = step;
    }
    return ret;
}

template <typename T>
bool LinkList<T>::end()
{
    return (m_current == nullptr);
//    return m_current.isNull();
}

template <typename T>
T LinkList<T>::current()
{
    if( !end() )
    {
        return m_current->value;
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"invalid operation in T LinkList<T>::current() no value at current position...");
    }
}

template <typename T>
bool LinkList<T>::next()
{
    int i= 0;
    while( (i<m_step) && !end() )
    {
        m_current = m_current->next;
        i++;
    }
    return ( i == m_step);
}


template <typename T>
LinkList<T>::LinkList()
{
    m_header.next = nullptr;
    m_length = 0 ;
    m_step = 1;
    m_current = nullptr;
}

template <typename T>
 bool LinkList<T>::insert(const T& e)   // insert to tail
 {
    return insert(m_length,e);
 }

 template <typename T>
 bool LinkList<T>::insert(int i, const T& e)
 {
     bool ret= ( (0<=i) && (i<= m_length) );

     if(ret)
     {
         Node* node = create();
         if(node != nullptr)
         {
             Node* current = position(i);

             node->value = e;
             node->next = current->next;
             current->next = node;

             m_length++;
         }
         else
         {
             THROW_EXCEPTION(NoEnoughMemoryException,"no enough to  bool LinkList<T>::insert new element...");
         }
     }
     return ret;
 }

 template <typename T>
 bool LinkList<T>::remove(int i)
 {
    bool ret= ( (0<=i) && (i< m_length) );  // is <= or <

    if(ret)
    {
        Node* current = position(i);
//        SmartPointer<Node> current = position(i);

        Node* toDel = current->next;
//        SmartPointer<Node> toDel = current->next;
        current->next = toDel->next;

        m_length --;

        destory(toDel);
    }
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException,"index out of LinkList<T>::remove ...");
    }

    return ret;
 }

  template <typename T>
 bool LinkList<T>::set(int i, const T& e)
 {
     bool ret = ( (0<=i) && (i< m_length) );
     if(ret)
     {
         Node* current = position(i);

         current->next->value = e;
     }
     else
     {
         THROW_EXCEPTION(IndexOutOfBoundsException,"index out of LinkList<T>::remove ...");
     }

     return ret;
 }

 template <typename T>
 bool LinkList<T>::get(int i, T& e) const
 {
if(i==-1)
{
    cout<<endl<<"i="<<i<<",len:"<<m_length<<endl;
}
     bool ret= ( (0<=i) && (i< m_length) );
     if(ret)
     {
         Node* current = position(i);

         e =  current->next->value;
     }
     else
     {
         THROW_EXCEPTION(IndexOutOfBoundsException,"index out of LinkList<T>::get ...");
     }
     return ret;
 }


 template <typename T>
 T LinkList<T>::get(int i) const
 {
     T ret;
     if(get(i,ret))
     {
         return ret;
     }
     else
     {
         THROW_EXCEPTION(IndexOutOfBoundsException,"index out of LinkList<T>::get ...");
     }
     return ret;
 }

 template <typename T>
 int LinkList<T>::length() const
 {
    return m_length;
 }

 template <typename T>
 void LinkList<T>::clear()
 {
//     while(m_header.next.isNull())
    while( m_header.next )
    {
        Node* toDel = m_header.next;
//         SmartPointer<Node> toDel = m_header.next;
        m_header.next = toDel->next;

        m_length -- ;
        destory(toDel);
    }
 }

template <typename T>
LinkList<T>::~LinkList()
{
    clear();
}

}






#endif // LINKLIST_H
