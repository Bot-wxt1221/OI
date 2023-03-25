// forward_list::before_begin    ǰ��һ��Ԫ�ص�ǰһ��λ�� 
#include <iostream>
#include <forward_list>

int main ()
{
  std::forward_list<int> mylist = {20, 30, 40, 50};

  mylist.insert_after ( mylist.before_begin(), 11 );

  std::cout << "mylist contains:";
  for ( int& x: mylist ) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}
