// deque::at
#include <iostream>
#include <deque>

int main ()
{
  std::deque<unsigned> mydeque (10);   // 10 zero-initialized unsigneds

  // assign some values:
  for (unsigned i = 0; i < mydeque.size(); i++)
    mydeque.at(i) = i * i;   

  std::cout << "mydeque contains:";
  for (unsigned i = 0; i < mydeque.size(); i++)
    std::cout << ' ' << mydeque.at(i);

  std::cout << '\n';

  return 0;
}
