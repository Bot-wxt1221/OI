// clearing deques
#include <iostream>
#include <deque>

int main ()
{
  unsigned int i;
  std::deque<int> mydeque;
  mydeque.push_back (100);
  mydeque.push_back (200);
  mydeque.push_back (300);

  std::cout << "mydeque contains:";
  for (std::deque<int>::iterator it = mydeque.begin(); it!=mydeque.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  mydeque.clear();
  mydeque.push_back (1101);
  mydeque.push_back (2202);

  std::cout << "mydeque contains:";
  for (std::deque<int>::iterator it = mydeque.begin(); it!=mydeque.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
