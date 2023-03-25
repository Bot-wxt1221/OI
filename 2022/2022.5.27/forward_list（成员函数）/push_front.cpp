// forward_list::push_front   ÔÚÍ·²åÈë 
#include <iostream>
#include <forward_list>
using namespace std;

int main ()
{
  forward_list<int> mylist = {77, 2, 16};
  mylist.push_front (19);
  mylist.push_front (34);

  std::cout << "mylist contains:";
  for (int& x: mylist) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}
