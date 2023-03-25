// remove from list  É¾³ıÖ¸¶¨ÔªËØ 
#include <iostream>
#include <list>

int main ()
{
  int myints[]= {17,89,7,14,89};
  std::list<int> mylist (myints,myints+5);

  mylist.remove(89);

  std::cout << "mylist contains:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
