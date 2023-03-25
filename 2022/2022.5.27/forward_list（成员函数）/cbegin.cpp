// forward_list::cbegin/cend example   第一个元素的迭代器（const） 
#include <iostream>
#include <forward_list>

int main ()
{
  std::forward_list<int> mylist = { 21, 32, 12 };

  std::cout << "myarray contains:";
  for ( auto it = mylist.cbegin(); it != mylist.cend(); ++it )
    std::cout << ' ' << *it;   // cannot modify *it

  std::cout << '\n';

  return 0;
}
