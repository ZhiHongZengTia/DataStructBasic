#ifndef OBJECT_H
#define OBJECT_H


namespace DTLib
{
class Object  // 纯虚父类，所有子类都能进行动态类型识别
{
    public:
    void* operator new(long unsigned int size) throw();  // 不抛出异常，new失败返回NULL
    void operator delete(void* p);
    void* operator new[] (long unsigned int size) throw();
    void operator delete[] ( void* p);
    bool operator== (const Object& obj) const;
    bool operator!= (const Object& obj) const;
    virtual ~Object() = 0;  // 抽象类
};

}





#endif // OBJECT_H
