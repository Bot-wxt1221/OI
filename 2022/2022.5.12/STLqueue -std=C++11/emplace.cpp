// queue::emplace
#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue ѭ������ͷ��β���� 
#include <string>         // std::string, std::getline(string)

int main ()
{
  std::queue<std::string> myqueue;

  myqueue.emplace ("First sentence");//ͬ���룬Ч�ʸ��ߣ��ڴ������Ƹı� 
  myqueue.emplace ("Second sentence");//using C++11,or Complier Error

  std::cout << "myqueue contains:\n";
  while (!myqueue.empty())
  {
    std::cout << myqueue.front() << '\n';
    myqueue.pop();
  }

  return 0;
}
