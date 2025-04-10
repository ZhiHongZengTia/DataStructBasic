#ifndef LINKGRAPH_H
#define LINKGRAPH_H
#include "Graph/graph.h"
#include "LinkList/linklist.h"
#include "dynamicarray.h"

namespace DTLib
{
template <typename V, typename E>
class LinkGraph : public Graph<V,E>
{

protected:
    struct Vertex : public Object  // 顶点数据类型
    {
       V* data;   // 顶点数据元素
        LinkList<Edge<E>> edge;   // 邻接与该顶点的边
        Vertex()
        {
            data = nullptr;
        }
    };

    LinkList<Vertex*> m_list;

public:
    LinkGraph(unsigned int n = 0);

    int addVertex();
    int addVertex(const V& value);

    bool setVertex(int i, const V& value);
    V getVertex(int i);
    bool getVertex(int i,V& value);
    SharedPointer<ArrayM<int>> getAdjacent(int i) ;
    E getEdge(int i , int j) ;
    bool getEdge(int i, int j, E& value) ;
    bool setEdge(int i, int j, const E& value) ;
    bool removeEdge(int i, int j) ;
    int vCount();
    int eCount() ;
    int OD(int i) ;
    int ID(int i) ;

    void removeVertex();  // 删除最近增加的顶点

     virtual bool isAdjacent(int i, int j) override;  // 判断在当前图中顶点i到顶点j是否邻接

    ~LinkGraph();
};


template <typename V, typename E>
LinkGraph<V,E>::LinkGraph(unsigned int n )
{
    for(int i = 0; i< n; ++i)
    {
        addVertex();
    }
}

template <typename V, typename E>
int LinkGraph<V,E>::addVertex()
{
    int ret = -1;
    Vertex* v = new Vertex();
    if(v != nullptr)
    {
        m_list.insert(v);
        ret = m_list.length() -1;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException,"no memory to create new vertex object...");
    }

    return ret;
}

template <typename V, typename E>
int LinkGraph<V,E>::addVertex(const V& value)
{
    int ret = addVertex();
    if(ret >= 0)
    {
        setVertex(ret,value);
    }
    return ret;
}

template <typename V, typename E>
bool LinkGraph<V,E>::setVertex(int i, const V& value)
{
    bool ret = ( (0<=i) && (i<vCount()) );
    if(ret)
    {
        Vertex* vertex = m_list.get(i);
        V* data = vertex->data;
        if(data == nullptr)
        {
            data = new V();
        }
        if(data!= nullptr)
        {
            *data = value;
            vertex->data = data;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"no memory to create new vertex object...");
        }
    }
    return ret;
}


template <typename V, typename E>
V LinkGraph<V,E>::getVertex(int i)
{
    V ret;
    if( !getVertex(i,ret) )
    {
        THROW_EXCEPTION(InvalidParameterException,"index i is invalid...");
    }
    return ret;
}

template <typename V, typename E>
bool LinkGraph<V,E>::getVertex(int i,V& value)
{
   bool ret = ( (0<=i) && (i<vCount()) );
   if(ret)
   {
        Vertex* v = m_list.get(i);
        if(v->data != nullptr)
        {
            value = *(v->data);
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"no value assigned to this vertex...");
        }
   }
   return ret;
}



template <typename V, typename E>
void LinkGraph<V,E>::removeVertex()  // 删除最近增加的顶点
{
    if(m_list.length() > 0)
    {
        int index = m_list.length() - 1;
        Vertex* v = m_list.get(index);
        if(m_list.remove(index))
        {

            for(int i = (m_list.move(0) , 0); !m_list.end() ; i++, m_list.next())
            {
                int pos = m_list.current()->edge.find(Edge<E>(i,index));
                if(pos >= 0)
                {
                    m_list.current()->edge.remove(pos-1);
                }
            }
            delete v->data;
            delete v;
        }
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"no vertex in current graph...");
    }
}

template <typename V, typename E>
SharedPointer<ArrayM<int>> LinkGraph<V,E>::getAdjacent(int i)
{
    DynamicArray<int>* ret = nullptr;
    if(  (0<=i) && ( i<vCount()) )
    {
        Vertex* vertex = m_list.get(i);
        ret = new DynamicArray<int> (vertex->edge.length());
        if( ret != nullptr)
        {
            for( int k = (vertex->edge.move(0), 0); !vertex->edge.end(); ++k,vertex->edge.next() )
            {
                ret->set(k,vertex->edge.current().e);
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"no memory to create ret object...");
        }
    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException,"index i is invalid...");
    }
    return ret;
}

template <typename V, typename E>
E LinkGraph<V,E>::getEdge(int i , int j)
{
    E ret;
    if( !getEdge(i,j,ret) )
    {
        THROW_EXCEPTION(InvalidParameterException,"index i, j is invalid...");
    }
    return ret;
}

template <typename V, typename E>
bool LinkGraph<V,E>::getEdge(int i, int j, E& value)
{
    bool ret = ( ( i>= 0) && (i<vCount()) &&  \
                 (j >= 0) && (j<vCount())  );
    if(ret)
    {
        Vertex* vertex = m_list.get(i);
        int pos = vertex->edge.find(Edge<E>(i,j));
        if(pos > 0)
        {
//            if(i == j) value = 65535;
//            else
            value = vertex->edge.get(pos-1).data;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"no value assigned to this edge ...");
        }
    }
    return ret;
}


template <typename V, typename E>
bool LinkGraph<V,E>::setEdge(int i, int j, const E& value)
{

    bool ret = ( (0<= i) && (i<vCount()) &&  \
                 (0<= j) && (j<vCount()));
    if(ret)
    {
        Vertex* vertex = m_list.get(i);
        int pos = vertex->edge.find(Edge<E>(i,j));
        if(pos >= 0)
        {
            ret = vertex->edge.set(pos,Edge<E>(i,j,value));
        }
        else
        {
            ret = vertex->edge.insert(0,Edge<E>(i,j,value));
        }
    }
    return ret;
}


template <typename V, typename E>
bool LinkGraph<V,E>::removeEdge(int i, int j)
{
    bool ret = ( (0<= i) && (i<vCount()) &&  \
                 (0<= j) && (j<vCount()));
    if(ret)
    {
        Vertex* vertex = m_list.get(i);
        int pos = vertex->edge.find(Edge<E>(i,j));
        if(pos >= 0)
        {
            ret = vertex->edge.remove(pos-1);
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"cannot find the edget to be removed in LinkGraph<V,E>::removeEdge...");
        }
    }

    return ret;
}

template <typename V, typename E>
int LinkGraph<V,E>::vCount()
{
    return m_list.length();
}

template <typename V, typename E>
int LinkGraph<V,E>::eCount()
{
    int ret = 0;
    for(m_list.move(0); !m_list.end(); m_list.next())
    {
        ret+= m_list.current()->edge.length();
    }
    return ret;
}

template <typename V, typename E>
int LinkGraph<V,E>::OD(int i)
{
    int ret = 0;
    if ( ( 0<= i) && (i<vCount())  )
    {
        ret = m_list.get(i)->edge.length();
    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException,"index i is invalid in MatrixGraph<N,V,E>::OD...");
    }
    return ret;

}

template <typename V, typename E>
int LinkGraph<V,E>::ID(int i)
{
    int ret = 0;
    if ( ( 0<= i) && (i<vCount())  )
    {
        for(m_list.move(0); !m_list.end(); m_list.next())
        {
            LinkList<Edge<E>>& edge = m_list.current()->edge;
            for(edge.move(0); !edge.end(); edge.next())
            {
                if( edge.current().e == i)
                {
                    ret++;
                    break;
                }
            }
        }
    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException,"index i is invalid in MatrixGraph<N,V,E>::ID...");
    }
    return ret;
}

template <typename V, typename E>
LinkGraph<V,E>::~LinkGraph()
{
    while(m_list.length() > 0)
    {
        Vertex* toDel = m_list.get(0);
        m_list.remove(0);
        delete toDel->data;
        delete toDel;
    }
}

template <typename V, typename E>
 bool LinkGraph<V,E>::isAdjacent(int i, int j)   // 判断在当前图中顶点i到顶点j是否邻接
{

    return ( 0<=i ) && ( i<vCount()) && (0<=j) && (j<vCount())  && (i!=j) && (m_list.get(i)->edge.find(Edge<E>(i,j)) >= 0 );
}



}


#endif // LISTGRAPH_H
