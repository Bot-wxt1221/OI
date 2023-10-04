// resizing deque
#include <iostream>
#include <deque>

int main ()
{
  std::deque<int> mydeque;
  std::deque<int>::iterator it;

  // set some initial content:
  for (int i=1; i<10; ++i) mydeque.push_back(i);

  mydeque.resize(5);
  mydeque.resize(8,100);
  mydeque.resize(12);

  std::cout << "mydeque contains:";
  for (std::deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
