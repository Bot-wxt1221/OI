// forward_list::splice_after  将一个list的元素删除并插入另一个list 
#include <iostream>
#include <forward_list>

int main ()
{
  std::forward_list<int> first = { 1, 2, 3 };
  std::forward_list<int> second = { 10, 20, 30 };

  auto it = first.begin();  // points to the 1

  first.splice_after ( first.before_begin(), second );
                          // first: 10 20 30 1 2 3
                          // second: (empty)
                          // "it" still points to the 1 (now first's 4th element)
std::cout<<*it<<std::endl;
  std::cout << "first contains:";
  for (int& x: first) std::cout << " " << x;
  std::cout << std::endl;

  std::cout << "second contains:";
  for (int& x: second) std::cout << " " << x;
  std::cout << std::endl;
  std::cout<<*it<<std::endl;
  second.splice_after ( second.before_begin(), first, first.begin(), it);
                          // first: 10 1 2 3
                          // second: 20 30
	std::cout<<*it<<std::endl;

  std::cout << "first contains:";
  for (int& x: first) std::cout << " " << x;
  std::cout << std::endl;

  std::cout << "second contains:";
  for (int& x: second) std::cout << " " << x;
  std::cout << std::endl;
  std::cout<<*it<<std::endl;
  first.splice_after ( first.before_begin(), second, second.begin() );
                          // first: 30 10 1 2 3
                          // second: 20
                          // * notice that what is moved is AFTER the iterator
                          std::cout<<*it<<std::endl;
  std::cout << "first contains:";
  for (int& x: first) std::cout << " " << x;
  std::cout << std::endl;

  std::cout << "second contains:";
  for (int& x: second) std::cout << " " << x;
  std::cout << std::endl;
  std::cout << "first contains:";
  for (int& x: first) std::cout << " " << x;
  std::cout << std::endl;

  std::cout << "second contains:";
  for (int& x: second) std::cout << " " << x;
  std::cout << std::endl;

std::cout<<*it<<std::endl;
  return 0;
}
