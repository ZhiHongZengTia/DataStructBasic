#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include "object.h"
#include "Queue/queuem.h"
#include "LinkList/linklist.h"
#include "exception.h"

namespace DTLib
{

template<typename T >
class LinkQueue : public Queue<T>
{

protected:
    LinkList<T> m_list;   // 队列存储空间

public:

    LinkQueue();

    void add(const T& e) override;
    void remove() override;
    T front() const override;
    void clear() override;
    int length() const override;
};

template<typename T>
LinkQueue<T>::LinkQueue()
{


}


template<typename T>
void LinkQueue<T>::add(const T& e)
{
    m_list.insert(e);
}

template<typename T>
void LinkQueue<T>::remove()
{
    if(m_list.length()  > 0)
    {
        m_list.remove(0);
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"NO element in current linkqueue remove...");
    }
}

template<typename T>
T LinkQueue<T>::front() const
{
    if(m_list.length() > 0)
    {
        return m_list.get(0);
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"NO element in current linkqueue front...");
    }
}

template<typename T>
void LinkQueue<T>::clear()
{
    m_list.clear();

}

template<typename T>
int LinkQueue<T>::length() const
{
    return m_list.length();
}


}


#endif // LINKQUEUE_H
