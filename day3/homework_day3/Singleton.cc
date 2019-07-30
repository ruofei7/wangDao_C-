#include<iostream>
using std::cout;
using std::endl;
class Singleton
{
    public:
    static Singleton * getInstance()
    {
        if(nullptr==_pInstance)
        {
            _pInstance=new Singleton;//创建一个堆对象，此时会调用private中的Singleton()
        }
        return _pInstance;
        
    }
    static void destroy()
    {
        if(_pInstance)
            delete _pInstance;//销毁堆对象，此时会调用private中的~Singleton()
    }
    //必须将构造函数和析构函数放在private中，防止类外对其进行调用。
    private:
    Singleton(){    cout<<"Singleton()"<<endl;}//为了使类外不能调用构造函数，只能调用getInstance();
    ~Singleton(){   cout<<"~Singleton()"<<endl;}//为了使类外不能调用析构函数，只能调用destroy();
    private:
    static Singleton *_pInstance;
};
Singleton * Singleton::_pInstance=nullptr;//静态成员只能在类外进行初始化
int main(void)
{
    Singleton *p1=Singleton::getInstance();//调用Singleton类的getInstance()方法。
    Singleton *p2=Singleton::getInstance();
    Singleton *p3=Singleton::getInstance();
    cout<<"p1="<<p1<<endl;
    cout<<"p2="<<p2<<endl;
    cout<<"p3="<<p3<<endl;
    Singleton::destroy();//回收内存。
    return 0;
}