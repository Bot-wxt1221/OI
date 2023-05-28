// list::get_allocator
#include <iostream>
#include <list>

int main ()
{
  std::list<int> mylist;
  int * p;

  // allocate an array of 5 elements using mylist's allocator:
  p=mylist.get_allocator().allocate(5);

  // assign some values to array
  for (int i=0; i<5; ++i) p[i]=i;

  std::cout << "The allocated array contains:";
  for (int i=0; i<5; ++i) std::cout << ' ' << p[i];
  std::cout << '\n';

  mylist.get_allocator().deallocate(p,5);

  return 0;
}
