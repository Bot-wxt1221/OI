// forward_list::cbefore_begin  前面一个元素的前一个位置 （const） 
#include <iostream>
#include <forward_list>

int main ()
{
  std::forward_list<int> mylist = {77, 2, 16};

  mylist.insert_after ( mylist.cbefore_begin(), 19 );

  std::cout << "mylist contains:";
  for ( int& x: mylist ) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}
