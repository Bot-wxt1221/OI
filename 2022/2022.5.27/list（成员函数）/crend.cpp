// list::crbegin/crend  rbegin/rend µÄconstĞÎÊ½ 
#include <iostream>
#include <deque>

int main ()
{
  std::list<int> mylist = {1,2,4,8,16};

  std::cout << "mylist backwards:";
  for (auto rit = mylist.crbegin(); rit != mylist.crend(); ++rit)
    std::cout << ' ' << *rit;
  std::cout << '\n';

  return 0;
}
