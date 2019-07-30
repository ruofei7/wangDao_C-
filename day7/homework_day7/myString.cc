#include "myString.h"
String ::String()
{
    _pstr = nullptr;
}
String ::String(const char *pstr)
    : _pstr(new char[strlen(pstr) + 1]())
{
    strcpy(_pstr, pstr);
}
String ::String(const String &rstr)
{
    *this = rstr;
}
String ::~String()
{
    if (_pstr)
        delete[] _pstr;
}
String &String::operator=(const String &rstr)
{
    _pstr = new char[strlen(rstr._pstr) + 1]();
    strcpy(_pstr, rstr._pstr);
    return *this;
}
String &String::operator=(const char *pstr)
{
    _pstr = new char[strlen(pstr) + 1]();
    strcpy(_pstr, pstr);
    return *this;
}
String &String::operator+=(const String &rstr)
{
    char *tempString = new char[strlen(rstr._pstr) + strlen(this->_pstr) + 1]();
    sprintf(tempString, "%s%s", _pstr, rstr._pstr);
    delete[] _pstr;
    if (_pstr)
        _pstr = tempString;
    return *this;
}
String &String::operator+=(const char *pstr)
{
    char *tempString = new char[strlen(pstr) + strlen(this->_pstr) + 1]();
    sprintf(tempString, "%s%s", _pstr, pstr);
    delete[] _pstr;
    if (_pstr)
        _pstr = tempString;
    return *this;
}
char &String::operator[](std::size_t index)
{
    return this->_pstr[index];
}
const char &String::operator[](std::size_t index) const
{
    return this->_pstr[index];
}
std::size_t String::size() const
{
    return strlen(_pstr);
}
const char *String::c_str() const //将String转换成C风格的字符串
{
    return _pstr;
}
bool operator==(const String &lhs, const String &rhs)
{
    if (0 == strcmp(lhs._pstr, rhs._pstr))
        return true;
    else
    {
        return false;
    }
}
bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}
bool operator<(const String &lhs, const String &rhs)
{
    if (strcmp(lhs._pstr, rhs._pstr) < 0)
        return true;
    else
    {
        return false;
    }
}
bool operator>(const String &lhs, const String &rhs)
{
    if (strcmp(lhs._pstr, rhs._pstr) > 0)
        return true;
    else
    {
        return false;
    }
}
bool operator<=(const String &lhs, const String &rhs)
{
    if (strcmp(lhs._pstr, rhs._pstr) <= 0)
        return true;
    else
    {
        return false;
    }
}
bool operator>=(const String &lhs, const String &rhs)
{
    if (strcmp(lhs._pstr, rhs._pstr) >= 0)
        return true;
    else
    {
        return false;
    }
}
std::ostream &operator<<(std::ostream &os, const String &s)
{
    os << s._pstr;
    return os;
}
std::istream &operator>>(std::istream &is, String &s)
{
    char *pstr = new char[10]();
    while (is >> pstr, !is.eof())
    {
        s += pstr;
        bzero(pstr, sizeof(pstr));
    }
    is >> s._pstr;
    return is;
}
String operator+(const String &lhs, const String &rhs)
{

    char *pstr = new char[strlen(lhs.c_str()) + strlen(rhs.c_str()) + 1]();
    sprintf(pstr, "%s%s", lhs.c_str(), rhs.c_str());
    return String(pstr);
}
String operator+(const String &lhs, const char *str)
{
    char *pstr = new char[strlen(lhs.c_str()) + strlen(str) + 1]();
    sprintf(pstr, "%s%s", lhs.c_str(), str);
    return String(pstr);
}
String operator+(const char *str, const String &rhs)
{
    char *pstr = new char[strlen(pstr) + strlen(rhs.c_str()) + 1]();
    sprintf(pstr, "%s%s", str, rhs.c_str());
    return String(pstr);
}