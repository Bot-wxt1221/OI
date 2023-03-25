// forward_list::pop_front  É¾³ıÊ×ÔªËØ 
#include <iostream>
#include <forward_list>

int main ()
{
  std::forward_list<int> mylist = {10, 20, 30, 40};

  std::cout << "Popping out the elements in mylist:";
  while (!mylist.empty())
  {
    std::cout << ' ' << mylist.front();
    mylist.pop_front();
  }

  std::cout << '\n';

  return 0;
}
