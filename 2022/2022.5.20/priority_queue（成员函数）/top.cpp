// priority_queue::top
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue

int main ()
{
  std::priority_queue<int> mypq;

  mypq.push(10);
  mypq.push(20);
  mypq.push(15);

  std::cout << "mypq.top() is now " << mypq.top() << '\n';

  return 0;
}
