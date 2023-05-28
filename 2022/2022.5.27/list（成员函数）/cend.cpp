// list::cbegin/cend  begin/end µÄ const ĞÎÊ½ 
#include <iostream>
#include <list>

int main ()
{
  std::list<int> mylist = {5,10,15,20};

  std::cout << "mylist contains:";

  for (auto it = mylist.cbegin(); it != mylist.cend(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
