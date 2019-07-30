#include<iostream>
using std::cout;
using std::endl;
class MutexLock
{
    public:
        void lock();
        void unlock();
    private:
        MutexLock();
        ~MutexLock();
    private:
        int mutex;
        static int mutexNum;
};
class Condition
{
    public:
        void wait();
        void notify();
        void notifyall();
    
}