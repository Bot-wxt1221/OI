// forward_list::end example  最后一个元素的下一个元素的迭代器 
#include <iostream>
#include <forward_list>

int main ()
{
  std::forward_list<int> mylist = { 10, 20, 30, 40 };

  std::cout << "mylist contains:";
  for ( auto it = mylist.begin(); it != mylist.end(); ++it )
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
