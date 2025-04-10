#ifndef GTREE_H
#define GTREE_H

#include "Object.h"
#include "Tree/tree.h"
#include "Tree/gtreenode.h"
#include "Queue/linkqueue.h"

namespace DTLib {

template <typename T>
class GTree : public Tree<T>
{

protected:
    GTreeNode<T>* find(GTreeNode<T>* node,const T& value) const;
    GTreeNode<T>* find(GTreeNode<T>* node, GTreeNode<T>* obj) const;

    void free(GTreeNode<T>* node);

    LinkQueue<GTreeNode<T>*> m_queue;

//    GTree(const GTree<T>&);
//    GTree<T>* operator= (const GTree<T>& );

    // 实现虚函数
public:
    GTree()
    {

    }

    virtual bool insert(TreeNode<T>* node ) ;
    virtual bool insert(const T& value, TreeNode<T>* parent) ;

    void remove(GTreeNode<T>* node, GTree<T>*& ret) ;  // ret 是一个指针的引用
    virtual SharedPointer<Tree<T> > remove(const T& value) ;
    virtual SharedPointer<Tree<T> > remove(TreeNode<T >* node) ;

     GTreeNode<T>* find(const T& value) const ;
     GTreeNode<T>* find(TreeNode<T>* node ) const ;

     GTreeNode<T>* root() const ;

     int degree(GTreeNode<T>* node) const;
     virtual int degree() const ;

     int count(GTreeNode<T>* node) const;
     virtual int count() const ;

     int height(GTreeNode<T>* node) const;
     virtual int height() const ;
     virtual void clear() ;
     ~GTree();

     virtual bool begin()
    {
         bool ret = ( root() != nullptr );
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
        bool ret = ( m_queue.length() > 0 );
        if(ret)
        {
            GTreeNode<T>* node = m_queue.front();
            m_queue.remove();
            for(node->child.move(0); !node->child.end(); node->child.next())
            {
                m_queue.add(node->child.current());
            }
        }
        return ret;
    }
    virtual T current()
    {
        if( !end() )
        {
            return m_queue.front()->value;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"no value at current postion...");
        }
    }


};

template <typename T>
bool GTree<T>::insert(TreeNode<T>* node )
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
            GTreeNode<T>* np = find(node->parent);
            if(np != nullptr)
            {
                GTreeNode<T>* n = dynamic_cast<GTreeNode<T>*>(node);
                if(np->child.find(n) < 0)
                {
                    np->child.insert(n);
                }
            }
            else
            {
                THROW_EXCEPTION(InvalidOperationException,"invalid parent tree node...");
            }
        }
    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException,"paramater node cannot be nullptr...");
    }
    return ret;
}

template <typename T>
bool GTree<T>::insert(const T& value, TreeNode<T>* parent)
{
    bool ret = true;
    GTreeNode<T>* node = GTreeNode<T>::NewNode();
    if(node != nullptr)
    {
        node->value = value;
        node->parent = parent;
        insert(node);
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException,"no enough memory to create tree node...");
    }
     return ret;
}

template <typename T>
void GTree<T>::remove(GTreeNode<T>* node, GTree<T>*& ret)   // ret 是一个指针的引用
{
    ret = new GTree<T>();
    if(ret!= nullptr)
    {
        if(root() == node)
        {
            this->m_root = nullptr;
        }
        else
        {
            LinkList<GTreeNode<T>*>& child = dynamic_cast<GTreeNode<T>*>(node->parent)->child;
            child.remove(child.find(node));
            node->parent = nullptr;
        }
        ret->m_root = node;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException,"no enough memory to create tree in remove...");
    }
}


template <typename T>
SharedPointer<Tree<T> > GTree<T>::remove(const T& value)
{
    GTree<T>* ret = nullptr;
    GTreeNode<T>* node = find(value);
    if(node != nullptr)
    {
        remove(node,ret);
        m_queue.clear();

    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException,"cannnot find the node via parameter value...");
    }
    return ret;
}

template <typename T>
SharedPointer<Tree<T> > GTree<T>::remove(TreeNode<T >* node)
{
    GTree<T>* ret = nullptr;
    node = find(node);
    if(node != nullptr)
    {
        remove(dynamic_cast<GTreeNode<T>*>(node),ret);
        m_queue.clear();
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"cannnot find the node via parameter node...");
    }
    return ret;
}

template <typename T>
GTreeNode<T>* GTree<T>::find(GTreeNode<T>* node,const T& value) const
{
    GTreeNode<T>* ret = nullptr;
    if(node != nullptr)
    {
        if(node->value == value)
        {
            return node;
        }
        else
        {
            for(node->child.move(0); (!node->child.end()) && (ret == nullptr); node->child.next())
            {
                ret = find(node->child.current(),value);
            }
        }
    }
    return ret;
}

template <typename T>
GTreeNode<T>* GTree<T>::find(const T& value) const
{
    return find(root(),value);
}



 template <typename T>
 GTreeNode<T>* GTree<T>::find(GTreeNode<T>* node,GTreeNode<T>* obj) const
 {
     GTreeNode<T>* ret = nullptr;
     if(node == obj)
     {
         return obj;
     }
     else
     {
         if(node != nullptr)
         {
             for(node->child.move(0); (!node->child.end())&& (ret == nullptr); node->child.next())
             {
                 ret = find(node->child.current(),obj);
             }
         }
     }
     return ret;
 }

template <typename T>
GTreeNode<T>* GTree<T>::find(TreeNode<T>* node ) const
{
     return find(root(),dynamic_cast<GTreeNode<T>*>(node));
}

template <typename T>
GTreeNode<T>* GTree<T>::root() const
{
     return dynamic_cast<GTreeNode<T>*>(this->m_root);
}

template <typename T>
int GTree<T>::degree(GTreeNode<T>* node) const
{
    int ret = 0;
    if(node!= nullptr)
    {
        ret = node->child.length();
        for(node->child.move(0);!node->child.end(); node->child.next())
        {
            int d = degree(node->child.current());
            if(ret < d)
            {
                ret =d;
            }
        }
    }
    return ret;
}

template <typename T>
int GTree<T>::degree() const
{
    return degree(root());
}

template <typename T>
int GTree<T>::count(GTreeNode<T>* node) const
{
    int ret = 0;
    if(node != nullptr)
    {
        ret = 1;
        for(node->child.move(0); !node->child.end(); node->child.next())
        {
            ret += count(node->child.current());
        }
    }
    return ret;
}


template <typename T>
int GTree<T>::count() const
{
    return count(root()) ;
}

template <typename T>
int GTree<T>::height(GTreeNode<T>* node) const
{
    int ret = 0;
    if(node != nullptr)
    {
        for(node->child.move(0); !node->child.end(); node->child.next())
        {
            int h = height(node->child.current());
            if(ret < h)
            {
                ret = h;
            }
        }
        ret += 1;
    }
    return ret;
}

template <typename T>
int GTree<T>::height() const
{
    return height(root());
}

template <typename T>
void GTree<T>::free(GTreeNode<T>* node)
{
    if(node != nullptr)
    {
        for(node->child.move(0);!node->child.end();node->child.next())
        {
            free(node->child.current());
        }
        if(node->flag())
        {
            delete node;
        }
        else
        {
            cout<<"donnot free node in stack, node.value="<<node->value<<endl;
        }
    }
}

template <typename T>
void GTree<T>::clear()
{
    free(root());
    this->m_root = nullptr;
    m_queue.clear();
}

template <typename T>
GTree<T>::~GTree()
{
    clear();
}


}


#endif // GTREE_H
