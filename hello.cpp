
#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
using namespace std;
mutex m_mutex;
int i=0;
void test()
{
    
    while(true)
    {
        m_mutex.lock();
        cout<<"生产者生产："<<i<<endl;
        i++;
        m_mutex.unlock();

    }

}
void sss2()
{
    while(true)
    {
        m_mutex.lock();
        cout<<"消费者消费："<<i<<endl;
        i--;
        m_mutex.unlock();
    }

}

int main(){
    cout<<"hello_world!"<<endl;
    std::thread  t2(test);
    std::thread  t1(sss2);
    t2.join();
    t1.join();
    return 0;
}
