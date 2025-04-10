#ifndef BTREENODE_H
#define BTREENODE_H


#include "object.h"
#include "Tree/tree.h"
#include "BinaryTree/btreenode.h"
#include "exception.h"


namespace DTLib
{
template <typename T>
class BTreeNode : public TreeNode<T>
{
public:
    BTreeNode<T>* left;
    BTreeNode<T>* right;

    BTreeNode();
    static BTreeNode<T>* NewNode();
    // 工厂模式

};

template <typename T>
BTreeNode<T>::BTreeNode()
{
    left = nullptr;
    right = nullptr;
}


template <typename T>
 BTreeNode<T>* BTreeNode<T>::NewNode()
{
    BTreeNode<T>* ret = new BTreeNode<T>();
    if( ret != nullptr)
    {
        ret->m_flag = true;
    }
    return ret;
}


}


#endif // BTREENODE_H
