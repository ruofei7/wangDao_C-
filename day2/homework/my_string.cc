#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
class String
{
public:
    //构造函数：
    String()
    {
        cout << "String()" << endl;
        this->_pstr = new char[20]();
    }
    //带传入参数的构造函数：
    String(const char *pstr)
    {
        cout << "String(const char *pstr)" << endl;
        this->_pstr = new char[strlen(pstr) + 1]();
        strcpy(this->_pstr, pstr);
    }
    //拷贝构造函数
    String(const String &rhs)
        : _pstr(new char[strlen(rhs._pstr) + 1]())
    {
        cout << "String(const String & rhs)" << endl;
        strcpy(_pstr, rhs._pstr);
    }
    //赋值运算符函数
    String &operator=(const String &rhs)
    {
        if (this != &rhs) //判断是否是自复制，这里&是取地址，不是引用。
        {
            cout << "String & operator=(const String & rhs)" << endl;
            delete[] this->_pstr; //回收左操作申请的空间
            //再进行深拷贝：
            this->_pstr = new char[strlen(rhs._pstr) + 1];
            strcpy(this->_pstr, rhs._pstr);
        }
        return *this;
    }
    //析构函数
    ~String()
    {
        cout << "~String()" << endl;
        if (NULL != this->_pstr)
            delete[] this->_pstr;
        this->_pstr = NULL;
    }
    //普通成员函数
    void print()
    {
        if (NULL != this->_pstr)
            cout << this->_pstr << endl;
        else
        {
            cout << "_pstr is NULL." << endl;
        }
    }

private:
    char *_pstr;
};
int main(void)
{
    String str1; //调用不带参数的构造函数
    cout << "str1=";
    str1.print();

    String str2 = "Hello,world"; //调用了带参数的构造函数
    String str3("wangdao");      //调用带参数的构造函数
    cout << "str2=";
    str2.print();
    cout << "str3=";
    str3.print();

    String str4 = str3; //调用拷贝构造函数
    cout << "执行String str4 = str3后" << endl;
    cout << "str4=";
    str4.print();

    str4 = str2; //调用赋值运算符函数
    cout << "执行str4 = str2后" << endl;
    cout << "str4=";
    str4.print();

    return 0;
}
