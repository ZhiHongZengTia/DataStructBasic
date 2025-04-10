#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H


#include "object.h"
#include "Queue/queuem.h"
#include "LinkList/linklist.h"
#include "exception.h"

namespace DTLib
{

template<typename T >
class DynamicQueue : public Queue<T>
{

protected:
    DynamicQueue<T> m_list;   // 队列存储空间

public:

    LinkQueue();

    void add(const T& e) override;
    void remove() override;
    T front() const override;
    void clear() override;
    int length() const override;
};

template<typename T>
DynamicQueue<T>::DynamicQueue()
{


}


template<typename T>
void DynamicQueue<T>::add(const T& e)
{
    m_list.insert(e);
}

template<typename T>
void DynamicQueue<T>::remove()
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
T DynamicQueue<T>::front() const
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
void DynamicQueue<T>::clear()
{
    m_list.clear();

}

template<typename T>
int DynamicQueue<T>::length() const
{
    return m_list.length();
}


}



#endif // DYNAMICQUEUE_H
