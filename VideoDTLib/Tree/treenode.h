#ifndef TREENODE_H
#define TREENODE_H

#include "object.h"

namespace DTLib
{
template <typename T>
class TreeNode: public Object
{
protected:
    bool m_flag;
    void* operator new(long unsigned int size) throw();

    TreeNode(TreeNode<T>&);
    TreeNode<T>& operator= (const TreeNode<T>&);

public:

    bool flag();
    T value;
    TreeNode<T>* parent;
    TreeNode()
    {
        m_flag = false;
        parent = nullptr;
    }
    virtual ~TreeNode() = 0;  // 抽象类
};

template <typename T>

 TreeNode<T>::~TreeNode(){

 }

 template <typename T>
 void*   TreeNode<T>::operator new(long unsigned int size) throw()
 {
     return Object::operator new(size);
 }

 template <typename T>
bool TreeNode<T>::flag()
{
    return m_flag;
}

}



#endif // TREENODE_H
