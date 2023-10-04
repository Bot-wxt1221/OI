// swap (list overload)
#include <iostream>
#include <list>

int main ()
{
  std::list<int> foo (3,100);   // three ints with a value of 100
  std::list<int> bar (5,200);   // five ints with a value of 200

  std::swap(foo,bar);

  std::cout << "foo contains:";
  for (std::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (std::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
