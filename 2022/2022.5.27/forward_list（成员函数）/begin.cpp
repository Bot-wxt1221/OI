// forward_list::begin example    ��һ��λ�õĵ����� 
#include <iostream>
#include <forward_list>

int main ()
{
  std::forward_list<int> mylist = { 34, 77, 16, 2 };

  std::cout << "mylist contains:";
  for ( auto it = mylist.begin(); it != mylist.end(); ++it )
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
