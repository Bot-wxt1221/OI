// deque::begin
#include <iostream>
#include <deque>

int main ()
{
  std::deque<int> mydeque;

  for (int i=1; i<=5; i++) mydeque.push_back(i);

  std::cout << "mydeque contains:";

  std::deque<int>::iterator it = mydeque.begin();

  while (it != mydeque.end())
    std::cout << ' ' << *it++;

  std::cout << '\n';

  return 0;
}
