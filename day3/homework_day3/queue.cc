#include<iostream>
using std::cout;
using std::endl;
class Queue{
    public:
        void push(int);
        void pop();//元素出队
        int front();//读取队头元素
        int back();//读取队尾元素
        bool emty();//判断队列是否为空
        bool full();//判断队列是否以满
        Queue(int queueSize);
        ~Queue();
    //顺序队列（循环队列）
    private:
        int *_queue;
        int _maxSize;
        int _front;
        int _rear;
};
Queue::Queue(int queueSize)
:_queue(new int[queueSize+1])
,_maxSize(queueSize+1)
,_front(0)
,_rear(0)
{
    cout<<"Queue(int queueSize)"<<endl;
}
Queue::~Queue()
{
    delete [] this->_queue;
    cout<<"~Queue()"<<endl;
}
inline void Queue::push(int x)
{
    if(!this->full())
    {
        _rear=(_rear+1)%_maxSize;
        _queue[_rear]=x;
    }
}
inline void Queue::pop()
{
    if(!this->emty())
        _front=(_front+1)%_maxSize;
}
inline int Queue::front()
{
    return _queue[(_front+1)%_maxSize];
}
inline int Queue::back()
{
    return _queue[this->_rear];
}
inline bool Queue::emty()
{
    if(_front==_rear)
        return true;
    else
    {
        return false;
    }
}
inline bool Queue::full()
{
    if(_front==(_rear+1)%_maxSize)
        return true;
    else
    {
        return false;
    }  
}
int test0(void)
{
    Queue q(10);
    q.push(23);
    q.push(77);
    q.push(24);
    q.push(11);
    q.push(8);
    cout<<"queue[front]="<<q.front()<<endl;
    cout<<"queue[rear]="<<q.back()<<endl;
    q.pop();
    cout<<"执行一次pop后："<<endl;
    cout<<"queue[front]="<<q.front()<<endl;
    cout<<"queue[rear]="<<q.back()<<endl;
    return 0;
}
int main(void)
{
    test0();
    return 0;
}