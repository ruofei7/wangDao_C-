#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
//只能创建栈对象就是说不能生成堆对象，亦即不能通过new表达式[在类之外]生成对象
//方法：将operator new()或operator delete放在private区域即可，而且只需要声明，不需要实现。使得在类外不能调用new来创建堆对象。
class Student
{
public:
    Student(int id, const char *name)
        : _id(id), _name(new char[strlen(name) + 1]())
    {
        cout << "Student(int id,const char * name)" << endl;
        strcpy(_name, name);
    }
    ~Student()
    {
        cout << " ~Student()" << endl;
        delete[] _name;
    }
    void print() const
    {
        cout << "id=" << _id << "\t name=" << _name << endl;
    }

private:
    void *operator new(size_t sz);
    void operator delete(void *p);

private:
    int _id;
    char *_name;
};
int main()
{
    //Student *s1=new Student("24","Dujianjun");//error，不能创建堆对象
    Student s2(7, "qiqi");
    s2.print();
    return 0;
}