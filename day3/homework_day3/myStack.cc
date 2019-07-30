#include <iostream>
using std::cout;
using std::endl;
class Stack
{
public:
    void push(int x); //x入栈
    void pop();
    int top();            //读出栈顶元素
    bool emty();          //是否为空
    bool full();          //是否满了
    Stack(int stackSize); //构造函数
    ~Stack();             //析构函数
private:
    int *_stack;
    int _stackSize;
    int _top;
};
Stack::Stack(int stackSize)
    : _stack(new int[stackSize]()), _stackSize(stackSize), _top(-1)
{
    cout << "Stack(int stackSize)" << endl;
}
Stack::~Stack()
{
    delete[] _stack;
    cout << "~Stack()" << endl;
}
inline void Stack::push(int x)
{
    if (!this->full())
    {
        this->_stack[++this->_top] = x;
    }
}
inline void Stack::pop()
{
    if (!this->emty())
        _top--;
}
inline int Stack::top()
{
    return this->_stack[_top];
}
inline bool Stack::emty()
{
    if (this->_top == -1)
        return true;
    else
        return false;
}
inline bool Stack::full()
{
    if (this->_top == this->_stackSize)
        return true;
    else
        return false;
}
int test0(void)
{
    Stack s(10);
    s.push(10);
    s.push(12);
    s.push(14);
    cout << "stack[top]=" << s.top() << endl;
    s.pop();
    cout << "stack[top]=" << s.top() << endl;
    return 0;
}
int main(void)
{
    test0();
    return 0;
}