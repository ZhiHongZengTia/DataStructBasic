#ifndef BTREE_H
#define BTREE_H

#include "object.h"
#include "Tree/tree.h"
#include "BinaryTree/btreenode.h"
#include "BinaryTree/btreenode.h"

#include "exception.h"
#include <iostream>
#include "dynamicarray.h"
#include "Queue/linkqueue.h"

namespace DTLib
{
enum BTNodePos
{
    ANY,LEFT,RIGHT
};

enum BTTraversal
{
    PreOrder,InOrder,PostOrder,LevelOrder
};



template <typename T>
class BTree: public Tree<T>
{
protected:
    virtual BTreeNode<T>* find(BTreeNode<T>* node,const T& value) const;
    virtual BTreeNode<T>* find(BTreeNode<T>* node, BTreeNode<T>* obj) const;

    virtual bool insert(BTreeNode<T>* node , BTreeNode<T>* nodeParent ,BTNodePos pos );
    virtual bool insert(TreeNode<T>* node,BTNodePos pos ) ;

    void remove(BTreeNode<T>* node, BTree<T>*& ret);


    virtual void free(BTreeNode<T>* node);

    virtual int count(BTreeNode<T>* node) const;
    virtual int height(BTreeNode<T>* node) const ;
    virtual int degree(BTreeNode<T>* node) const;

    LinkQueue<BTreeNode<T>*> m_queue;


    // 实现
public:
    BTree() { this->m_root = nullptr; }


    virtual bool insert(TreeNode<T>* node ) ;

    virtual bool insert(T value , TreeNode<T>* nodeParent ,BTNodePos pos );
    virtual bool insert(const T& value, TreeNode<T>* parent) ;

    virtual SharedPointer<Tree<T> > remove(const T& value) ;
    virtual SharedPointer<Tree<T> > remove(TreeNode<T >* node) ;


    virtual BTreeNode<T>* find(const T& value) const  ;
    virtual BTreeNode<T>* find(TreeNode<T>* node ) const ;
    virtual BTreeNode<T>* root() const ;
    virtual int degree() const ;
    virtual int count() const ;
    virtual int height() const ;
    virtual void clear() ;

    ~BTree();

    BTreeNode<T>* clone(BTreeNode<T>* node) const;
    SharedPointer<BTree<T>> clone() const;

    bool equal(BTreeNode<T>* lh,BTreeNode<T>* rh);
    bool operator ==(const BTree<T>& btree);
    bool operator !=(const BTree<T>& btree);


    BTreeNode<T>* add(BTreeNode<T>* lh, BTreeNode<T>* rh) const;
    SharedPointer<BTree<T>> add(const BTree<T>& btree) const;


    void traversal(BTTraversal order,LinkQueue<BTreeNode<T>*>& queue);  // 新增功能函数

    BTreeNode<T>* connect(LinkQueue<BTreeNode<T>*>& queue);
    BTreeNode<T>* thread(BTTraversal order);  // 新增公有函数


//    void inOrderThread(BTreeNode<T>* node , BTreeNode<T>* & head, BTreeNode<T>* & tail);
//    BTreeNode<T>* inOrderThread4(BTreeNode<T>* node );



    virtual bool begin()
    {
        bool ret = ( root() != nullptr);
        if(ret)
        {
            m_queue.clear();
            m_queue.add(root());
        }
        return ret;
    }
    virtual bool end()
    {
        return (m_queue.length() == 0);
    }
    virtual bool next()
    {
        bool ret = (m_queue.length() > 0);
        if(ret)
        {
            BTreeNode<T>* node = m_queue.front();
            m_queue.remove();
            if(node->left != nullptr)
            {
                m_queue.add(node->left);
            }
            if(node->right != nullptr)
            {
                m_queue.add(node->right);
            }
        }
        return ret;
    }
   virtual  T current()
    {
        if( ! end())
        {
            return m_queue.front()->value;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"no value at current postion...");
        }
    }


    SharedPointer<ArrayM<T>> traversal(BTTraversal order)
    {
        DynamicArray<T>* ret = nullptr;
        LinkQueue<BTreeNode<T>*> queue;

        traversal(order,queue);

        ret = new DynamicArray<T>(queue.length());
        if(ret != nullptr)
        {
            for(int i= 0; i<ret->length(); i++,queue.remove())
            {
                ret->set(i,queue.front()->value);
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"no memory to create return array...");
        }
        return ret;
    }
    void preOrderTraversal(BTreeNode<T>* node ,LinkQueue<BTreeNode<T>*>& queue)
    {
        if(node != nullptr)
        {
            queue.add(node);
            preOrderTraversal(node->left, queue);
            preOrderTraversal(node->right, queue);
        }
    }
    void inOrderTraversal(BTreeNode<T>* node ,LinkQueue<BTreeNode<T>*>& queue)
    {
        if(node != nullptr)
        {
            inOrderTraversal(node->left, queue);
            queue.add(node);
            inOrderTraversal(node->right, queue);
        }
    }
    void postOrderTraversal(BTreeNode<T>* node ,LinkQueue<BTreeNode<T>*>& queue)
    {
        if(node != nullptr)
        {
            postOrderTraversal(node->left, queue);
            postOrderTraversal(node->right, queue);
            queue.add(node);
        }
    }
    void levelOrderTraversal(BTreeNode<T>* node ,LinkQueue<BTreeNode<T>*>& queue)
    {
        if(node != nullptr)
        {
            LinkQueue<BTreeNode<T>*> temp;
            temp.add(root());
            while(temp.length() > 0)
            {
                BTreeNode<T>* current = temp.front();
                if(current->left != nullptr)
                {
                    temp.add(current->left);
                }
                if(current->right != nullptr)
                {
                    temp.add(current->right);
                }
                temp.remove();
                queue.add(current);
            }
        }
    }



};

template <typename T>
 bool BTree<T>::insert(BTreeNode<T>* node , BTreeNode<T>* nodeParent ,BTNodePos pos )
{
    bool ret = true;
    if( pos  == ANY)
    {
        if(nodeParent->left == nullptr)
        {
            nodeParent->left = node;
        }
        else if(nodeParent->right == nullptr)
        {
            nodeParent->right = node;
        }
        else
        {
            ret = false;
        }

    }
    else if(pos == LEFT)
    {
        if(nodeParent->left == nullptr)
        {
            nodeParent->left = node;
        }
        else
        {
            ret = false;
        }
    }
    else if(pos == RIGHT)
    {
        if(nodeParent->right == nullptr)
        {
            nodeParent->right = node;
        }
        else
        {
            ret = false;
        }
    }
    return ret;
}

 template <typename T>
 bool BTree<T>::insert(TreeNode<T>* node,BTNodePos pos )
 {
     bool ret = true;
     if(node != nullptr)
     {
         if(this->m_root == nullptr)
         {
             node->parent = nullptr;
             this->m_root = node;
         }
         else
         {
             BTreeNode<T>* np = find(node->parent);
             if(np!= nullptr)
             {
                 ret = insert(dynamic_cast<BTreeNode<T>*>(node),np,pos);
             }
             else
             {
                 THROW_EXCEPTION(InvalidParameterException,"invalid parent tree node...");
             }
         }
     }
     else
     {
         THROW_EXCEPTION(InvalidParameterException,"parameter node cannot be nullptr...");
     }
     return ret;
 }


template <typename T>
bool BTree<T>::insert(TreeNode<T>* node )
{
    return insert(node,ANY);
}

template <typename T>
 bool BTree<T>::insert(T value , TreeNode<T>* nodeParent ,BTNodePos pos )
{
    int ret = true;
    BTreeNode<T>* node = BTreeNode<T>::NewNode();
    if(node != nullptr)
    {
        node->value = value;
        node->parent = nodeParent;
        ret = insert(node,pos);
        if(!ret)
        {
            delete node;
        }
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException,"no memory to create new node in BTree<T>::insert(T value , TreeNode<T>* nodeParent ,BTNodePos pos)...");
    }
    return ret;
}


template <typename T>
 bool BTree<T>::insert(const T& value, TreeNode<T>* parent)
 {
     return insert(value,parent,ANY);
 }

 template <typename T>
 void BTree<T>::remove(BTreeNode<T>* node, BTree<T>*& ret)
 {
    ret = new BTree<T>();
    if(ret == nullptr)
    {
        THROW_EXCEPTION(NoEnoughMemoryException,"no memory to create new tree");
    }
    else
    {
        if(root() == node)
        {
            this->m_root = nullptr;
        }
        else
        {
            BTreeNode<T>* parent = dynamic_cast<BTreeNode<T>*>(node->parent);
            if(parent->left == node)
            {
                parent->left =nullptr;
            }
            else if(parent->right == node)
            {
                parent->right =nullptr;
            }
            node->parent = nullptr;

        }
        ret->m_root = node;
    }
 }


template <typename T>
 SharedPointer<Tree<T>> BTree<T>::remove(const T& value)
 {
     BTree<T>* ret = nullptr;
     BTreeNode<T>* node = find(value);

     if( node == nullptr)
     {
         THROW_EXCEPTION(InvalidParameterException,"cannot find the tree node via value...");
     }
     else
     {
         remove(node,ret);
         m_queue.clear();
     }
     return ret;
 }


template <typename T>
 SharedPointer<Tree<T>> BTree<T>::remove(TreeNode<T >* node)
 {
     BTree<T>* ret = nullptr;
     node = find(node);
     if( node == nullptr )
     {
         THROW_EXCEPTION(InvalidParameterException,"parameter node is invalid...");
     }
     else
     {
        remove(dynamic_cast<BTreeNode<T>*>(node),ret);
        m_queue.clear();
     }
     return ret;
 }


 template <typename T>
 BTreeNode<T>* BTree<T>::find(BTreeNode<T>* node,const T& value) const
 {
     BTreeNode<T>* ret = nullptr;
     if(node != nullptr)
     {
         if(node->value == value)
         {
             ret =  node;
         }
         else
         {
            if(ret == nullptr)
            {
                ret = find(node->left,value);
            }
            if(ret == nullptr)
            {
                ret = find(node->right,value);
            }
         }
     }
     return ret;
 }

template <typename T>
 BTreeNode<T>* BTree<T>::find(const T& value) const
 {
    return find(root(),value);
 }


 template <typename T>
 BTreeNode<T>* BTree<T>::find(BTreeNode<T>* node,BTreeNode<T>* obj) const
 {
     BTreeNode<T>* ret = nullptr;
     if(node == obj)
     {
         ret = obj;
     }
     else
     {
         if(node != nullptr)
         {
            if( ret == nullptr)
            {
                ret = find(node->left,obj);
            }
            if(ret == nullptr)
            {
                ret = find(node->right,obj);
            }
         }
     }
     return ret;
 }

template <typename T>
 BTreeNode<T>* BTree<T>::find(TreeNode<T>* node ) const
 {
    return find(root(),dynamic_cast<BTreeNode<T>*>(node));
 }

template <typename T>
 BTreeNode<T>* BTree<T>::root() const
 {
    return dynamic_cast<BTreeNode<T>*>(this->m_root);
 }

 template <typename T>
  int BTree<T>::degree(BTreeNode<T>* node) const
 {
     int ret = 0;
     if(node != nullptr)
     {
         ret = (!!node->left) +(!!node->right);

         BTreeNode<T>* child[] = {node->left,node->right};

         for(int i=0; (i<2) && (ret<2); ++i)
         {
             int d1 = degree(child[i]);
             if(ret < d1)
             {
                 ret = d1;
             }
         }


//         int d1 = degree(node->left);
//         int d2 = degree(node->right);
//         ret = (!!node->left) +(!!node->right);
//         if(ret < d1)
//         {
//             ret = d1;
//         }
//          if(ret <d2)
//          {
//              ret = d2;
//          }
     }
     return ret;
 }

template <typename T>
 int BTree<T>::degree() const
 {
    return degree(root());
 }


 template <typename T>
  int BTree<T>::count(BTreeNode<T>* node) const
 {
     return (node == nullptr)? 0 : (count(node->left) + count(node->right) +1);
 }


template <typename T>
 int BTree<T>::count() const
 {
     return count(root());

 }

 template <typename T>
  int BTree<T>::height(BTreeNode<T>* node) const
 {
    int ret = 0;
    if(node != nullptr)
    {
        int h1 = height(node->left);
        int h2 = height(node->right);
        ret = (h1>h2)?h1:h2;
        ret += 1;

    }
    return ret;
 }


template <typename T>
 int BTree<T>::height() const
 {
     return height(root());

 }

 template <typename T>
  void BTree<T>::free(BTreeNode<T>* node)
{
    if(node != nullptr)
    {
        free(node->left);
        free(node->right);
        if(node->flag())
        {
            delete node;
        }
    }
}

template <typename T>
 void BTree<T>::clear()
{
     free(root());
    this->m_root = nullptr;
     m_queue.clear();
}

 template <typename T>
BTree<T>::~BTree()
 {
    clear();
 }

template <typename T>
BTreeNode<T>* BTree<T>::clone(BTreeNode<T>* node) const
{
    BTreeNode<T>* ret = nullptr;
    if(node != nullptr)
    {
        ret = BTreeNode<T>::NewNode();
        if(ret != nullptr)
        {
            ret->value = node->value;
            ret->left = clone(node->left);
            ret->right = clone(node->right);
            if(ret->left != nullptr)
            {
                ret->left->parent = ret;
            }
            if(ret->right != nullptr)
            {
                ret->right->parent = ret;
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"NO memory to clone...");
        }
    }
    return ret;
}


 template <typename T>
SharedPointer<BTree<T>> BTree<T>::clone() const
{
    BTree<T>* ret = new BTree<T>();
    if(ret != nullptr)
    {
        ret->m_root = clone(root());
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException,"NO memory to clone...");
    }
    return ret;
}


template <typename T>
bool BTree<T>::equal(BTreeNode<T>* lh,BTreeNode<T>* rh)
{
    bool ret = false;
    if(lh == rh)
    {
        ret = true;
    }
    else if( (lh!= nullptr)&& (rh != nullptr) )
    {
        ret =  ( (lh->value == rh->value) && (equal(lh->left,rh->left)) && (equal(lh->right, rh->right)) );
    }
    else
    {
        ret = false;
    }
    return ret;
}

template <typename T>
bool BTree<T>::operator ==(const BTree<T>& btree)
{
    return equal(this->root(),btree.root());
}

template <typename T>
bool BTree<T>::operator !=(const BTree<T>& btree)
{
    return !( (*this) == btree );
}

template <typename T>
BTreeNode<T>* BTree<T>::add(BTreeNode<T>* lh, BTreeNode<T>* rh) const
{
    BTreeNode<T>* ret = nullptr;
    if( lh == nullptr && rh != nullptr)
    {
        ret = clone(rh);
    }
    else if( lh != nullptr && rh == nullptr)
    {
        ret = clone(lh);;
    }
    else if( lh != nullptr && rh != nullptr)
    {
        ret = BTreeNode<T>::NewNode();
        if(ret != nullptr)
        {
            ret->value = lh->value + rh->value;
            ret->left = add(lh->left,rh->left);
            ret->right = add(lh->right,rh->right);
            if(ret->left != nullptr)
            {
                ret->left->parent = ret;
            }
            if(ret->right != nullptr)
            {
                ret->right->parent = ret;
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"no memory to create new tree");
        }
    }

    return ret;
}


template <typename T>
SharedPointer<BTree<T>> BTree<T>::add(const BTree<T>& btree) const
{
    BTree<T>* ret = new BTree<T>();
    if(ret != nullptr)
    {
        ret->m_root = add(root(),btree.root());
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException,"no memory to create new tree");
    }
    return ret;
}


template <typename T>
void BTree<T>::traversal(BTTraversal order,LinkQueue<BTreeNode<T>*>& queue)  // 新增功能函数
{
    switch(order)
    {
    case PreOrder:
        preOrderTraversal(root(),queue);
        break;
    case InOrder:
        inOrderTraversal(root(),queue);
        break;
    case PostOrder:
        postOrderTraversal(root(),queue);
        break;
    case LevelOrder:
        levelOrderTraversal(root(),queue);
        break;
    default:
        THROW_EXCEPTION(InvalidParameterException,"PARAMETER order is invalid...");
        break;
    }
}

template <typename T>
BTreeNode<T>* BTree<T>::connect(LinkQueue<BTreeNode<T>*>& queue)
{
    BTreeNode<T>* ret = nullptr;

    if(queue.length() > 0)
    {
        ret = queue.front();

        BTreeNode<T>* slider = nullptr;
        slider = queue.front();
        queue.remove();
        slider->left = nullptr;
        while(queue.length() >0 )
        {
            slider->right = queue.front();
            queue.front()->left = slider;
            slider = queue.front();
            queue.remove();
        }
        slider->right = nullptr;
    }
    return ret;
}

template <typename T>
BTreeNode<T>* BTree<T>::thread(BTTraversal order)  // 新增公有函数
{
    BTreeNode<T>* ret = nullptr;
    LinkQueue<BTreeNode<T>*> queue;
    traversal(order,queue);
    ret = connect(queue);
    this->m_root = nullptr;
    m_queue.clear();
    return ret;
}




}


#endif // BTREE_H
