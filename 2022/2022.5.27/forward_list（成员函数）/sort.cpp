// forward_list::sort  ≈≈–Ú 
#include <iostream>
#include <forward_list>
#include <functional>

int main ()
{
  std::forward_list<int> mylist = {22, 13, 5, 40, 90, 62, 31};

  mylist.sort();

  std::cout << "default sort (operator<):";
  for (int& x: mylist) std::cout << ' ' << x;
  std::cout << '\n';

  mylist.sort(std::greater<int>());

  std::cout << "sort with std::greater():";
  for (int& x: mylist) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}
