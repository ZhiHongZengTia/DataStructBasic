#ifndef STATICSTACK_H
#define STATICSTACK_H

#include "object.h"
#include "Stack/stackm.h"
#include "exception.h"

namespace DTLib {

template <typename T, int N>
class StaticStack: public StackM<T>
{
protected:
    T m_space[N];  // 栈存储空间
    int m_top;    // 栈顶标识
    int m_size;    // 当前栈大小
public:
    StaticStack();
    int capacity() const;
    void push(const T& e) override;
    void pop() override;
    T top() const override ;
    void clear() override ;
    int size() const override;
//    ~StaticStack();

};

template <typename T, int N>
StaticStack<T,N>::StaticStack()
{
    m_top = -1;
    m_size = 0;
}

template <typename T, int N>
int StaticStack<T,N>::capacity() const
{
    return N;
}

template <typename T, int N>
void StaticStack<T,N>::push(const T& e)
{
    if(m_size < N)
    {
        m_space[m_top+1] = e;
        m_top++;
        m_size++;
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"invalid operator exception, no space in current stack push()...");
    }

}

template <typename T, int N>
void StaticStack<T,N>::pop()
{
    if( m_size > 0)
    {
        m_top--;
        m_size--;
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"invalid operator exception, no space in current stack pop()...");
    }
}

template <typename T, int N>
T StaticStack<T,N>::top() const
{
    if( m_size > 0)
    {
        return m_space[m_top];
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"invalid operator exception, no space in current stack top()...");
    }
}

template <typename T, int N>
void StaticStack<T,N>::clear()
{
    m_top = -1;
    m_size = 0 ;
}

template <typename T, int N>
int StaticStack<T,N>::size() const
{
    return m_size;
}

//template <typename T, int N>
//StaticStack<T,N>::~StaticStack()
//{

//}

}




#endif // STATICSTACK_H
