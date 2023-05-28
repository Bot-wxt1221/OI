// deque::front
#include <iostream>
#include <deque>

int main ()
{
  std::deque<int> mydeque;

  mydeque.push_front(77);
  mydeque.push_back(20);

  mydeque.front() -= mydeque.back();

  std::cout << "mydeque.front() is now " << mydeque.front() << '\n';

  return 0;
}
