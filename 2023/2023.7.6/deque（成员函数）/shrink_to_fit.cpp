// deque::shrink_to_fit
#include <iostream>
#include <deque>

int main ()
{
  std::deque<int> mydeque (100);
  std::cout << "1. size of mydeque: " << mydeque.size() << '\n';

  mydeque.resize(10);
  std::cout << "2. size of mydeque: " << mydeque.size() << '\n';

  mydeque.shrink_to_fit();

  return 0;
}
