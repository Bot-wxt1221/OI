// remove from forward_list  ɾ��ָ��Ԫ�� 
#include <iostream>
#include <forward_list>

int main ()
{
  std::forward_list<int> mylist = {10, 20, 30, 40, 30, 20, 10};

  mylist.remove(20);

  std::cout << "mylist contains:";
  for (int& x: mylist) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}
