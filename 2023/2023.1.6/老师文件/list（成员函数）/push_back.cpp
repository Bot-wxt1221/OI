// list::push_back
#include <iostream>
#include <list>

int main ()
{
  std::list<int> mylist;
  int myint;

  std::cout << "Please enter some integers (enter 0 to end):\n";

  do {
    std::cin >> myint;
    mylist.push_back (myint);
  } while (myint);

  std::cout << "mylist stores " << mylist.size() << " numbers.\n";

  return 0;
}
