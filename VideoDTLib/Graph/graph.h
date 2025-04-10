#ifndef GRAPH_H
#define GRAPH_H

#include "object.h"
#include "exception.h"
#include "Pointer/sharedpointer.h"
#include "arraym.h"
#include "dynamicarray.h"
#include "arraym.h"
#include "Queue/linkqueue.h"
#include "Stack/linkstack.h"
#include "Stack/staticstack.h"
#include "staticarray.h"


namespace DTLib
{

template <typename E>
struct Edge : public Object  // 边数据类型
{
    int b;   // 起始顶点
    int e;   // 邻接顶点
    E data;   // 权值
    Edge(int i = -1, int j = -1)
    {
        b = i;
        e = j;
    }
    Edge(int i,int j, const E& value)
    {
        b = i;
        e = j;
        data = value;
    }

    bool operator== (const Edge <E>& obj)
    {
        return ((b == obj.b) && ( e == obj.e));
    }
    bool operator!= (const Edge <E>& obj)
    {
        return !(*this == obj);
    }

};



template <typename V,typename E>
class Graph: public Object
{
public:
    virtual V getVertex(int i) = 0;
    virtual bool getVertex(int i, V& value) = 0;
    virtual bool setVertex(int i, const V& value) = 0;
    virtual SharedPointer<ArrayM<int>> getAdjacent(int i) = 0;
    virtual E getEdge(int i , int j) = 0;
    virtual bool getEdge(int i, int j, E& value) = 0;
    virtual bool setEdge(int i, int j, const E& value) = 0;
    virtual bool removeEdge(int i, int j) = 0;
    virtual int vCount() = 0;
    virtual int eCount() = 0;
    virtual int OD(int i) = 0;
    virtual int ID(int i) = 0;
    virtual int TD(int i)
    {
        return OD(i)+ID(i);
    }

    virtual bool isAdjacent(int i, int j) = 0;  // 判断在当前图中顶点i到顶点j是否邻接
    bool asUndirected()  // 判断当前的有向图是否能够看作无向图
    {
        bool ret = true;

        for(int i =0; i<vCount(); ++i)
        {
            cout<<"asUndirectedv  vCout"<<vCount()<<",i"<<i<<endl;
            for(int j = 1; j<vCount(); ++j)
            {

                if(isAdjacent(i,j))
                {
                    E testa ;
                    cout<<"j"<<j<<",i"<<i<<endl;
                    try
                    {
//                        testa = getEdge(i,j);

//                        testa = getEdge(j,i);
                        ret = ret && isAdjacent(j,i) && ( getEdge(i,j) == getEdge(j,i) );
                    }
                    catch(Exception& exp)
                    {
                        cout<<"222error,mes:"<<exp.message()<<",loc ="<<exp.location()<<endl;
                    }
                }
            }
        }
        return ret;
    }
    SharedPointer<ArrayM<Edge<E>>> Prim(const E& LIMIT, const bool MINIMUN = true)
    {
        LinkQueue<Edge<E>> ret;
        if(asUndirected())
        {
            DynamicArray<int> adjVex(vCount());
            DynamicArray<bool> mark(vCount());
            DynamicArray<E> cost(vCount());
            SharedPointer<ArrayM<int>> aj = nullptr;
            bool end = false;
            int v = 0;
            for(int i =0 ;i<vCount(); ++i)
            {
                adjVex[i] = -1;
                mark[i]  = false;
                cost[i] = LIMIT;
            }

            mark[v] = true;
            aj = getAdjacent(v);
            for(int j = 0; j<aj->length(); ++j)
            {
                cost[(*aj)[j]] = getEdge(v,(*aj)[j]);
                adjVex[(*aj)[j]] = v;
            }
            for(int i =0; (i<vCount() && !end ) ; ++i)
            {
                E m = LIMIT;
                int k = -1;
                for(int j = 0; j<vCount(); ++j)
                {
                    if( !mark[j] && ( MINIMUN?(cost[j] < m):(cost[j] > m) ) )
                    {
                        m= cost[j];
                        k = j;
                    }
                }
                end = (k == -1);
                if(!end)
                {
                    ret.add(Edge<E> (adjVex[k],k ,getEdge(adjVex[k],k) ));

                    mark[k] = true;

                    aj = getAdjacent(k);

                    for(int j = 0; j<aj->length(); ++j)
                    {
                        if( !mark[(*aj)[j]] && \
                                ( MINIMUN? (getEdge(k,(*aj)[j]) < cost[(*aj)[j]]):\
                                  (getEdge(k,(*aj)[j]) > cost[(*aj)[j]]) ) )
                        {
                            cost[(*aj)[j]] = getEdge(k,(*aj)[j]);
                            adjVex[(*aj)[j]] = k;

                        }
                    }
                }
            }





        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"Prim operation is for undirected graph only...");
        }
        if( ret.length() != (vCount() -1))
        {
            THROW_EXCEPTION(InvalidOperationException,"no enough for prim operation...");
        }
        return toArray(ret);
    }

    template <typename T>
    DynamicArray<T>* toArray(LinkQueue<T>& queue)
    {
        DynamicArray<T>* ret = new DynamicArray<T>(queue.length());
        if(ret != nullptr)
        {
            for(int i = 0; i<ret->length(); ++i)
            {
                ret->set(i,queue.front());
                queue.remove();
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"no memory to create ret object...");
        }
        return ret;
    }

    SharedPointer<ArrayM<int>> BFS(int i)
    {
        DynamicArray<int>* ret = nullptr;
        if( (i>=0) && (i<vCount()) )
        {
            LinkQueue<int > q;
            LinkQueue<int> r;
            DynamicArray<bool > visited(vCount());
            for(int i =0; i< vCount(); ++i)
            {
                visited[i] = false;
            }
            q.add(i);
            while(q.length() >0)
            {
                int v = q.front();
                q.remove();
                if(!visited[v])
                {
                    SharedPointer<ArrayM<int>> aj = getAdjacent(v);
                    for(int j = 0; j<aj->length(); ++j)
                    {
                        q.add((*aj)[j]);
                    }
                    r.add(v);
                    visited[v] = true;
                }
            }
            ret = toArray(r);
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException,"index i is invalid...");
        }
        return ret;
    }


    SharedPointer<ArrayM<int>> DFS(int i)
    {
        DynamicArray<int>* ret = nullptr;
        if( (i>=0) && (i<vCount()) )
        {
//            StaticStack<int,9> s;
            LinkStack<int> s;

            LinkQueue<int> r;
            DynamicArray<bool> visited(vCount());
            for(int j =0; j< vCount(); ++j)
            {
                visited[j] = false;
            }
            s.push(i);
            while(s.size()>0)
            {
                int v = s.top();
                s.pop();
                if( !visited[v] )
                {
                    SharedPointer<ArrayM<int>> aj = getAdjacent(v);
                    for(int j = aj->length() - 1; j>=0; j--)
                    {
                        s.push((*aj)[j]);
                    }
                    r.add(v);
                    visited[v] = true;
                }
            }
            ret = toArray(r);
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException,"index i is invalid...");
        }
        return ret;
    }

    SharedPointer<ArrayM<int>> dijkstra(int i, int j,const E& LIMIT)
    {
        LinkQueue<int > ret ;

        if( (i>= 0)&& (j>=0) && (i<vCount()) && (j< vCount()) )
        {
            DynamicArray<E> dist(vCount());
            DynamicArray<int> path(vCount());
            DynamicArray<bool> mark(vCount());
            for(int k = 0; k<vCount(); ++k)
            {
                mark[k] = false;
                path[k] = -1;
                dist[k] = isAdjacent(i,k)? ( path[k] =i, getEdge(i,k) ):LIMIT;
            }

            mark[i] = true;
            for(int k  =0; k<vCount(); ++k)
            {
                E m = LIMIT;
                int u = -1;
                for(int w = 0; w<vCount(); ++w)
                {
                    if( !mark[w] && (dist[w]<m) )
                    {
                        m = dist[w];
                        u = w;
                    }
                }
                if( u == -1)
                {
                    break;
                }
                mark[u] = true;
                for(int w = 0; w<vCount(); ++w)
                {
                    if( !mark[w] && isAdjacent(u,w) && (dist[u] + getEdge(u,w) < dist[w]) )
                    {
                        dist[w] = dist[u] + getEdge(u,w);
                        path[w] = w;
                    }
                }
            }
            LinkStack<int> s;
            s.push(j);
            for( int k = path[j]; k!=-1; k = path[k])
            {
                cout<<"k:"<<k<<",path k="<<path[k]<<endl;
                s.push(k);
            }
            while(s.size() > 0)
            {
                ret.add(s.top());
                s.pop();
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException,"index <i,j> is invalid...");
        }
        if(ret.length() < 2)
        {
            THROW_EXCEPTION(ArithmeticException,"there is no path from i to j...");
        }
        return toArray(ret);
    }


    int Floyd(int x, int y, const E& LIMIT)
    {
        int ret = -1;
        if( (x >=0) && (y>=0) && (x<vCount())  && (y<vCount())  )
        {
//            DynamicArray<DynamicArray<E> > dist(vCount());
//            for(int k =0; k<vCount(); ++k)
//            {
//                dist[k].resize(vCount());
//            }
            int dist[vCount()][vCount()];

            for(int i =0; i<vCount(); ++i)
            {
                for(int j =0; j<vCount(); ++j)
                {
                    dist[i][j] = isAdjacent(i,j)? getEdge(i,j) : LIMIT;
                }
            }
            for(int k = 0; k<vCount(); ++k)
            {
                for(int i =0; i<vCount(); ++i)
                {
                    for(int j =0; j<vCount(); ++j)
                    {
                        if( (dist[i][k]+dist[k][j]) < dist[i][j] )
                        {
                            dist[i][j] = dist[i][k]+dist[k][j];
                        }
                    }
                }
            }
            ret = dist[x][y];
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException,"index <x,y> is invalid");
        }
        return ret;
    }



};




}

#endif // GRAPH_H
