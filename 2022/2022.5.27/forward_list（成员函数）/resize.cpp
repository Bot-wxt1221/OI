// resizing forward_list  ÷ÿ÷√¥Û–° 
#include <iostream>
#include <forward_list>

int main ()
{
  std::forward_list<int> mylist = {10, 20, 30, 40, 50};
                                // 10 20 30 40 50
  mylist.resize(6);  
  std::cout << "mylist contains:";
  for (int& x: mylist) std::cout << ' ' << x;
  std::cout << '\n';           // 10 20 30 40 50 0
  
  mylist.resize(3);  
  std::cout << "mylist contains:";
  for (int& x: mylist) std::cout << ' ' << x;
  std::cout << '\n';    //10 20 30
  mylist.resize(5,100);        

  std::cout << "mylist contains:";
  for (int& x: mylist) std::cout << ' ' << x;
  std::cout << '\n'; // 10 20 30 100 100

  return 0;
}
