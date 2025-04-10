#ifndef STRINGM_H
#define STRINGM_H

#include "object.h"
#include "exception.h"
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

namespace DTLib {


class StringM: public Object
{
protected:
    char* m_str;
    int m_length;
    void init(const char* s);
public:
    StringM();
    StringM(const char* s);
    StringM (const StringM & s);  //
    StringM(char c);
    int length() const;
    const char* str() const;

    bool operator ==(const StringM& s) const;  /* 比较操作符重载 */
    bool operator ==(const char* s) const;
    bool operator !=(const StringM& s) const;  /* 比较操作符重载 */
    bool operator !=(const char* s) const;
    bool operator >(const StringM& s) const;  /* 比较操作符重载 */
    bool operator >(const char* s) const;
    bool operator <(const StringM& s) const;  /* 比较操作符重载 */
    bool operator <(const char* s) const;
    bool operator >=(const StringM& s) const;  /* 比较操作符重载 */
    bool operator >=(const char* s) const;
    bool operator <=(const StringM& s) const;  /* 比较操作符重载 */
    bool operator <=(const char* s) const;

    /* 加法操作符重载 */
    StringM operator+ (const StringM& s) const;
    StringM operator+ (const char* s) const;
    StringM& operator+= (const StringM& s) ;
    StringM& operator+= (const char* s) ;
//    StringM operator- (const StringM& s) const;
//    StringM operator- (const char* s) const;
//    StringM operator-= (const StringM& s) const;
//    StringM operator-= (const char* s) const;


    /* 赋值操作符重载 */
    StringM& operator= (const StringM& s) ;
    StringM& operator= (const char* s) ;
    StringM& operator= (char c) ;



    char& operator[] (int i);
    char operator[] (int i) const;

    bool equal(const char* s1,const char* s2, int len) const;

    bool startWith(const char* s) const;
    bool startWith(const StringM& s) const;
    bool endOf(const char* s) const;
    bool endOf(const StringM & s) const;


    StringM& intsert(int i, const char* s);
    StringM& insert(int i, const StringM& s);


    StringM& trim();

    ~StringM();
};


}








#endif // STRINGM_H
