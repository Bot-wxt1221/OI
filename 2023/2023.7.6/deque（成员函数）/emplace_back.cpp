// deque::emplace_back
#include <iostream>
#include <deque>

int main ()
{
  std::deque<int> mydeque = {10,20,30};

  mydeque.emplace_back (100);
  mydeque.emplace_back (200);

  std::cout << "mydeque contains:";
  for (auto& x: mydeque)
    std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}
