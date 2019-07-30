#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
//只能生成堆对象，就是说不能生成栈对象，亦即在创建栈对象时，不能[在类之外]调用构造函数或者析构函数
//方法：将析构函数放在private区，并在public区域定义一个destroy函数，用于销毁堆对象，从而可以调用private中的析构函数。
class Student
{
public:
    void print() const
    {
        cout << "id=" << _id << "\t name=" << _name << endl;
    }
    Student(int id, const char *name)
        : _id(id), _name(new char[strlen(name) + 1]())
    {
        cout << "Student(int id,const char * name)" << endl;
        strcpy(_name, name);
    }
    void destroy()
    {
        cout<<"destroy()"<<endl;
        if(this)
        delete this;
    }
private:
    ~Student()
    {
        cout << " ~Student()" << endl;
        delete[] _name;
    }

private:
    int _id;
    char *_name;
};
int main()
{
    Student *s1=new Student(24,"Dujianjun");//error，不能创建堆对象
    //Student s2(7, "qiqi");//error,不能创建栈对象，析构函数不能使用。
    s1->print();
    //delete s1;//error,不能直接delete，析构函数不能使用。
    s1->destroy();
}