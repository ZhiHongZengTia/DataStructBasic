#ifndef GTREENODE_H
#define GTREENODE_H

#include "Object.h"
#include "LinkList/linklist.h"
#include "Tree/treenode.h"
#include "exception.h"


namespace DTLib {

template <typename T>
class GTreeNode : public TreeNode<T>
{
    protected:
//        bool m_flag;
//        void* operator new(long unsigned int size) throw();

//        GTreeNode(GTreeNode<T>&);
//        GTreeNode<T>& operator= (const GTreeNode<T>&);

    public:
        LinkList<GTreeNode<T>*> child;
        GTreeNode();
//        bool flag();
        static GTreeNode<T>* NewNode();

};

template <typename T>
 GTreeNode<T>::GTreeNode()
 {
//     m_flag = false;
 }

// template <typename T>
// void*  GTreeNode<T>::operator new(long unsigned int size) throw()
// {
//     return Object::operator new(size);
// }

//  template <typename T>
// bool GTreeNode<T>::flag()
// {
//     return m_flag;
// }


 template <typename T>
  GTreeNode<T>* GTreeNode<T>::NewNode()
 {
     GTreeNode<T>* ret = new GTreeNode<T>();
     if( ret != nullptr)
     {
         ret->m_flag = true;
     }
     return ret;
 }



}


#endif // GTREENODE_H
