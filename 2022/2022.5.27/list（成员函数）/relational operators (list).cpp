// list comparisons  ±È½Ï 
#include <iostream>
#include <list>

int main ()
{
  std::list<int> a = {10, 20, 30};
  std::list<int> b = {10, 20, 30};
  std::list<int> c = {30, 20, 10};

  if (a==b) std::cout << "a and b are equal\n";
  if (b!=c) std::cout << "b and c are not equal\n";
  if (b<c) std::cout << "b is less than c\n";
  if (c>b) std::cout << "c is greater than b\n";
  if (a<=b) std::cout << "a is less than or equal to b\n";
  if (a>=b) std::cout << "a is greater than or equal to b\n";

  return 0;
}
