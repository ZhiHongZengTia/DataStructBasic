#include "stringm.h"



namespace DTLib {


void StringM::init(const char* s)
{
//    m_str = (s == nullptr)? nullptr:strdup(s);
     m_str = strdup(s?s:nullptr);
    if(m_str)
    {
        m_length = strlen(m_str);
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException,"no enought memory in StringM::init(const char* s)...");
    }

}

StringM::StringM()
{
    init("");


}

StringM::StringM(const char* s)
{
    init(s?s:"");
}

StringM::StringM (const StringM & s)
{
    init(s.m_str);
}

StringM::StringM(char c)
{
    char s[] = {c,'\0'};
    init(s);
}

int StringM::length() const
{
    return m_length;

}

const char* StringM::str() const
{
    return m_str;
}

/* 比较操作符重载 */
bool StringM::operator ==(const StringM& s) const  /* 比较操作符重载 */
{
    return (strcmp(m_str,s.m_str) == 0);
}

bool StringM::operator ==(const char* s) const
{
    return (strcmp(m_str, s?s:"") == 0);
}

bool StringM::operator !=(const StringM& s) const  /* 比较操作符重载 */
{
    return !(*this == s);
}

bool StringM::operator !=(const char* s) const
{
    return !(*this == s);
}

bool StringM::operator >(const StringM& s) const  /* 比较操作符重载 */
{
    return (strcmp(m_str,s.m_str) > 0 );
}

bool StringM::operator >(const char* s) const
{
    return (strcmp(m_str,s?s:"") > 0 );
}

bool StringM::operator <(const StringM& s) const  /* 比较操作符重载 */
{
    return (strcmp(m_str,s.m_str) < 0 );
}

bool StringM::operator <(const char* s) const
{
    return (strcmp(m_str, s?s:"") < 0 );
}


bool StringM::operator >=(const StringM& s) const  /* 比较操作符重载 */
{
    return (strcmp(m_str,s.m_str) >= 0 );
}


bool StringM::operator >=(const char* s) const
{
    return (strcmp(m_str, s?s:"") >= 0 );
}


bool StringM::operator <=(const StringM& s) const  /* 比较操作符重载 */
{
    return (strcmp(m_str,s.m_str) <= 0 );
}

bool StringM::operator <=(const char* s) const
{
    return (strcmp(m_str, s?s:"") <= 0 );
}




/* 加法操作符重载 */
StringM StringM::operator+ (const StringM& s) const
{
    return (*this+s.m_str);
}

StringM StringM::operator+ (const char* s) const
{
    StringM ret;
    int len = m_length + strlen(s?s : "");
    char* str=reinterpret_cast<char*>(malloc(len+1));
    if(str)
    {
        strcpy(str,m_str);
        strcat(str,s?s : "");

        free(ret.m_str);

        ret.m_str = str;
        ret.m_length = len;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException,"no enought memory in StringM::operator+...");
    }
    return ret;
}

StringM& StringM::operator+= (const StringM& s)
{
    return (*this = *this+ s.m_str);
}

StringM& StringM::operator+= (const char* s)
{
    return (*this = *this + (s?s:""));
}






/* 赋值操作符重载 */
StringM& StringM::operator= (const StringM& s)
{
    return (*this = s.m_str);

}

StringM& StringM::operator= (const char* s)
{
    if(m_str != s)
    {
        char* str = strdup(s?s:"");
        if(str)
        {
            free(m_str);
            m_str = str;
            m_length = strlen(s?s:"");
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"no enought memory in StringM::operator=...");
        }
    }

    return *this;

}

StringM& StringM::operator= (char c)
{
    char s[] = {c,'\0'};
   return (*this = s);
}


StringM::~StringM()
{
    free(m_str);
}


char& StringM::operator[] (int i)
{
    if( (0<= i) && (i<m_length) )
    {
        return m_str[i];
    }
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException, "parameter i is out of bounds...");
    }
}
char StringM::operator[] (int i) const
{
    return (const_cast<StringM &>(*this)[i]);
}

bool StringM::equal(const char* s1,const char* s2, int len) const
{
    bool ret = true;
    for(int i = 0; i<len && ret; ++i)
    {
        ret = ret&&  (s1[i] == s2[i]);
    }
    return ret;
}

bool StringM::startWith(const char* s) const
{
    bool ret = ( s != nullptr);
    if(ret)
    {
        int len = strlen(s);
        ret = (len<m_length) && ( equal(m_str,s,len));
    }
    return ret;
}
bool StringM::startWith(const StringM& s) const
{
    return startWith(s.m_str);
}
bool StringM::endOf(const char* s) const
{
    bool ret = ( s != nullptr);
    if(ret)
    {
        int len = strlen(s);
        char* str = m_str + m_length - len;
        ret = (len<m_length) && ( equal(str,s,len));
    }
    return ret;
}
bool StringM::endOf(const StringM & s) const
{
    return startWith(s.m_str);
}




StringM& StringM::intsert(int i, const char* s)
{
    if( (i>=0) && (i<=m_length) )
    {
       if( (s!=nullptr) && (s[0]!= '\0') )
       {
           int len = strlen(s);
           char* str = reinterpret_cast<char *>(malloc(m_length + len+1));
           if( str != nullptr)
           {
              strncpy(str,m_str,i);
              strncpy(str+i,s,len);
              strncpy(str+i+len,m_str+i,m_length-i);
              str[m_length+len] = '\0';
              free(m_str);
              m_str = str;
              m_length = m_length+len;

           }
           else
           {
               THROW_EXCEPTION(NoEnoughMemoryException, "no memory in StringM::intsert...");
           }
       }
    }
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException, "parameter i is invalid in StringM::intsert...");
    }
    return *this;  // to achieve link recall

}
StringM& StringM::insert(int i, const StringM& s)
{
    return intsert(i,s.m_str);
}

StringM& StringM::trim()
{
    int b =0 ;
    int e = m_length-1;
    while(m_str[b] == ' ')
    {
        ++b;
    }
    while(m_str[e] == ' ')
    {
        --e;
    }


    if( b == 0)
    {
        m_str[e+1] = '\0';
        m_length = e+1;
    }
    else
    {
        for(int i = 0 ,j = b; j<=e; ++i, ++j)
        {
            m_str[i] = m_str[j];
        }
        m_str[e-b+1] = '\0';
        m_length = e-b+1;
    }

//    char* str = reinterpret_cast<char *>(malloc(e-b+2));
//    if( str != nullptr)
//    {
//       strncpy(str,m_str+b,e-b+1);
//       str[e-b+1] = '\0';
//       free(m_str);
//       m_str = str;
//       m_length = e-b+1;

//    }
//    else
//    {
//        THROW_EXCEPTION(NoEnoughMemoryException, "no memory in StringM::trim...");
//    }

    return *this;// to achieve link recall
}

}
