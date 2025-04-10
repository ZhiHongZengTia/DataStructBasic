#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H


#include "object.h"
#include "LinkList/linklist.h"


namespace DTLib
{
template <typename T, int N>
class StaticLinkList : public LinkList<T>
{
  protected:
    typedef typename LinkList<T>::Node Node;
    struct SNode : public Node
    {
        void* operator new (long unsigned int size_t, void* loc)
        {
            (void)size_t;
            return loc;
        }
    };
    typedef typename StaticLinkList<T, N>::SNode SNode;

    unsigned char m_space[sizeof( SNode)* N];
    int m_used[N];

    void destory(Node* pn) override;
    SNode* create() override;

public:
    StaticLinkList();
    int capacity();

};

template <typename T, int N>
void StaticLinkList<T,N>::destory(Node* pn)
{
    SNode* space = reinterpret_cast<SNode*>(m_space);
    SNode* psn = dynamic_cast<SNode*>(pn);

    for(int i = 0; i<N; ++i)
    {
        if(psn == (space + i))
        {
            m_used[i] = 0;
            psn->~SNode();

        }
    }
}

template <typename T, int N>
 typename StaticLinkList<T,N>::SNode* StaticLinkList<T,N>::create()
{
    Node* ret = nullptr;
    for(int i = 0; i< N; ++i)
    {
        if(!m_used[i])
        {
            ret = reinterpret_cast<SNode*> (m_space) + i;
            ret = new(ret)SNode();
            m_used[i] = 1;
            break;
        }
    }

    return reinterpret_cast<SNode*>(ret);

}

template <typename T, int N>
StaticLinkList<T,N>::StaticLinkList()
{
    for(int i = 0 ; i <N; ++i)
    {
        m_used[i] = 0;
    }
}

template <typename T, int N>
int StaticLinkList<T,N>::capacity()
{
    return N;
}


}




#endif // STATICLINKLIST_H
