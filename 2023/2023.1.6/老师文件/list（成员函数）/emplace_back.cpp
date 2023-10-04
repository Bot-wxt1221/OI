// list::emplace_back
#include <iostream>
#include <list>

int main ()
{
  std::list< std::pair<int,char> > mylist;

  mylist.emplace_back(10,'a');
  mylist.emplace_back(20,'b');
  mylist.emplace_back(30,'c');

  std::cout << "mylist contains:";
  for (auto& x: mylist)
    std::cout << " (" << x.first << "," << x.second << ")";

  std::cout << std::endl;
  return 0;
}
