TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    exception.cpp \
    object.cpp \
    Test/testfolder.cpp \
    String/stringm.cpp \
    Graph/graph.cpp \
    Graph/matrixgraph.cpp


HEADERS += \ 
    exception.h \
    object.h \
    list.h \
    seqlist.h \
    staticlist.h \
    dynamiclist.h \
    arraym.h \
    staticarray.h \
    dynamicarray.h \
    Test/testfolder.h \
    LinkList/linklist.h \
    Pointer/smartpointer.h \
    Pointer/pointer.h \
    Pointer/sharedpointer.h \
    LinkList/staticlinklist.h \
    Stack/stackm.h \
    Stack/staticstack.h \
    Stack/linkstack.h \
    Queue/queuem.h \
    Queue/staticqueue.h \
    Queue/dynamicqueue.h \
    Queue/linkqueue.h \
    String/stringm.h \
    Sort/sortm.h \
    Tree/tree.h \
    Tree/treenode.h \
    Tree/gtreenode.h \
    Tree/gtree.h \
    BinaryTree/btree.h \
    BinaryTree/btreenode.h \
    Graph/graph.h \
    Graph/matrixgraph.h \
    Graph/linkgraph.h
