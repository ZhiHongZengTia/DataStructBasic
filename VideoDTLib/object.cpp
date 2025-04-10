#include "object.h"
#include <cstdlib>
#include <iostream>

using namespace std;

namespace DTLib
{

void* Object::operator new(long unsigned int size) throw()
{

//    cout<<"object ,operator new\n";/
//    cout<<"size:"<<size<<endl;
    return malloc(size);
}
void Object::operator delete(void* p)
{
    cout<<"object ,operator delete\n";
//    cout<<"p:"<<p<<endl;
    free(p);
}
void* Object::operator new[] (long unsigned int size) throw()
{
    return malloc(size);
}
void Object::operator delete[] ( void* p)
{
    cout<<"object ,operator delete\n";
    cout<<"p:"<<p<<endl;
    free(p);
}

bool Object::operator==(const Object &obj) const
{
    return (this == &obj);
}

bool Object::operator!=(const Object &obj) const
{
    return (this != &obj);
}
Object::~Object() // 抽象类
{

}


}

