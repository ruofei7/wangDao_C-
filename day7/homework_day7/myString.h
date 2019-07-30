#pragma once
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
class String
{
public:
    String();
    String(const char *);
    String(const String &);
    ~String();
    String &operator=(const String &);
    String &operator=(const char *);

    String &operator+=(const String &);
    String &operator+=(const char *);

    char &operator[](std::size_t index);             //非const对
    const char &operator[](std::size_t index) const; //const对象调用这个,eg.const String。

    std::size_t size() const;
    const char *c_str() const; //转换成C风格的字符串

    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);

    friend bool operator<(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator>=(const String &, const String &);

    friend std::ostream &operator<<(std::ostream &os, const String &s);
    friend std::istream &operator>>(std::istream &is, String &s);

private:
    char *_pstr;
};
String operator+(const String &, const String &);
String operator+(const String &, const char *);
String operator+(const char *, const String &);
//String operrator+(const char*,const char*);//error,重载操作符必须具有一个类类型或者是枚举类型的操作数
