// set::cbegin/cend
#include <iostream>
#include <set>

int main ()
{
  std::set<int> myset = {50,20,60,10,25};

  std::cout << "myset contains:";
  for (auto it=myset.cbegin(); it != myset.cend(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
