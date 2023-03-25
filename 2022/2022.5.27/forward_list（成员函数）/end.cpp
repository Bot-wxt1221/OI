// forward_list::end example  ���һ��Ԫ�ص���һ��Ԫ�صĵ����� 
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
