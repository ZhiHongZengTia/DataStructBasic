#ifndef LINKSTACK_H
#define LINKSTACK_H


#include "object.h"
#include "LinkList/linklist.h"
#include "exception.h"
#include "Stack/stackm.h"

namespace DTLib {

template <typename T>
class LinkStack: public StackM<T>
{
protected:
    LinkList<T> m_list;
public:
    void push(const T& e) override;
    void pop() override;
    T top() const override ;
    void clear() override ;
    int size() const override;

};

template <typename T>
void LinkStack<T>::push(const T& e)
{
    m_list.insert(0,e);
}

template <typename T>
void LinkStack<T>::pop()
{
    if(m_list.length() > 0)
    {
        m_list.remove(0);
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"invalid operator exception, no space in current link stack pop()...");
    }
}

template <typename T>
T LinkStack<T>::top() const
{
    if(m_list.length() > 0)
    {
        return m_list.get(0);
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"invalid operator exception, no space in current link stack top()...");
    }
}

template <typename T>
void LinkStack<T>::clear()
{
    m_list.clear();
}

template <typename T>
int LinkStack<T>::size() const
{
    return m_list.length();
}

}


#endif // LINKSTACK_H
