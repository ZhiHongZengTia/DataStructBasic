#ifndef STATICQUEUE_H
#define STATICQUEUE_H

#include "object.h"
#include "Queue/queuem.h"
#include "exception.h"


namespace DTLib {

template <typename T , int N>
class StaticQueue : public Queue<T>
{

protected:
    T m_space[N];  // 队列存储空间
    int m_front;  // 队列顶标识
    int m_rear;   //  队列尾标识
    int m_length;  // 当前长度

public:
    StaticQueue();
    int capacity() const;

    void add(const T& e) override;
    void remove() override;
    T front() const override;
    void clear() override;
    int length() const override;
};


template <typename T , int N>
StaticQueue<T,N>::StaticQueue()
{
    m_front = 0;
    m_rear = 0;
    m_length = 0;
}

template <typename T , int N>
int StaticQueue<T,N>::capacity() const
{
    return N;
}

template <typename T , int N>
void StaticQueue<T,N>::add(const T& e)
{
    if(m_length < N)
    {
        m_space[m_rear] = e;
        m_rear = (m_rear+1)%N;
        m_length ++;
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"NO space in current queue add...");
    }
}

template <typename T , int N>
void StaticQueue<T,N>::remove()
{
    if(m_length > 0)
    {
        m_front = (m_front+1);
        m_length -- ;
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"NO element in current queue remove...");
    }
}

template <typename T , int N>
T StaticQueue<T,N>::front() const
{
    if(m_length > 0)
    {
        return m_space[m_front];
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"NO element in current queue front...");
    }
}

template <typename T , int N>
void StaticQueue<T,N>::clear()
{
    m_front = 0;
    m_rear = 0;
    m_length = 0;
}

template <typename T , int N>
int StaticQueue<T,N>::length() const
{
    return m_length;
}


}


#endif // STATICQUEUE_H
