// list::pop_back  ɾ�����һ��Ԫ�� 
#include <iostream>
#include <list>

int main ()
{
  std::list<int> mylist;
  int sum (0);
  mylist.push_back (100);
  mylist.push_back (200);
  mylist.push_back (300);

  while (!mylist.empty())
  {
    sum+=mylist.back();
    mylist.pop_back();
  }

  std::cout << "The elements of mylist summed " << sum << '\n';

  return 0;
}
