// forward_list::insert_after  ����֮�����Ԫ�� 
#include <iostream>
#include <array>
#include <forward_list>

int main ()
{
  std::array<int,3> myarray = { 11, 22, 33 };
  std::forward_list<int> mylist;
  std::forward_list<int>::iterator it;

  it = mylist.insert_after ( mylist.before_begin(), 10 );          // 10
                                                                   //  ^  <- it
  it = mylist.insert_after ( it, 2, 20 );                          // 10 20 20
                                                                   //        ^
  it = mylist.insert_after ( it, myarray.begin(), myarray.end() ); // 10 20 20 11 22 33
                                                                   //                 ^
  it = mylist.begin();                                             //  ^
  it = mylist.insert_after ( it, {1,2,3} );                        // 10 1 2 3 20 20 11 22 33
                                                                   //        ^

  std::cout << "mylist contains:";
  for (int& x: mylist) std::cout << ' ' << x;
  std::cout << '\n';
  return 0;
}
