// list::max_size  ����С 
#include <iostream>
#include <list>

int main ()
{
  unsigned int i;
  std::list<int> mylist;

  std::cout << "Enter number of elements: ";
  std::cin >> i;

  if (i<mylist.max_size()) mylist.resize(i);
  else std::cout << "That size exceeds the limit.\n";

  return 0;
}
