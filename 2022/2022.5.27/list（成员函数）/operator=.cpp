// assignment operator with lists  ÷ÿ‘ÿ∏≥÷µ 
#include <iostream>
#include <list>

int main ()
{
  std::list<int> first (3);      // list of 3 zero-initialized ints
  std::list<int> second (5);     // list of 5 zero-initialized ints

  second = first;
  first = std::list<int>();

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  return 0;
}
