#include "vector"
#include "iostream"
#include "thread"
int th(int val)
{
    std::cout<<val*val<<std::endl;
    return val*val;
}
int main()
{
    int a=std::thread::hardware_concurrency();
    std::vector<std::thread> poll;
    for (int i = 0; i < a; ++i) {
        poll.push_back(std::thread(th));
    }
//    std::cin>>a;
//    std::thread t(th,a);
//    std::cin>>a;
//    t(a);
//    t.join();
}