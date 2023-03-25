// forward_list::emplace_front    C++11引入的插入（在头部插入） 
#include <iostream>
#include <forward_list>

int main ()
{
  std::forward_list< std::pair<int,char> > mylist;

  mylist.emplace_front(10,'a');
  mylist.emplace_front(20,'b');
  mylist.emplace_front(30,'c');

  std::cout << "mylist contains:";
  for (auto& x: mylist)
    std::cout << " (" << x.first << "," << x.second << ")";

  std::cout << std::endl;
  return 0;
}
