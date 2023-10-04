// queue::emplace
#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue 循环队列头、尾操作 
#include <string>         // std::string, std::getline(string)

int main ()
{
  std::queue<std::string> myqueue;

  myqueue.emplace ("First sentence");//同插入，效率更高，内存管理机制改变 
  myqueue.emplace ("Second sentence");//using C++11,or Complier Error

  std::cout << "myqueue contains:\n";
  while (!myqueue.empty())
  {
    std::cout << myqueue.front() << '\n';
    myqueue.pop();
  }

  return 0;
}
