// assignment operator with forward_list
#include <iostream>
#include <forward_list>

template<class Container>
Container by_two (const Container& x) {
  Container temp(x); for (auto& x:temp) x*=2; return temp;
}

int main ()
{
  std::forward_list<int> first (4);      // 4 ints
  std::forward_list<int> second (3,5);   // 3 ints with value 5

  first = second;                        // copy assignment
  second = by_two(first);                // move assignment

  std::cout << "first: ";
  for (int& x : first) std::cout << ' ' << x;
  std::cout << '\n';

  std::cout << "second: ";
  for (int& x : second) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}
