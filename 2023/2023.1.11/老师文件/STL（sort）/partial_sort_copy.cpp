// partial_sort_copy example
#include <iostream>     // std::cout
#include <algorithm>    // std::partial_sort_copy
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

int main () {
  int myints[] = {9,8,7,6,5,4,3,2,1};
  std::vector<int> myvector (5);

  // using default comparison (operator <):
  std::partial_sort_copy (myints, myints+9, myvector.begin(), myvector.end());

  // using function as comp
  std::partial_sort_copy (myints, myints+9, myvector.begin(), myvector.end(), myfunction);

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
