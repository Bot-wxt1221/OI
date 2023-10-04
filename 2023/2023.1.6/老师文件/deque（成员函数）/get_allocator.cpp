// deque::get_allocator
#include <iostream>
#include <deque>

int main ()
{
  std::deque<int> mydeque;
  int * p;
  unsigned int i;

  // allocate an array with space for 5 elements using deque's allocator:
  p = mydeque.get_allocator().allocate(5);

  // construct values in-place on the array:
  for (i=0; i<5; i++) mydeque.get_allocator().construct(&p[i],i);

  std::cout << "The allocated array contains:";
  for (i=0; i<5; i++) std::cout << ' ' << p[i];
  std::cout << '\n';

  // destroy and deallocate:
  for (i=0; i<5; i++) mydeque.get_allocator().destroy(&p[i]);
  mydeque.get_allocator().deallocate(p,5);

  return 0;
}
