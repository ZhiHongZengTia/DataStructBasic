#include <iostream>
#include "Pointer/smartpointer.h"
#include "exception.h"
#include "object.h"
#include "list.h"
#include "seqlist.h"
#include "staticlist.h"
#include "dynamiclist.h"
#include "arraym.h"
#include "staticarray.h"
#include "dynamicarray.h"
#include "LinkList/linklist.h"
#include "Pointer/pointer.h"
#include "Pointer/smartpointer.h"
#include "Pointer/sharedpointer.h"
#include "LinkList/staticlinklist.h"
#include "Stack/staticstack.h"
#include "Stack/linkstack.h"


#include "Queue/staticqueue.h"
#include "Queue/linkqueue.h"

#include "String/stringm.h"

#include "Sort/sortm.h"
#include <ctime>

#include "Tree/tree.h"
#include "Tree/gtree.h"
#include "BinaryTree/btree.h"


#include "Graph/graph.h"
#include "Graph/matrixgraph.h"
#include "Graph/linkgraph.h"

using namespace std;
using namespace DTLib;


class Test1: public Object
{
public:
    int i;
    int j;
};
class child:public Test1
{
public:
    int k;
};

class Test
{
public:
    Test(){cout<<"test"<<endl; }
    ~Test(){ cout<<"~Test"<<endl; }
};



void TestSeqList();
void TestStaticList();  void Test2StaticList();
void TestDynamicList();  void Test2DynamicList();

void TestStaticArray();
void TestDynamicArray();

void TestLinkList();  void TestStaticLinkList();

void TestLesson24();

void TestSmartPointer();  void TestSharedPointer();

void TestVideo26_2();

void TestVideo34StaticStack();  void TestVideo35LinkStack();   void TestVideo35LinkStackApplication();

void TestVideo36_2StaticQueue();  void TestVideo37LinkQueue();

void TestVideo38_1StackApplication();  void TestVideo38_2StackApplication();

void TestVideo39_4StringM();

void TestVideo43_1();  void TestVideo44_2();


void TestVideo46_2compare();

void TestVideo47_1SelectSort();   void TestVideo47_2InsertSort();   void TestVideo47_3BubbleSort();
void TestVideo48_2ShellSort();     void TestVideo49_2MergeSort();   void TestVideo49_3QuickSort();
void TestVideo50SortForArray();   void TestVideo50_2SortForComplex();


void TestVideo51Tree();  void TestVideo56TreeRemove();

void TestVideo62TwoTree();  void TestVideo68_1BTreeClone();
void TestVideo70_1BTreeQue();  void TestVideo70_3BTreeQue();  void TestVideo70_4BTreeQue();


void TestVideo71Graph();  void TestVideo73ListGraph();

void TestVideo74GraphSearch();

void TestVideo76Prim();

void TestVideo78Dijkstra();   void TestVideo79Floyd();

void TestVideo80_2();

int main(int argc, char *argv[])
{

//    TestLinkList();
    TestVideo80_2();


//    TestDynamicArray();

//TestDynamicList();

//    Test2DynamicList();
//    Test2StaticList();
//    TestDynamicList();


//    SmartPointer<Test> sp = new Test();
//    SmartPointer<Test> sp2 ;
//    sp2 = sp;
////    sp2++;
//    cout<<"sp:"<<(sp.get())<<",isnull"<<sp.isNull()<<",sp2:"<<(sp2.get())<<",isnull"<<sp2.isNull();

//    cout << "Hello World!" << endl;


//    try{ throw "cc"; cout<<"throw cc"<<endl; }
//    catch(int i){  cout<<"catch i = "<<i;  }
//    catch(double d){  cout<<"catch d = "<<d;  }
//    catch(char c){  cout<<"catch c = "<<c;  }
//    catch(char* pc){  cout<<"catch *pc = "<<*pc;  }
//    catch(const char* cpc){  cout<<"const catch *cpc = "<<*cpc;  } // 异常处理匹配成功



//    try{
//        throw ArithmeticException("test",__FILE__,__LINE__);
//    }
//    catch(const Exception & e)
//    {
//        cout<<"\n\ncatch exception,message:"<<e.message()<<endl;
//        cout<<"location:"<<e.location()<<endl;
//    }



//    try{
//        THROW_EXCEPTION(ArithmeticException,"ArithmeticException error");
//    }

//    catch(const Exception & e)
//    {
//        cout<<"\n\ncatch exception,message:"<<e.message()<<endl;
//        cout<<"location:"<<e.location()<<endl;
//    }
//    catch(const ArithmeticException & e)
//    {
//        cout<<"\n\ncatch ArithmeticException,message:"<<e.message()<<endl;
//        cout<<"location:"<<e.location()<<endl;
//    }

//    cout<<endl;
//    Object* obj1 = new Test1();
//    Object* obj2 = new child();
//    cout<<"obj1:"<<obj1<<endl;
//    cout<<"obj2:"<<obj2<<endl;
//    delete obj1;
//    delete obj2;



//    cout<<endl<<endl;
//    try
//    {
//        throw NoEnoughMemoryException("no enough",__FILE__,__LINE__);
//    }
//    catch(const NoEnoughMemoryException& e)
//    {
//        cout<<"NoEnoughMemoryException error, mess:"<<e.message()<<endl;
//    }

//    SmartPointer<int> p = new int();
//    cout<<&p<<", *p:= "<<*p<<", get"<<p.get();
//    delete p.get();


//    cout<<endl<<endl;

//    InvalidOperationException* inf = new InvalidOperationException();
//    delete inf;

    return 0;
}


void TestSeqList()
{
    SeqList<int>* l = nullptr;
    l->insert(1);
}


void TestStaticList()
{
    StaticList<int, 5> li;
    for(int i = 0 ; i<li.capacity(); i++)
    {
        li.insert(0,i);
    }
    li[0] *= li[0];
    cout<<"capacity:"<<li.capacity()<<endl;


    try
    {
        li[4] = 9;
        li[5] = 88;
         li[6] = 9;
//         li[4] = 99;
    }
    catch(const Exception& e)
    {
        cout<<"error, message:"<<e.message()<<e.location()<<endl;
    }

    for(int i = 0  ; i<li.capacity(); ++i)
    {
        cout<<"i:"<<i<<"="<<(li[i])<<", ";
    }
}

void Test2StaticList()
{
//    StaticList<int*, 5> list1;
//    StaticList<int*, 5> list2;

//    for(int i = 0 ; i<list1.capacity(); ++i)
//    {
//        list1.insert(0,new int(i));
//    }
//    list2 = list1;
//    for(int i = 0; i<list1.length(); ++i)
//    {
//        delete list1[i];
//        delete list2[i];
//    }
}


void TestDynamicList()
{
    DynamicList<int> li(5);
    for(int i = 0 ; i<li.capacity(); i++)
    {
        li.insert(i);
    }
    for(int i = 0  ; i<li.length(); ++i)
    {
        cout<<"i:"<<i<<"="<<(li[i])<<", ";
    }
    cout<<endl;
    li[0] *= li[0];
    cout<<"capacity:"<<li.capacity()<<",length:"<<li.length()<<endl;


    try
    {
        li[4] = 9;
        li[5] = 88;
         li[6] = 9;
//         li[4] = 99;
    }
    catch(const Exception& e)
    {
        cout<<"error, message:"<<e.message()<<e.location()<<endl;
        li.resize(10);
        li.insert(5,55);
    }

    cout<<"capacity:"<<li.capacity()<<",length:"<<li.length()<<endl;

    li.insert(6,44);
    li.insert(0,2222);

    cout<<"capacity:"<<li.capacity()<<",length:"<<li.length()<<endl;

    for(int i = 0  ; i<li.length(); ++i)
    {
        cout<<"i:"<<i<<"="<<(li[i])<<", ";
    }
    li.resize(3);
    cout<<"\nafter resize\n";
    for(int i = 0  ; i<li.length(); ++i)
    {
        cout<<"i:"<<i<<"="<<(li[i])<<", ";
    }
}

void Test2DynamicList()
{
//    DynamicList<int> list1(5);
//    DynamicList<int>  list2 = list1;

//    for(int i = 0 ; i<list1.capacity(); i++)
//    {
//        list1.insert(0,i);
//        list2.insert(0,i*i);
//    }

//    cout<<"capacity:"<<list1.capacity()<<",length:"<<list1.length()<<endl;


//    for(int i = 0  ; i<list1.length(); ++i)
//    {

//        cout<<"i:"<<i<<",list1="<<(list1[i])<<", list2 = "<<list2[i]<<", ";
//        cout<<"addr list1:"<<&list1[i]<<" , list2"<<&list2[i]<<endl;
//    }
}


void TestStaticArray()
{
    cout<<"\n~~~~~test begin\n";
    StaticArray<int, 5> array1;
    for(int i = 0 ; i<array1.length(); ++i)
    {
        array1[i] = i*i;
    }
    for(int i = 0 ; i<array1.length(); ++i)
    {
        cout<<"i["<<i<<"], ="<<array1[i]<<",addr:"<<&array1[i]<<"\n";
    }

    StaticArray<int ,5> array2;
    array2 = array1;
    for(int i = 0 ; i<array1.length(); ++i)
    {
        cout<<"i["<<i<<"], ="<<array2[i]<<",addr:"<<&array2[i]<<"\n";
    }

    try
    {
        array2[6] = 100;
    }
    catch(Exception& e)
    {
        cout<<"error,mess:"<<e.message()<<",line:"<<e.location();
    }

    cout<<"\n~~~~~test End\n";
}



void TestDynamicArray()
{

    cout<<"\n~~~~~TestDynamicArray begin\n";
    DynamicArray<int> array1(5);
    for(int i = 0 ; i<array1.length(); ++i)
    {
        array1[i] = i*i;
    }
    for(int i = 0 ; i<array1.length(); ++i)
    {
        cout<<"i["<<i<<"], ="<<array1[i]<<",addr:"<<&array1[i]<<"\n";
    }

    DynamicArray<int > array2(10);

    array2 = array1;

    for(int i = 0 ; i<array2.length(); ++i)
    {
        cout<<"i["<<i<<"], ="<<array2[i]<<",addr:"<<&array2[i]<<"\n";
    }
    array2.resize(9);

    for(int i = 0 ; i<array2.length(); ++i)
    {
        cout<<"after resize ,i["<<i<<"], ="<<array2[i]<<",addr:"<<&array2[i]<<"\n";
    }

//    array2[22] = 100;
    try
    {
        array2[22] = 100;
    }
    catch(Exception& e)
    {
        cout<<"error,mess:"<<e.message()<<",line:"<<e.location();
    }



    cout<<"\n~~~~~TestDynamicArray End\n";
}


void TestLinkList()
{
    cout<<"\n~~~~~TestLinkList begin \n";
    LinkList<int> list1;
    for(int i =0; i<5; i++)
    {
        list1.insert(0,i);
//        list1.set(i,i);
    }
    for(int i =0; i<list1.length(); ++i)
    {
        cout<<"list["<<i<<"],="<<list1.get(i)<<endl;
    }


    list1.remove(2);
    list1.set(2,2222);
//    list1.clear();

    for(int i =0; i<list1.length(); ++i)
    {
        cout<<"after remove list["<<i<<"],="<<list1.get(i)<<endl;
    }


    cout<<"\n~~~~~~test stage 2\n";
    cout<<"find 9,result:"<<list1.find(4)<<endl;


     class Test3: public Object
     {
         int val =1;
     public:
         Test3(int v = 0) {  val = v; }
         bool operator== (const Test3& obj) {
            return (val == obj.val);
         }
     };

     LinkList<Test3> list2;
     try
     {
         Test3 t;
         LinkList<Test3> list2;
     }
     catch(int i)
     {
         cout<<"error, :"<<i<<endl;
     }

     cout<<"\n~~~~~~test stage 3\n";

     Test3 t1(1) ,t2(2) ,t3(3);
     LinkList<Test3> list3;
     list3.insert( t1);
     list3.insert( t3);
     list3.insert( t2);

     cout<<"find 9,result:"<<list3.find(t2)<<endl;
     cout<<"find t1:"<<list3.find(t1)<<endl;


    cout<<"\n~~~~~TestLinkList End\n";

}

void TestStaticLinkList()
{
    cout<<"\n~~~~~TestStaticLinkList begin \n";

    StaticLinkList<int,5> list1;
    for(int i = 0 ; i<1; ++i)
    {
        list1.insert(i*i);
    }

//    try
//    {
//        list1.insert(666);
//    }
//    catch(const Exception& e)
//    {
//        cout<<e.message()<<",loc="<<e.location()<<endl;
//    }


//    for(list1.move(0,1); !list1.end(); list1.next())  // O(n)
//    {
//        cout<<"list1.current"<<list1.current()<<endl;
//    }


    cout<<"\n~~~~~TestStaticLinkList End\n";
}



void TestLesson24()
{
    cout<<"\n~~~~~TestLesson24 begin \n";

    LinkList<int> list1;
    for(int i = 0 ; i<5; ++i)
    {
        list1.insert(i*i);
    }


//    for(int i = 0 ; i<list1.length();++i)
//    {
//        cout<<"["<<i<<"] = "<<list1.get(i)<<endl;
//    }

    for(list1.move(0,1); !list1.end(); list1.next())  // O(n)
    {
        cout<<"list1.current"<<list1.current()<<endl;
    }


    cout<<"\n~~~~~TestLesson24 End\n";
}


void TestVideo26_1()
{
    cout<<"\n~~~~~TestVideo26_1 begin \n";

    try
    {
//        IndexOutOfBoundsException npe("ok",__FILE__,__LINE__);
        IndexOutOfBoundsException npe;
        cout<<"throw"<<endl;
        throw npe;
    }
    catch(const Exception& e)
    {
        cout<<"catch:"<<endl;
    }
    cout<<"\n~~~~~TestVideo26_1 End\n";
}


void TestVideo26_2()
{
    cout<<"\n~~~~~TestVideo26_1 begin \n";

    class Test3: public Object
    {
        int val =1;

    public:
        Test3(int v = 0) {  val = v; }
        bool operator== (const Test3& obj) {
           return (val == obj.val);
        }
        ~Test3()
        {
            if(val == 1)
            {
                throw val;
            }
        }
    };

    LinkList<Test3> list;
    Test3 t0(1), t1(1), t2(2);

    try
    {
        list.insert(t0);
        list.insert(t1);
        list.insert(t2);
        list.remove(1);
    }
    catch(int e)
    {
        cout<<"catch1:"<<(int)e<<endl;
        cout<<"catch:"<<list.length()<<endl;
    }
    cout<<"\n~~~~~TestVideo26_1 End\n";
}


void TestSmartPointer()
{
    class Test4
    {
    public:
        Test4() {  cout<< "~Test4"<<endl; }
        ~Test4() {  cout<< "~Test4"<<endl; }
    };
    SmartPointer<Test4> sp1 =  new Test4();
    SmartPointer<Test4> sp2;
    sp2 = sp1;
}

void TestSharedPointer()
{
    cout<<"\n~~~~~TestSharedPointer begin \n";
    class Test4
    {
    public:
        int value;
        Test4(int v=10) { value = v;  cout<< "~Test4"<<endl; }
        ~Test4() {  cout<< "~Test4"<<endl; }
    };
    const SharedPointer<Test4> sp1 =  new Test4(666);
    SharedPointer<Test4> sp2;
//    SharedPointer<Test4> sp3 = nullptr;
//    sp2 = sp1;
//    sp3 = sp2;

//    sp1->value = 100;

    const SmartPointer<Test4> sp5 =  new Test4();
//    sp5->value = 9000;
//    sp5=sp1;


    cout<<"sp1.value:"<<sp1->value<<", sp5:"<<sp5->value<<endl;

    cout<<"\n~~~~~TestSharedPointer End\n";
}

void TestVideo34StaticStack()
{
    cout<<"\n~~~~~TestVideo34StaticStack begin \n";

    StaticStack<int, 5> sta1;
    try{ sta1.pop();}
    catch(const Exception& e)
    {
        cout<<"error, mes:"<<e.message();
    }
    for(int i = 0 ; i<5 ; ++i)
    {
        sta1.push(i*i);
    }
    for(int i = 0 ; i<5; ++i)
    {
        cout<<"top:"<<sta1.top()<<endl;
//        cout<<"["<<i<<"]="<<(sta1.top())<<endl;
        sta1.pop();
    }

    cout<<"~~~~~~stage 2"<<endl;

    class Test3: public Object
    {
    public:
        Test3() {  cout<<"test3"<<endl; }

        ~Test3()
        {
            cout<<"~test3"<<endl;
        }
    };
    StaticStack<Test3,10> sta2;
    cout<<sta2.size()<<endl;


    cout<<"\n~~~~~TestVideo34StaticStack End\n";
}


void TestVideo35LinkStack()
{
    cout<<"\n~~~~~TestVideo34StaticStack begin \n";
    LinkStack<int> sta1;
    try{ sta1.pop();}
    catch(const Exception& e)
    {
        cout<<"error, mes:"<<e.message();
    }
    for(int i = 0 ; i<5 ; ++i)
    {
        sta1.push(i*i);
    }
    for(int i = 0 ; i<5; ++i)
    {
        cout<<"top:"<<sta1.top()<<endl;
//        cout<<"["<<i<<"]="<<(sta1.top())<<endl;
        sta1.pop();
    }

    cout<<"\n~~~~~TestVideo34StaticStack End\n";
}

//------------------ TestVideo35LinkStackApplication ------------------------------------//
bool is_left(char c)
{
    return ((c  == '[') || (c  == '(') || (c  == '{') || (c  == '<'));
}
bool is_right(char c)
{
    return ((c  == ']') || (c  ==')') || (c  == '}') || (c  == '>'));
}
bool is_quot(char c)
{
    return ( (c== '\'')|| (c == '\"') );
}

bool is_match(char c1, char c2)
{
    return (   ((c1 == '(') &&  (c2 == ')'))  \
               || ((c1 == '{') && (c2 == '}') ) \
               || ((c1 == '<') && (c2 == '>') )  \
               || ((c1 == '[') && (c2 == ']') )  \
               || ((c1 == '\'') && (c2 == '\'') )  \
               || ((c1 == '\"') && (c2 == '\"') )  \
               );
}
bool scan(const char* s)
{
    LinkStack<char> stack1;
    int i = 0;
    bool ret = true;
    s = (s==nullptr)?"":s;
    while(ret && (s[i] != '\0') )
    {
        if(is_left(s[i]))
        {
            stack1.push(s[i]);
        }
        else if(is_right(s[i]))
        {
            if( (stack1.size()>0) && is_match(stack1.top(),s[i]))
            {
                stack1.pop();
            }
            else
            {
                ret = false;
            }
        }
        else if(is_quot(s[i]))
        {
            if( (stack1.size() == 0) || (!is_match(s[i],stack1.top())) )
            {
                stack1.push(s[i]);
            }
            else if(is_match(s[i],stack1.top()))
            {
                stack1.pop();
            }
        }
        i++;

    }
//    if(ret && (stack1.size() == 0) )
//    {
//        ret = true;
//    }
    if(stack1.size() )
    {
        ret = false;
    }
    return ret;
}

void TestVideo35LinkStackApplication()
{
    cout<<"\n~~~~~TestVideo35LinkStackApplication begin\n";
    char* str1 = "template <typename T> \n \
            class LinkStack: public StackM<T> \n \
    {   \n \
            protected:  \n \
            LinkList<T> m_list;  \n \
            public:  \n \
            void push(const T& e) override;  \n \
            void pop[[]] override;  \n \
            T top() const override ;  \n \
            void clear() override ;  \n \
            int size() const override;   \n \
};";
    if(scan(str1))
    {
        cout<<"TestVideo35LinkStackApplication success!"<<endl;
    }
    else
    {
        cout<<"TestVideo35LinkStackApplication failed!"<<endl;
    }
    cout<<"\n~~~~~TestVideo35LinkStackApplication End\n";

}

void TestVideo36_2StaticQueue()
{
    cout<<"\n~~~~~TestVideo35LinkStackApplication begin\n";
    StaticQueue<int , 5> queue1;
    for(int i = 0; i< 5; ++i)
    {
        queue1.add(i*i);
    }

    int i = 0;
    while(queue1.length() > 0)
    {
        cout<<"["<<i++<<"]="<<queue1.front()<<endl;
        queue1.remove();
    }
    cout<<"\n~~~~~TestVideo35LinkStackApplication End\n";
}

void TestVideo37LinkQueue()
{
    cout<<"\n~~~~~TestVideo35LinkStackApplication begin\n";
    LinkQueue<int > queue1;
    for(int i = 0; i< 10; ++i)
    {
        queue1.add(i*i);
    }

    int i = 0;
    while(queue1.length() > 0)
    {
        cout<<"["<<i++<<"]="<<queue1.front()<<endl;
        queue1.remove();
    }
    cout<<"\n~~~~~TestVideo35LinkStackApplication End\n";
}



namespace DTLib {

template <typename T>
class StackToQueue: public Queue<T>
{
protected:
    mutable LinkStack<T> m_stack_in;
    mutable LinkStack<T> m_stack_out;


public:

    void add(const T& e)
    {
        m_stack_in.push(e);
    }
    virtual void remove()
    {
        if( m_stack_out.size() == 0 )
        {
            while(m_stack_in.size() > 0)
            {
                m_stack_out.push(m_stack_in.top());
                m_stack_in.pop();
            }
        }
        if(m_stack_out.size() > 0)
        {
            m_stack_out.pop();
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"NO space in current StackToQueue remove...");
        }
    }
//    T front() const override;
     T front() const override
    {
        if( m_stack_out.size() == 0 )
        {
            while(m_stack_in.size() > 0)
            {
                m_stack_out.push(m_stack_in.top());
                m_stack_in.pop();
            }
        }
        if(m_stack_out.size() > 0)
        {
            return m_stack_out.top();  // T LinkStack<T>::top() const
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"NO element in current StackToQueue front...");
        }
    }
    virtual void clear()
    {
        m_stack_in.clear();
        m_stack_out.clear();
    }
    virtual int length() const
    {
        return m_stack_in.size() + m_stack_out.size();
    }
};
}

void TestVideo38_1StackApplication()
{
    cout<<"\n~~~~~TestVideo35LinkStackApplication begin\n";
    StackToQueue<int> sq;
    for(int i = 0; i < 3; ++i)
    {
        sq.add(i*i);
    }
    while(sq.length() > 0 )
    {
        cout<<"["<<"]"<<sq.front()<<endl;
        sq.remove();
    }
    cout<<"\n~~~~~TestVideo35LinkStackApplication End\n";
}


namespace DTLib {

template <typename T>
class QueueToStack: public StackM<T>
{
protected:
     LinkQueue<T> m_link_1;
     LinkQueue<T> m_link_2;
     LinkQueue<T>* m_pIn;
     LinkQueue<T>* m_pOut;


public:
QueueToStack()
{
    m_pIn = &m_link_1;
    m_pOut = &m_link_2;
}

virtual void push(const T& e)
{
    m_pIn->add(e);
}

void move() const
{
    int n = m_pIn->length();
    for(int i = 0; i<n-1; i++)
    {
        m_pOut->add(m_pIn->front());
        m_pIn->remove();
    }
}

virtual void pop()
{
    if(m_pIn->length() > 0)
    {
        move();
        m_pIn->remove();

        LinkQueue<T>* temp = nullptr;
        temp = m_pIn;
        m_pIn = m_pOut;
        m_pOut = temp;
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"NO element in current QueueToStack pop...");
    }
}

virtual T top() const
{
    if(m_pIn->length() > 0)
    {
        move();
        return m_pIn->front();

//        m_pOut->add(m_pIn->front());
//        m_pIn->remove();

//        LinkQueue<T>* temp = m_pIn;
//        m_pIn = m_pIn;
//        m_pOut = temp;
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"NO element in current QueueToStack pop...");
    }
}

virtual void clear()
{
    m_link_1.clear();
    m_link_2.clear();
}

virtual int size() const
{
    return m_link_1.length() + m_link_2.length();
}

};
}

void TestVideo38_2StackApplication()
{
    cout<<"\n~~~~~TestVideo38_2StackApplication begin\n";
    QueueToStack<int> sq;
    for(int i = 0; i < 3; ++i)
    {
        sq.push(i*i);
    }
    while(sq.size() > 0 )
    {
        cout<<"["<<"]="<<sq.top()<<endl;
        sq.pop();
    }
    cout<<"\n~~~~~TestVideo38_2StackApplication End\n";
}

void TestVideo39_4StringM()
{
    cout<<"\n~~~~~TestVideo38_2StackApplication begin\n";
    StringM s;
    s = 'c';
    cout<<"s="<<s.str()<<",s.len:"<<s.length()<<endl;
    cout<<"s==c "<<(s=='c')<<endl;
    cout<<"s>d " <<(s>'d')<<endl;
    cout<<"s>abczzz " <<(s>"abczzz")<<endl;

    cout<<"\nstage 2\n";

    s += " hello";
    cout<<"s="<<s.str()<<",s.len:"<<s.length()<<endl;
    s = s+ " world";
    cout<<"s="<<s.str()<<",s.len:"<<s.length()<<endl;
    s = s+'c';
    cout<<"s="<<s.str()<<",s.len:"<<s.length()<<endl;

    cout<<"=="<< (s == "c hello worldc");
    cout<<"\nstage 3\n";

    StringM a[] = { "Efgldg", "D", "C", "B", "A" };
    StringM min = a[0];
    for(int i = 0 ; i< 5; ++i)
    {
        if( min > a[i])
        {
            min = a[i];
        }
    }
    cout<<"min="<<min.str()<<endl;
    for(int i = 0 ; i<5; ++i)
    {
        cout<<"["<<i<<"]="<<a[i].str()<<",len="<<a[i].length()<<endl;
    }

    cout<<"\nstage 3\n";
    for(int i = 0 ; i<a[0].length(); ++i)
    {
        cout<<"["<<i<<"]="<<a[0][i]<<",len="<<a[i].length()<<endl;
    }

    cout<<"\nstage 4\n";
    cout<<"is start with EF"<<a[0].startWith("Ef")<<endl;
    cout<<"is start with EFa"<<a[0].startWith("Efa")<<endl;
    cout<<"is end with dg"<<a[0].endOf("dg")<<endl;
    cout<<"is end with Efgldg"<<a[0].endOf("Efgldg")<<endl;


     cout<<"\nstage 5\n";
     a[0].insert(0,"zzh, ");
     cout<<a[0].str()<<endl;
     a[0].insert(5,"555, ");
     cout<<a[0].str()<<endl;

     cout<<"\nstage 5\n";
     StringM test5 = "   123  ";
//     test5.trim();
//     cout<<"test.trim:"<<test5.str()<<",len="<<test5.length()<<endl;

     cout<<test5.trim().insert(0,'i').startWith("i12")<<"end";
     cout<<"test5="<<test5.str()<<endl;



    cout<<"\n~~~~~TestVideo38_2StackApplication End\n";
}

unsigned int sum(unsigned int n)
{
    if(n>1)
    {
        return n + sum(n-1);
    }
    else
    {
        return 1;
    }
}
unsigned int fac(unsigned int n)
{
    if(n>2)
    {
        return fac(n-1)+fac(n-2);
    }
    if( 2== n  || 1== n)
    {return 1;}
    return 0 ;
}
unsigned int strlenM(const char* s)
{
//    if(*s != '\0' )
//    {
//        return 1+ strlen(s+1);
//    }
//    else
//    {
//        return 0;
//    }
//    return s ? ( (*s =='\0')? 0: (1+strlen(s+1)) ) : 0;
    return s ? ( (*s ) ? (1+strlen(s+1)) :0  ) : 0;
}
void TestVideo43_1()
{
    for(int i = 1 ; i<11; ++i)
    {
        cout<<"["<<i<<"]="<<fac(i)<<endl;
    }
    cout<<"str len = "<<strlenM("ABCDdefghijk")<<endl;
//        cout<<"1+2+...+100="<<sum(100)<<endl;
}

void HanoiTower(int n, char a, char b, char c)  // a:source, b:destination , c:tool
{
    if( n == 1)
    {
        cout<<a<<"-->"<<c<<endl;
    }
    else
    {
        HanoiTower(n-1,a,c,b);
        HanoiTower(1,a,b,c);
        HanoiTower(n-1,b,a,c);
    }
}
 void TestVideo44_2()
 {
    HanoiTower(3,'A','B','C');

 }






namespace DTLib
{
struct TestVideo46_2: public Object
{
    int key1;
    int key2;
    TestVideo46_2(int k1, int k2):key1(k1),key2(k2){}
    bool operator== (const TestVideo46_2& t)
    {
        return ( (key1== t.key1)&& (key2 == t.key2) );
    }
    bool operator!= (const TestVideo46_2& t)
    {
        return !(*this == t);
    }
    bool operator < (const TestVideo46_2& t)
    {
        return ( (key1<t.key1)||( (key1==t.key1) &&(key2<t.key2)) );  // key1 的比较优先级更高
    }
    bool operator>= (const TestVideo46_2& t)
    {
        return (!(*this< t) );
    }
    bool operator > (const TestVideo46_2& t)
    {
        return ( (key1>t.key1)||( (key1==t.key1) &&(key2>t.key2)) );  // key1 的比较优先级更高
    }
    bool operator<= (const TestVideo46_2& t)
    {
        return (!(*this> t));
    }
};
}

void TestVideo46_2compare()
{
    TestVideo46_2 t1(3,5);
    TestVideo46_2  t2(33,33);
    cout<<"1:"<<(t1<t2)<<endl;
    TestVideo46_2 t3(3,5);
    cout<<"1:"<<(t1<t3)<<endl;
    TestVideo46_2 t4(3,1);
    cout<<"1:"<< (t1<t4)<<endl;
    TestVideo46_2 t5(1,1);
    cout<<"1:"<<(t1<t5)<<endl;
}

void TestVideo47_1SelectSort()
{
    cout<<"\n~~~~~TestVideo47_1SelectSort begin\n";
    int arr[] = { 3, 4, 12, 444, 22, 555, 2223,1};
    int len = sizeof(arr)/sizeof(int);
    SortM::SelectSort(arr,len,false);
    for(int i = 0; i<len; ++i)
    {
        cout<<"i:"<<arr[i]<<endl;
    }
    cout<<"\n~~~~~TestVideo47_1SelectSort End\n";
}


void TestVideo47_2InsertSort()
{
    cout<<"\n~~~~~TestVideo47_2InsertSort begin\n";
    int arr[] = { 3, 4, 12, 444, 22, 555, 2223,1};
    int len = sizeof(arr)/sizeof(int);
    SortM::InsertSort(arr,len,false);
    for(int i = 0; i<len; ++i)
    {
        cout<<"i:"<<arr[i]<<endl;
    }
    cout<<"\n~~~~~TestVideo47_2InsertSort End\n";
}

void TestVideo47_3BubbleSort()
{
    cout<<"\n~~~~~TestVideo47_3BubbleSort begin\n";
    int arr[] = { 3, 4, 12, 444, 22, 555, 2223,1};
    int len = sizeof(arr)/sizeof(int);
    SortM::BubbleSort(arr,len,false);
    for(int i = 0; i<len; ++i)
    {
        cout<<"i:"<<arr[i]<<endl;
    }
    cout<<"\n~~~~~TestVideo47_3BubbleSort End\n";
}

void TestVideo48_2ShellSort()
{
    cout<<"\n~~~~~TestVideo48_2ShellSort begin\n";
    int arr[] = { 3, 4, 12, 444, 22, 555, 2223,1};
    int len = sizeof(arr)/sizeof(int);
    SortM::ShellSort(arr,len,false);
    for(int i = 0; i<len; ++i)
    {
        cout<<"i:"<<arr[i]<<endl;
    }
    cout<<"\n~~~~~TestVideo48_2ShellSort End\n";
}


void TestVideo49_2MergeSort()
{
    cout<<"\n~~~~~TestVideo49_2MergeSort begin\n";
    int arr[] = { 4, 3, 12, 444, 66,22, 555, 2223,1,9};
    int len = sizeof(arr)/sizeof(int);
    SortM::MergeSort(arr,len,false);
    for(int i = 0; i<len; ++i)
    {
        cout<<"i:"<<i<<"="<<arr[i]<<endl;
    }
    cout<<"\n~~~~~TestVideo49_2MergeSort End\n";


}

void TestVideo49_3QuickSort()
{
    cout<<"\n~~~~~TestVideo49_3QuickSort begin\n";
    int arr[] = { 4, 3, 12, 444, 66,22, 555, 2223,1,9};
    int len = sizeof(arr)/sizeof(int);
    SortM::QuickSort(arr,len,false);
    for(int i = 0; i<len; ++i)
    {
        cout<<"i:"<<i<<"="<<arr[i]<<endl;
    }
    cout<<"\n~~~~~TestVideo49_3QuickSort End\n";
}

void TestVideo50SortForArray()
{
    cout<<"\n~~~~~TestVideo50SortForArray begin\n";

    StaticArray<int, 10> array1;
//    DynamicArray<int> array1(10);
    array1[0] = 3; array1[1] = 4;
    array1[2] = 12; array1[3] = 444;
    array1[4] = 66; array1[5] = 22;
    array1[6] = 555; array1[7] = 2223;
    array1[8] = 9; array1[9] = 1;


//    SortM::SelectSortForArray(array1,false);
//    SortM::InsertSortForArray(array1,false);
//    SortM::BubbleSortForArray(array1,false);
//    SortM::ShellSortForArray(array1,false);
//    SortM::MergeSortForArray(array1,false);
        SortM::QickSortForArray(array1,false);
    for(int i = 0; i<10; ++i)
    {
        cout<<"i:"<<i<<"="<<array1[i]<<endl;
    }
    cout<<"\n~~~~~TestVideo50SortForArray End\n";
}

void TestVideo50_2SortForComplex()
{
    cout<<"\n~~~~~TestVideo50_2SortForComplex begin\n";
    struct Test: public Object
    {
        int id;
        int data1[1000];
        double data2[500];
        bool operator< (const Test& obj)
        {
            return (this->id < obj.id);
        }
        bool operator>= (const Test& obj)
        {
            return !(this->id < obj.id);
        }
        bool operator> (const Test& obj)
        {
            return (this->id > obj.id);
        }
        bool operator<= (const Test& obj)
        {
            return !(this->id > obj.id);
        }


    };


    class TestProxy: public Object
    {
          protected:
        Test* m_pTest;
        public:
//        TestProxy(Test* pTest)
//        {
//            m_pTest = pTest;
//        }
        int id()
        {
            return m_pTest->id;
        }
        int* data1()
        {
            return m_pTest->data1;
        }
        double* data2()
        {
            return m_pTest->data2;
        }
        Test& test() const
        {
            return *m_pTest;
        }

        bool operator< (const TestProxy& obj)
        {
            return test() < obj.test();
        }
        bool operator>= (const TestProxy& obj)
        {
            return test() >= obj.test();
        }
        bool operator> (const TestProxy& obj)
        {
            return test() > obj.test();
        }
        bool operator<= (const TestProxy& obj)
        {
            return test() <= obj.test();
        }
        Test& operator= (Test& test)
        {
            m_pTest = &test;
            return test;
        }

    };


    int len = 1000;
    Test t[len];
    TestProxy pt[len];

    for(int i = 0; i<len; ++i)
    {
        t[i].id  = i;
        pt[i] = t[i];
    }

    clock_t begin = 0,end = 0;

//    begin = clock();
//    SortM::BubbleSort(t,len,false);
//    end = clock();
//    cout<<"time:"<<(end - begin)<<endl;

    begin = clock();
    SortM::BubbleSort(pt,len,false);
    end = clock();
    cout<<"time:"<<(end - begin)<<endl;


    for(int i = 0; i<len; ++i)
    {
//        cout<<"["<<i<<"]="<<pt[i].id()<<endl;
         cout<<"["<<i<<"]="<<t[i].id<<",pt:"<<pt[i].id()<<endl;
    }

    cout<<"\n~~~~~TestVideo50_2SortForComplex End\n";
}

void TestVideo51Tree()
{
    cout<<"\n~~~~~TestVideo51Tree Begin\n";

    Tree<int>* t;
    TreeNode<int>* tn;

    GTree<char>  t2;
    GTreeNode<char>  tn2;

    GTreeNode<char> root;
    root.value ='A';
    root.parent = nullptr;
    cout<<"stage 1\n";

    try
    {
        t2.insert(&root);
    }
    catch(const Exception& exp)
    {
        cout<<"mesg:"<<exp.message()<<",loc"<<exp.location()<<endl;
    }

    try
    {
//        t2.insert('A');
    }
    catch(const Exception& exp)
    {
        cout<<"mesg:"<<exp.message()<<",loc"<<exp.location()<<endl;
    }


    GTreeNode<char>* node = nullptr;
    node = t2.find('A');

    t2.insert('B',node);  t2.insert('C',node);  t2.insert('D',node);

    node = t2.find('B');
    cout<<"is node null:"<<(node==nullptr)<<endl;
    try
    {
        t2.insert('E',node);

    }
    catch(const Exception& exp)
    {
        cout<<"mesg:"<<exp.message()<<",loc"<<exp.location()<<endl;
    }
    t2.insert('F',node);

    node = t2.find('E');
    t2.insert('K',node);  t2.insert('L',node);

    node = t2.find('C');
    t2.insert('G',node);

    node = t2.find('G');
    t2.insert('N',node);


    node = t2.find('D');
    t2.insert('H',node);  t2.insert('I',node);  t2.insert('J',node);

    node = t2.find('H');
    t2.insert('M',node);

    cout<<"stage 2\n";
    try
    {
        t2.clear();
    }
    catch(const Exception& exp)
    {
        cout<<"mesg:"<<exp.message()<<",loc"<<exp.location()<<endl;
    }


    char* s = "KLFGMIJ";
    TreeNode<char>* tofindnode;
    for(int i = 0; i<strlen(s); ++i)
    {
        tofindnode = t2.find(s[i]);
        while(tofindnode!= nullptr)
        {
            cout<<"node value ="<<tofindnode->value<<" ";
            tofindnode = tofindnode->parent;
        }
        cout<<endl;
    }
    t2.find('0');
    t2.find(&tn2);
    cout<<"\n~~~~~TestVideo51Tree End\n";
}

void TestVideo56TreeRemove()
{
    cout<<"\n~~~~~TestVideo56TreeRemove Begin\n";
    GTree<char>  t2;

    GTreeNode<char> root;
    root.value ='A';
    root.parent = nullptr;
    t2.insert(&root);

//    t2.insert('A',nullptr);
    GTreeNode<char>* node = nullptr;
    node = t2.find('A');
    t2.insert('B',node);  t2.insert('C',node);  t2.insert('D',node);

    node = t2.find('B');
    t2.insert('E',node);t2.insert('F',node);

    node = t2.find('E');
    t2.insert('K',node);  t2.insert('L',node);

    node = t2.find('C');
    t2.insert('G',node);

//    node = t2.find('G');
//    t2.insert('N',node);

    node = t2.find('D');
    t2.insert('H',node);  t2.insert('I',node);  t2.insert('J',node);

    node = t2.find('H');
    t2.insert('M',node);

    try
    {
//        t2.remove('D');
//        t2.remove(t2.find('D'));

    }
    catch(Exception& exp)
    {
        cout<<"error,mes:"<<exp.message()<<",loc:"<<exp.location()<<endl;
    }

    cout<<"t2.count = "<<t2.count()<<endl;
    cout<<"t2.height = "<<t2.height()<<endl;
    cout<<"t2.degree = "<<t2.degree()<<endl;

//    t2.remove('D');
    cout<<"after remove t2.count = "<<t2.count()<<endl;

    char* s = "KLFGMIJ";

//    for(int i = 0; i<7; ++i)
//    {
//        TreeNode<char>* tofindnode = t2.find(s[i]);
//        while(tofindnode != nullptr)
//        {
//            cout<<"node value ="<<tofindnode->value<<" ";
//            tofindnode = tofindnode->parent;
//        }
//        cout<<endl;
//    }

    for(t2.begin(); !t2.end(); t2.next())
    {
        cout<<"t.current:"<<t2.current()<<endl;
    }
    cout<<"after check t2.count = "<<t2.count()<<endl;

    cout<<"\n~~~~~TestVideo56TreeRemove End\n";
}


void TestVideo62TwoTree()
{
    cout<<"\n~~~~~TestVideo62TwoTree Begin\n";

    BTree<int> bt;
    BTreeNode<int>* btn = nullptr;

    bt.insert(1,nullptr);
    btn = bt.find(1);
    bt.insert(2,btn);
    bt.insert(3,btn);

    try
    {
        btn = bt.find(2);
        bt.insert(4,btn);
        bt.insert(5,btn );
    }
    catch (Exception& exp)
    {
        cout<<"error, mes:"<<exp.message()<<",loc="<<exp.location()<<endl;
    }


    btn = bt.find(4);
    bt.insert(8,btn );
    bt.insert(9,btn );

    btn = bt.find(5);
    bt.insert(10,btn );

    btn = bt.find(3);
    bt.insert(6,btn );
    bt.insert(7,btn );

    btn = bt.find(6);
    bt.insert(11,btn ,LEFT);
    bt.insert(12,btn ,RIGHT);

    int a[] = {8, 9, 10, 11, 7, 12};

    for(int i = 0 ; i<6; ++i)
    {
        TreeNode<int>* node = bt.find(a[i]);
        while(node)
        {
            cout<<"node.value="<<node->value<<", " ;
            node = node->parent;
        }
        cout<<endl;
    }

    cout<<endl;

    cout<<"count:"<<bt.count()<<",height:"<<bt.height()<<",degree:"<<bt.degree()<<endl;
//    bt.remove(8);
//    bt.remove(9);
//    bt.remove(10);
//    bt.remove(11);
    SharedPointer<Tree<int>> sp = bt.remove(12);
    cout<<"after remove 12, count:"<<bt.count()<<",height:"<<bt.height()<<endl;


    for(int i = 0 ; i<6; ++i)
    {
        TreeNode<int>* node = bt.find(a[i]);
        while(node)
        {
            cout<<"node.value="<<node->value<<", " ;
            node = node->parent;
        }
        cout<<endl;
    }

    cout<<"the removed tree"<<endl;
    for(int i = 0 ; i<6; ++i)
    {
        TreeNode<int>* node = sp->find(a[i]);
        while(node)
        {
            cout<<"node.value="<<node->value<<", " ;
            node = node->parent;
        }
        cout<<endl;
    }


    cout<<"\nsatge 3 ";
    for(bt.begin(); !bt.end(); bt.next())
    {
        cout<<"current:"<<bt.current()<<",";
    }
    cout<<"\nsatge 4 ";
    SharedPointer<ArrayM<int>> sp2 = nullptr;
    sp2 = bt.traversal(PreOrder);
    for(int i = 0 ; i<(*sp2).length(); i++)
    {
        cout<<(*sp2)[i]<<", ";
    }
    cout<<"\nin order";
    sp2 = bt.traversal(InOrder);
    for(int i = 0 ; i<(*sp2).length(); i++)
    {
        cout<<(*sp2)[i]<<", ";
    }
    cout<<"\npost order";
    sp2 = bt.traversal(PostOrder);
    for(int i = 0 ; i<(*sp2).length(); i++)
    {
        cout<<(*sp2)[i]<<", ";
    }
    cout<<"\n~~~~~TestVideo62TwoTree End\n";
}


void TestVideo68_1BTreeClone()
{
    cout<<"\n~~~~~TestVideo68_1BTreeClone begin\n";

    BTree<int> bt;
    BTreeNode<int>* btn = nullptr;

    bt.insert(1,nullptr);
    btn = bt.find(1);
    bt.insert(2,btn);
    bt.insert(3,btn);

    btn = bt.find(2);
    bt.insert(4,btn);
    bt.insert(5,btn );

    btn = bt.find(4);
    bt.insert(8,btn );
    bt.insert(9,btn );

    btn = bt.find(5);
    bt.insert(10,btn );

    btn = bt.find(3);
    bt.insert(6,btn );
    bt.insert(7,btn );

    btn = bt.find(6);
    bt.insert(11,btn ,LEFT);
    bt.insert(12,btn ,RIGHT);

    SharedPointer<BTree<int>> btcopy = bt.clone();
    SharedPointer<ArrayM<int>> sp2 = nullptr;
    sp2 = btcopy->traversal(PreOrder);


    cout<<"size:"<<(*sp2).length()<<endl;
    for(int i = 0; i<(*sp2).length(); ++i)
    {
        cout<<(*sp2)[i]<<" , ";
    }

    BTree<int> bt2;
    cout<<"\n stage 2~~~~is euql :"<< (bt==*btcopy)<<", "<<(bt==bt2)<<endl;

    cout<<"\nsatge3"<<endl;
    BTree<int> bt3;
    bt3.insert(0,nullptr);
    btn = bt3.find(0);
    bt3.insert(6,btn);
    bt3.insert(2,btn);

    btn = bt3.find(2);
    bt3.insert(7,btn);
    bt3.insert(8,btn);
    SharedPointer<BTree<int>> r  = bt.add(bt3);

    sp2 = bt3.traversal(PreOrder);
    for(int i = 0 ; i<(*sp2).length(); i++)
    {
        cout<<(*sp2)[i]<<", ";
    }
    cout<<endl;

    sp2 = bt.traversal(LevelOrder);
    for(int i = 0 ; i<(*sp2).length(); i++)
    {
        cout<<(*sp2)[i]<<", ";
    }

    cout<<"\nstage 4:\n";
    BTreeNode<int>* head = bt.thread(LevelOrder);
    while (head!= nullptr)
    {
        cout<<"value:"<<head->value<<", ";
        head = head->left;
    }
    cout<<"~~~~~TestVideo68_1BTreeClone End\n";
}

template <typename T>
BTreeNode<T>* createTree()
{
    static  BTreeNode<int> ns[9];
    for(int i =0;i<9; ++i)
    {
        ns[i].value =i;
        ns[i].parent = nullptr;
        ns[i].left = nullptr;
        ns[i].right = nullptr;
    }
    ns[0].left = &ns[1];  ns[0].right = &ns[2];
    ns[1].parent = &ns[0]; ns[2].parent = &ns[0];

    ns[1].left = &ns[3];  ns[1].right = nullptr;
    ns[3].parent = &ns[1];

    ns[2].left = &ns[4];  ns[2].right = &ns[5];
    ns[4].parent = &ns[2]; ns[5].parent = &ns[2];

    ns[3].left = nullptr;  ns[3].right = &ns[6];
    ns[6].parent = &ns[3];

    ns[4].left = &ns[7];  ns[4].right = nullptr;
    ns[7].parent = &ns[4];

    ns[5].left = &ns[8];  ns[5].right = nullptr;
    ns[8].parent = &ns[5];

    return ns;
}
template <typename T>
void printInOrder(BTreeNode<T>* node)
{
    if(node!= nullptr)
    {
        printInOrder(node->left);
        cout<<"node.value"<<node->value<<endl;
        printInOrder(node->right);
    }
}
template <typename T>
BTreeNode<T>* delOdd1(BTreeNode<T>* node)
{
    BTreeNode<T>* ret = nullptr;
    if(node != nullptr)
    {
        if( ((node->left != nullptr) && (node->right == nullptr))  ||\
                ((node->left == nullptr) && (node->right != nullptr)) )
        {
            BTreeNode<T>* parent = dynamic_cast<BTreeNode<T>*>(node->parent);
            BTreeNode<T>* node_child = ( node->left != nullptr)?node->left:node->right;
            if(parent != nullptr)
            {
                BTreeNode<T>*& parent_child = (parent->left == node)?parent->left:parent->right;

                parent_child = node_child;

                node_child->parent = parent;
            }
            else
            {
                node_child->parent = nullptr;
            }
            if(node->flag())
            {
                delete node;
            }
             ret = delOdd1(node_child);
        }
        else
        {
            delOdd1(node->left);
            delOdd1(node->right);
            ret =  node;
        }
    }
    return ret;
}

template <typename T>
BTreeNode<T>* delOdd2(BTreeNode<T>*& node)
{
    BTreeNode<T>* ret = nullptr;
    if(node != nullptr)
    {
        if( ((node->left != nullptr) && (node->right == nullptr))  ||\
                ((node->left == nullptr) && (node->right != nullptr)) )
        {
            BTreeNode<T>* node_child = (node->left != nullptr)?node->left:node->right;

            if(node->flag())
            {
                delete node;
            }
            node = node_child;
            ret = delOdd2(node);
        }
        else
        {
            delOdd2(node->left);
            delOdd2(node->right);
            ret =  node;
        }
    }
    return ret;
}


void TestVideo70_1BTreeQue()
{
    BTreeNode<int>* ns = createTree<int>();
    printInOrder(ns);
    ns = delOdd2(ns);
    cout<<endl;
    printInOrder(ns);

    cout<<endl;
//    int a[] = {6,7,8};
//    for(int i = 0 ; i<3; ++i)
//    {
//        TreeNode<int>* n = ns+a[i];
//        while(n!= nullptr)
//        {
//            cout<<"val:"<<n->value<<", ";
//            n = n->parent;
//        }
//        cout<<endl;
//    }

    cout<<endl;
}



template <typename T>
void inOrderThread2(BTreeNode<T>* node,BTreeNode<T>*& pre)
{
    if(node != nullptr)
    {
        inOrderThread2(node->left,pre);
        node->left = pre;
        if(pre!= nullptr)
        {
            pre->right = node;
        }
        pre = node;
        inOrderThread2(node->right,pre);
    }
}

template <typename T>
BTreeNode<T>* inOrderThread1(BTreeNode<T>* node)
{
    BTreeNode<T>* pre =nullptr;
    inOrderThread2(node, pre);
    while( (node!= nullptr) && (node->left!=nullptr) )
    {
        node = node->left;
    }
    return node;

}

void TestVideo70_3BTreeQue()
{
    BTreeNode<int>* ns = createTree<int>();
    printInOrder(ns);
    delOdd2(ns);
    cout<<endl;
    printInOrder(ns);

    cout<<"start"<<endl;
    ns = inOrderThread1(ns);

    cout<<"after"<<endl;

//    printInOrder(ns);

    while(ns->right != nullptr)
    {
        cout<<"val:"<<ns->value<<", ";
        ns = ns->right;
    }
cout<<"val:"<<ns->value<<", ";

    cout<<endl;
}

template <typename T>
void inOrderThread(BTreeNode<T>* node , BTreeNode<T>* & head, BTreeNode<T>* & tail)
{
   if(node != nullptr)
   {
       BTreeNode<T>* h = nullptr;
       BTreeNode<T>* t = nullptr;

       inOrderThread(node->left, h, t);
       node->left = t;
       if(t != nullptr)
       {
           t->right = node;
       }

       head = (h!= nullptr)?h:node;

       h = nullptr;
       t = nullptr;

       inOrderThread(node->right,h, t);
       node->right = h;
       if(h != nullptr)
       {
           h->left = node;
       }
       tail = (t!= nullptr)? t : node;
   }
}

template <typename T>
BTreeNode<T>* inOrderThread4(BTreeNode<T>* node )
{
    BTreeNode<T>* head = nullptr;
    BTreeNode<T>* tail = nullptr;
    inOrderThread(node, head, tail);
    return head;

}


void TestVideo70_4BTreeQue()
{
    BTreeNode<int>* ns = createTree<int>();
    printInOrder(ns);
    cout<<"start"<<endl;
    ns = inOrderThread4(ns);
    while(ns->right != nullptr)
    {
        cout<<"val:"<<ns->value<<", ";
        ns = ns->right;
    }
    cout<<"val:"<<ns->value<<", ";
}


void TestVideo71Graph()
{
    cout<<"\n~~~~~TestVideo71Graph begin2222\n";
    cout<<"start1";
    Graph <int,int>* g = nullptr;
    cout<<"start2";
    MatrixGraph<3,int,int> g2;

    g2.setEdge(0,1,1);
    g2.setEdge(1,0,2);
    g2.setEdge(1,2,3);
    cout<<"vcount:"<<g2.vCount()<<endl;
    cout<<"ecount:"<<g2.eCount()<<endl;
    cout<<"od(1):"<<g2.OD(1)<<", id(1):"<<g2.ID(1)<<", td(1):"<<g2.TD(1)<<endl;

    cout<<"getEdge(0,1):"<<g2.getEdge(0,1)<<endl;
    cout<<"getEdge(1,0):"<<g2.getEdge(1,0)<<endl;
    cout<<"getEdge(1,2):"<<g2.getEdge(1,2)<<endl;

    SharedPointer<ArrayM<int>> aj = g2.getAdjacent(2);
    for(int i=0; i<aj->length(); ++i)
    {
        cout<<"["<<i<<"]="<<(*aj)[i]<<endl;
    }
    cout<<"delete edge"<<endl;
    g2.removeEdge(0,1);
    cout<<"ecount:"<<g2.eCount()<<endl;

    g2.setVertex(0,100);
    cout<<"v(0):"<<g2.getVertex(0)<<endl;

    cout<<"w(0,1):"<<g2.getEdge(1,0)<<endl;


    cout<<"\n~~~~~TestVideo71Graph End\n";
}

void TestVideo73ListGraph()
{
    cout<<"\n~~~~~TestVideo73ListGraph begin2222\n";

    LinkGraph<char,int> g2;


//        g2.setVertex(0,'A');
//        g2.setVertex(1,'B');
//        g2.setVertex(2,'C');
//        g2.setVertex(3,'D');
        g2.addVertex('A'); g2.addVertex('B');
        g2.addVertex('C'); g2.addVertex('D');

//    g2.removeVertex();


    for(int i = 0 ; i<g2.vCount(); ++i)
    {
        cout<<"["<<i<<"]="<<g2.getVertex(i)<<endl;
    }


    g2.setEdge(0,1,5);
    g2.setEdge(0,3,6);
    g2.setEdge(1,2,8);
    g2.setEdge(2,3,2);
    g2.setEdge(3,1,9);
try
{
    cout<<"w(0,1)"<<g2.getEdge(0,1)<<endl;
    cout<<"w(0,3)"<<g2.getEdge(0,3)<<endl;
    cout<<"w(1,2)"<<g2.getEdge(1,2)<<endl;
    cout<<"w(2,3)"<<g2.getEdge(2,3)<<endl;
    cout<<"w(3,1)"<<g2.getEdge(3,1)<<endl;
    }
    catch(Exception& exp)
    {
        cout<<"exp:"<<exp.message()<<", "<<exp.location()<<endl;
    }

    cout<<"ecount:"<<g2.eCount()<<", vcount:"<<g2.vCount()<<endl;
//    g2.removeEdge(3,1);
    cout<<"ecount:"<<g2.eCount()<<", vcount:"<<g2.vCount()<<endl;

    SharedPointer<ArrayM<int>> aj = g2.getAdjacent(0);
    for(int i = 0; i< aj->length(); ++i)
    {
        cout<<"["<<i<<"]="<<(*aj)[i]<<endl;
    }

    cout<<"id(1)"<<g2.ID(1)<<",od:"<<g2.OD(1)<<",td:"<<g2.TD(1)<<endl;

    g2.removeVertex();
    cout<<"ecount:"<<g2.eCount()<<", vcount:"<<g2.vCount()<<endl;
    cout<<"w(0,1)"<<g2.getEdge(0,1)<<endl;
    cout<<"w(1,2)"<<g2.getEdge(1,2)<<endl;

    cout<<"\n~~~~~TestVideo73ListGraph End\n";
}


template <typename V, typename E>
void DFS(Graph<V,E>& g, int v, ArrayM<bool>& visited)
{
    if( (0<=v) && (v<g.vCount()) )
    {
        cout<<"void DFS "<<v<<endl;
        visited[v] = true;
        SharedPointer<ArrayM<int>> aj = g.getAdjacent(v);
        for(int i = 0; i<aj->length(); ++i)
        {
            if(!visited[(*aj)[i]])
            {
                DFS(g,(*aj)[i],visited);
            }
        }
    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException,"index v is invalid in void DFS(Graph<V,E>& g, int v, ArrayM<bool>& visited)...");
    }
}


template <typename V, typename E>
void DFS(Graph<V,E>& g, int v)
{
    DynamicArray<bool> visited(g.vCount());
    for( int i =0; i< visited.length(); ++i)
    {
        visited[i] = false;
    }
    DFS(g,v,visited);
}

void TestVideo74GraphSearch()
{
    MatrixGraph<9, char, int> g;
    const char* VD = "ABCDEFGHI";
    for(int i = 0; i< 9; ++i)
    {
        g.setVertex(0,VD[i]);
    }
    g.setEdge(0,1,0);  g.setEdge(1,0,0);

    g.setEdge(0,3,0);  g.setEdge(3,0,0);

    g.setEdge(0,4,0);  g.setEdge(4,0,0);

    g.setEdge(1,2,0);  g.setEdge(2,1,0);

    g.setEdge(1,4,0);  g.setEdge(4,1,0);

    g.setEdge(2,5,0);  g.setEdge(5,2,0);

    g.setEdge(3,6,0);  g.setEdge(6,3,0);

    g.setEdge(4,6,0);  g.setEdge(6,4,0);

    g.setEdge(6,7,0);  g.setEdge(7,6,0);

    g.setEdge(7,8,0);  g.setEdge(8,7,0);

    SharedPointer<ArrayM<int>> sa = g.BFS(0);
    for(int i = 0; i<sa->length(); ++i)
    {
        cout<<"["<<i<<"]="<<(*sa)[i]<<endl;
    }
    cout<<"test2\n";
     sa = g.DFS(0);
    for(int i = 0; i<sa->length(); ++i)
    {
        cout<<"["<<i<<"]="<<(*sa)[i]<<endl;
    }

    cout<<"test3\n";
    DFS(g,0);
}

template<typename V, typename E>
Graph<V,E>& GraphEasy()
{
    static MatrixGraph<4,V,E> g;
    g.setEdge(0,1,1);  g.setEdge(1,0,1);
    g.setEdge(0,2,3);  g.setEdge(2,0,3);
    g.setEdge(1,2,1);  g.setEdge(2,1,1);
    g.setEdge(1,3,4);  g.setEdge(3,1,4);
    g.setEdge(2,3,1);  g.setEdge(3,2,1);
    return g;
}

template<typename V, typename E>
Graph<V,E>& GraphComplex()
{
    static LinkGraph<V,E> g(9);
//    static MatrixGraph<9,V,E> g;
    g.setEdge(0,1,10);  g.setEdge(1,0,10);
    g.setEdge(0,5,11);  g.setEdge(5,0,11);
    g.setEdge(1,2,18);  g.setEdge(2,1,18);
    g.setEdge(1,8,12);  g.setEdge(8,1,12);
    g.setEdge(1,6,16);  g.setEdge(6,1,16);
    g.setEdge(2,3,22);  g.setEdge(3,2,22);
    g.setEdge(2,8,8);  g.setEdge(8,2,8);
    g.setEdge(3,8,21);  g.setEdge(8,3,21);

    g.setEdge(3,6,24);  g.setEdge(6,3,24);
    g.setEdge(3,7,16);  g.setEdge(7,3,16);
    g.setEdge(3,4,20);  g.setEdge(4,3,20);
    g.setEdge(4,5,26);  g.setEdge(5,4,26);
    g.setEdge(4,7,7);  g.setEdge(7,4,7);
    g.setEdge(5,6,17);  g.setEdge(6,5,17);
    g.setEdge(6,7,19);  g.setEdge(7,6,19);
    return g;
}

void TestVideo76Prim()
{
    cout<<"\n~~~~~TestVideo76Prim begin2222\n";

//    Graph<int,int>& g = GraphEasy<int, int>();
//    SharedPointer<ArrayM<Edge<int>>> sa = g.Prim(65535);

//    int w = 0;
//    for(int i = 0; i<sa->length(); ++i)
//    {
//        cout<<"["<<i<<"]="<<(*sa)[i].b<<", "<<(*sa)[i].e<<", "<<(*sa)[i].data << endl;
//        w += (*sa)[i].data;
//    }
//    cout<<"w="<<w<<endl;
    cout<<"test 2"<<endl;
    Graph<int,int>& g = GraphComplex<int, int>();
    SharedPointer<ArrayM<Edge<int>>> sa;
    try
    {
         sa = g.Prim(65535,true);
    }
    catch(Exception& exp)
    {
        cout<<"error,mes:"<<exp.message()<<",loc ="<<exp.location()<<endl;
    }

    int  w = 0;
    for(int i = 0; i<sa->length(); ++i)
    {

        cout<<"["<<i<<"]="<<(*sa)[i].b<<", "<<(*sa)[i].e<<", "<<(*sa)[i].data << endl;
        w += (*sa)[i].data;
    }
    cout<<"w="<<w<<endl;

    cout<<"\n~~~~~TestVideo76Prim End\n";
}

void TestVideo78Dijkstra()
{
    cout<<"\n~~~~~TestVideo78Dijkstra begin2222\n";

    Graph<int,int>& g = GraphEasy<int, int>();
//    Graph<int,int>& g = GraphComplex<int, int>();
    SharedPointer<ArrayM<int>> p;
    try
    {
         p= g.dijkstra(0,2,65535);
    }
    catch(Exception& exp)
    {
        cout<<"error,mes:"<<exp.message()<<",loc ="<<exp.location()<<endl;
    }
    cout<<"end,size:"<<endl;
    cout<<"end,size:"<<p->length()<<endl;
    for(int i =0; i<p->length();++i)
    {
        cout<<"["<<i<<"]="<<(*p)[i]<<", ";
    }
    cout<<"\n~~~~~TestVideo78Dijkstra End\n";
}

template<typename V, typename E>
Graph<V,E>& GraphSample()
{
    static LinkGraph<V,E> g(3);
    g.setEdge(0,1,4);
    g.setEdge(0,2,11);
    g.setEdge(1,2,2);
    g.setEdge(1,0,6);
    g.setEdge(2,0,3);
    return g;
}

void TestVideo79Floyd()
{
    cout<<"\n~~~~~TestVideo79Floyd begin2222\n";

    Graph<int, int>& g2 = GraphSample<int, int>();
    int r ;
    try
    {
        r= g2.Floyd(0,2,65535);
    }
    catch(Exception& exp)
    {
        cout<<"error,mes:"<<exp.message()<<",loc ="<<exp.location()<<endl;
    }
    for(int i =0; i<g2.vCount(); ++i)
    {
        for(int j =0; j<g2.vCount(); ++j)
        {
             r= g2.Floyd(i,j,65535);
            cout<<i<<" to "<<j<< " smallest:"<<r<<endl;
        }
    }
    cout<<"\n~~~~~TestVideo79Floyd End\n";
}

int  searchMaxPath(Graph<int, int>& g, int v, ArrayM<int>& count, ArrayM<LinkList<int>*>& path, ArrayM<bool>& mark)
{
    int ret = 0;

//    int k = -1;
    SharedPointer<ArrayM<int>> aj = g.getAdjacent(v);
    for(int i = 0; i<aj->length(); ++i)
    {
        int num = 0;
        if(!mark[(*aj)[i]] )
        {
            num = searchMaxPath(g,(*aj)[i], count, path, mark);
        }
        else
        {
            num = count[(*aj)[i]];
        }
        if( ret < num)
        {
            ret = num;
//            k = (*aj)[i];
        }
    }
    for(int i =0; i<aj->length(); ++i)
    {
        if(ret == count[(*aj)[i]])
        {
            path[v]->insert((*aj)[i]);
        }
    }

    ret++;
    count[v] = ret;
    mark[v] = true;
//    path[v] = k;

    return ret;
}

SharedPointer<Graph<int, int>> CreateGraph(int * a, int len)
{
    LinkGraph<int,int>* ret = new LinkGraph<int, int >(len);

    for(int i = 0; i<len; ++i)
    {
        ret->setVertex(i,a[i]);
    }

    for(int i = 0; i < len; ++i)
    {
        for(int j = i+1; j<len; ++j)
        {
            if(a[i] <= a[j])
            {
                ret->setEdge(i,j,1);
            }
        }
    }
    return ret;
}

void InitArray(ArrayM<int>& count, ArrayM<LinkList<int>*>& path, ArrayM<bool>& mark)
{
    for(int i = 0; i<count.length(); ++i)
    {
        count[i] = 0;
    }
    for(int i = 0; i<path.length(); ++i)
    {
        path[i] = new LinkList<int>();
    }
    for(int i = 0; i<mark.length(); ++i)
    {
        mark[i] = false;
    }
}

void PrintPath(Graph<int, int>& g, int v, ArrayM<LinkList<int>*> & path, LinkList<int>& cp)
{
    cp.insert(v);
    if( path[v]->length() >0)
    {
        for(path[v]->move(0); !path[v]->end(); path[v]->next())
        {
            PrintPath(g,path[v]->current(), path, cp);
        }
    }
    else
    {
        cout<<"Element:"<<endl;
        for(cp.move(0); !cp.end(); cp.next())
        {
            cout<<g.getVertex(cp.current())<<", ";
        }
        cout<<endl;
    }

    cp.remove(cp.length() -1);

}

void PrintMaxPath(Graph<int, int>& g, ArrayM<int>& count, ArrayM<LinkList<int>*>& path)
{
    int max = 0;

    LinkList<int> cp;
    for(int i = 0; i<count.length(); ++i)
    {
        if(max < count[i])
        {
            max = count[i];
        }
    }
    cout<<"Len:"<<max<<endl;
    for(int i = 0; i<count.length(); ++i)
    {
        if(max == count[i])
        {
            PrintPath(g,i,path,cp);


//            cout<<"Element:"<<g.getVertex(i)<<", ";
//            for(int j = path[i]; j!=-1; j = path[j])
//            {
//                cout<<g.getVertex(j)<<", ";
//            }
//            cout<<endl;
        }
    }
}

void searchMaxPath(Graph<int, int>& g, ArrayM<int>& count, ArrayM<LinkList<int>*>& path,ArrayM<bool>& mark)
{
    for(int i =0; i<g.vCount(); ++i)
    {
        if(!mark[i])
        {
            searchMaxPath(g,i,count,path,mark);
        }
    }
}

void solution(int* a, int len)
{
    DynamicArray<int> count(len);
    DynamicArray<LinkList<int>*> path(len);
    DynamicArray<bool> mark(len);

    SharedPointer<Graph<int, int>> g = CreateGraph(a,len);
    InitArray(count, path,mark);
    searchMaxPath(*g,count, path,mark);
    PrintMaxPath(*g,count,path);
}


void TestVideo80_2()
{
//    int a[] = {3, 18, 7, 14, 10, 12, 23, 41, 16, 24};
//    int a[] = { 5,4,3,2,1  };
//    int a[] = { 1,2,3,4,5  };
    int a[] = { 1,2,9,8,7  };
//    int a[] = {  1,2,6,4,3,5,4  };
//    int a[] = { 2, 1,3,5,4  };
    solution(a,sizeof(a)/sizeof(*a));

}


