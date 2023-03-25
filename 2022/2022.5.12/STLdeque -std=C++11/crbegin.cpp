// deque::crbegin/crend const_right_begin/const_right_end
#include <iostream>
#include <deque>

int main ()
{
  std::deque<int> mydeque = {1,2,3,4,5};

  std::cout << "mydeque backwards:";
  for (auto rit = mydeque.crbegin(); rit != mydeque.crend(); ++rit)
    std::cout << ' ' << *rit;
  std::cout << '\n';

  return 0;
}
