// forward_list::swap
#include <iostream>
#include <forward_list>

int main ()
{
  std::forward_list<int> first = {10, 20, 30};
  std::forward_list<int> second = {100, 200};
  std::forward_list<int>::iterator it;

  first.swap(second);

  std::cout << "first contains:";
  for (int& x: first) std::cout << ' ' << x;
  std::cout << '\n';

  std::cout << "second contains:";
  for (int& x: second) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}
