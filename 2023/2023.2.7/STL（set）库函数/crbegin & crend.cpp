// set::crbegin/crend
#include <iostream>
#include <set>

int main ()
{
  std::set<int> myset = {50,20,60,10,25};

  std::cout << "myset backwards:";
  for (auto rit=myset.crbegin(); rit != myset.crend(); ++rit)
    std::cout << ' ' << *rit;

  std::cout << '\n';

  return 0;
}
