//#include "matrixgraph.h"


//namespace DTLib {


////template <int N, typename V, typename E>
////MatrixGraph<N,V,E>::MatrixGraph()
////{
////    for(int i = 0 ; i<vCount(); ++i)
////    {
////        m_vertexes[i] = nullptr;
////        for(int j = 0 ; i<vCount(); ++j)
////        {
////            m_edges[i][j] = nullptr;
////        }
////    }
////    m_eCount = 0;
////}

//template <int N, typename V, typename E>
// V MatrixGraph<N,V,E>::getVertex(int i)
//{
//    V ret;
//    if( !getVertex(i,ret))
//    {
//        THROW_EXCEPTION(InvalidParameterException,"index i is invalid...");
//    }
//    return ret;
//}

//template <int N, typename V, typename E>
// bool MatrixGraph<N,V,E>::getVertex(int i, V& value)
// {
//    bool ret = ( 0<= i && (i<vCount()) );
//    if(ret)
//    {
//        if(m_vertexes[i] != nullptr)
//        {
//            value = *(m_vertexes[i]);
//        }
//        else
//        {
//            THROW_EXCEPTION(InvalidOperationException,"no value assigned to this vertex ...");
//        }
//    }
//    return ret;
// }

//template <int N, typename V, typename E>
// bool MatrixGraph<N,V,E>::setVertex(int i, const V& value)
// {
//     bool ret = ( 0<= i && (i<vCount()) );
//     if(ret)
//     {
//         V* data = m_vertexes[i];  // for exception security
//         if(data == nullptr)
//         {
//             data = new V();
//         }
//         if(data != nullptr)
//         {
//            *(data) = value;
//             m_vertexes[i] = data;   // for exception security
//         }
//         else
//         {
//             THROW_EXCEPTION(NoEnoughMemoryException,"no memory to store new vertex value ...");
//         }
//     }
//     return ret;
// }

//template <int N, typename V, typename E>
// SharedPointer<ArrayM<int>> MatrixGraph<N,V,E>::getAdjacent(int i)
// {
//    DynamicArray<int>* ret = nullptr;
//    if( ( 0<= i) && (i<vCount())  )
//    {
//        int n = 0;
//        for(int j =0 ; j<vCount(); ++j)
//        {
//            if(m_edges[i][j] != nullptr)
//            {
//                n++;
//            }
//        }
//        ret = new DynamicArray<int>*(n);
//        if(ret != nullptr)
//        {

//            for(int j = 0, k=0; j<vCount(); ++j)
//            {
//                if(m_edges[i][j] != nullptr)
//                {
//                    ret->set(k++,j);
//                }
//            }
//        }

//        else
//        {
//            THROW_EXCEPTION(NoEnoughMemoryException,"no memory to create ret object...");
//        }
//    }
//    else
//    {
//        THROW_EXCEPTION(InvalidParameterException,"index i is invalid...");
//    }
//    return ret;
// }


//template <int N, typename V, typename E>
// E MatrixGraph<N,V,E>::getEdge(int i , int j)
// {
//    E ret;
//    if( !getEdge(i,j,ret) )
//    {
//        THROW_EXCEPTION(InvalidParameterException,"index i, j is invalid...");
//    }
//    return ret;
// }

//template <int N, typename V, typename E>
// bool MatrixGraph<N,V,E>::getEdge(int i, int j, E& value)
// {
//     bool ret = ( (0<= i) && (i<vCount()) &&  \
//                  (0<= j) && (j<vCount()));
//     if(ret)
//     {
//         if(m_edges[i][j] != nullptr)
//         {
//             value = *(m_edges[i][j]);
//         }
//         else
//         {
//             THROW_EXCEPTION(InvalidOperationException,"no value assigned to this edge ...");
//         }
//     }
//     return ret;
// }

//template <int N, typename V, typename E>
// bool MatrixGraph<N,V,E>::setEdge(int i, int j, const E& value)
// {
//     bool ret = ( (0<= i) && (i<vCount()) &&  \
//                  (0<= j) && (j<vCount()));
//     if(ret)
//     {
//         E* data = m_edges[i][j];  // for exception security
//         if(data == nullptr)
//         {
//             data = new E();
//         }
//         if(data != nullptr)
//         {
//            *(data) = value;
//             m_edges[i][j] = data;   // for exception security
//             m_eCount++;
//         }
//         else
//         {
//             THROW_EXCEPTION(NoEnoughMemoryException,"no memory to store new edge value ...");
//         }
//     }
//     return ret;
// }


//template <int N, typename V, typename E>
// bool MatrixGraph<N,V,E>::removeEdge(int i, int j)
//{
//     bool ret = ( (0<= i) && (i<vCount()) &&  \
//                  (0<= j) && (j<vCount()));
//     if(ret)
//     {
//         E* toDel = m_edges[i][j];
//         m_edges[i][j] = nullptr;
//         if(toDel != nullptr)
//         {
//             m_eCount--;
//             delete toDel;
//         }
//     }


//    return ret;
//}

//template <int N, typename V, typename E>
// int MatrixGraph<N,V,E>::vCount()
//{
//    return N;
// }

//template <int N, typename V, typename E>
// int MatrixGraph<N,V,E>::eCount()
//{
//    return m_eCount;
// }

//template <int N, typename V, typename E>
// int MatrixGraph<N,V,E>::OD(int i)
//{
//    int ret = 0;
//    if ( ( 0<= i) && (i<vCount())  )
//    {
//        for(int j = 0; j<vCount(); ++j)
//        {
//            if(m_edges[i][j] != nullptr )
//            {
//                ret ++;
//            }
//        }
//    }
//    else
//    {
//        THROW_EXCEPTION(InvalidParameterException,"index i is invalid in MatrixGraph<N,V,E>::OD...");
//    }
//    return ret;
// }


//template <int N, typename V, typename E>
// int MatrixGraph<N,V,E>::ID(int i)
//{
//     int ret = 0;
//     if ( ( 0<= i) && (i<vCount())  )
//     {
//         for(int j = 0; j<vCount(); ++j)
//         {
//             if(m_edges[j][i] != nullptr )
//             {
//                 ret ++;
//             }
//         }
//     }
//     else
//     {
//         THROW_EXCEPTION(InvalidParameterException,"index i is invalid in MatrixGraph<N,V,E>::ID...");
//     }
//     return ret;
// }




////template <int N, typename V, typename E>
////MatrixGraph<N,V,E>::~MatrixGraph()
////{
////    for(int i = 0 ; i<vCount(); ++i)
////    {
////        delete m_vertexes[i];
////        for(int j = 0 ; i<vCount(); ++j)
////        {
////            delete m_edges[i][j];
////        }
////    }
////}

//}
