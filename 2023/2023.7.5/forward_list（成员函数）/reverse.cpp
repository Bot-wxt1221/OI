// reversing forward_list
#include <iostream>
#include <forward_list>

int main ()
{
  std::forward_list<int> mylist = {10, 20, 30, 40};

  mylist.reverse();

  std::cout << "mylist contains:";
  for (int& x: mylist) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}
