// deque::emplace
#include <iostream>
#include <deque>

int main ()
{
  std::deque<int> mydeque = {10,20,30};

  auto it = mydeque.emplace ( mydeque.begin()+1, 100 );
  mydeque.emplace ( it, 200 );
  mydeque.emplace ( mydeque.end(), 300 );

  std::cout << "mydeque contains:";
  for (auto& x: mydeque)
    std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}

