// deque::back
#include <iostream>
#include <deque>

int main ()
{
  std::deque<int> mydeque;

  mydeque.push_back(10);

  while (mydeque.back() != 0)
    mydeque.push_back ( mydeque.back() - 1 );

  std::cout << "mydeque contains:";

  for (std::deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
