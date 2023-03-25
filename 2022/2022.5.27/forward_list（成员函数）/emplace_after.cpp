// forward_list::emplace_after  C++11引入的插入（在尾部插入）
#include <iostream>
#include <forward_list>

int main ()
{
  std::forward_list< std::pair<int,char> > mylist;
  auto it = mylist.before_begin();

  it = mylist.emplace_after ( it, 100, 'x' );
  it = mylist.emplace_after ( it, 200, 'y' );
  it = mylist.emplace_after ( it, 300, 'z' );

  std::cout << "mylist contains:";
  for (auto& x: mylist)
    std::cout << " (" << x.first << "," << x.second << ")";

  std::cout << '\n';
  return 0;
}
