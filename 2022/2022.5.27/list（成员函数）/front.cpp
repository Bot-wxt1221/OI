// list::front  第一个元素 
#include <iostream>
#include <list>

int main ()
{
  std::list<int> mylist;

  mylist.push_back(77);
  mylist.push_back(22);

  // now front equals 77, and back 22

  mylist.front() -= mylist.back();

  std::cout << "mylist.front() is now " << mylist.front() << '\n';

  return 0;
}
