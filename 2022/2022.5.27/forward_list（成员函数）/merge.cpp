// forward_list::merge  将两个有序序列合并成另一个有序队列 （类似于合并排序的合并过程） 
#include <iostream>
#include <forward_list>
#include <functional>

int main ()
{
  std::forward_list<double> first = {7.7, 2.9, 3.1};
  std::forward_list<double> second = {1.4, 4.2, 3.1};
  std::forward_list<double> third = {6.2, 3.7, 7.1};

  first.sort();
  second.sort();
    std::cout << "first contains:";
  for (double& x: first) std::cout << " " << x;
  std::cout << std::endl;
    std::cout << "second contains:";
  for (double& x: second) std::cout << " " << x;
  std::cout << std::endl;
  first.merge(second);

  std::cout << "first contains:";
  for (double& x: first) std::cout << " " << x;
  std::cout << std::endl;
    std::cout << "second contains:";
  for (double& x: second) std::cout << " " << x;
  std::cout << std::endl;


  first.sort (std::greater<double>());
  third.sort (std::greater<double>());
    std::cout << "first contains:";
  for (double& x: first) std::cout << " " << x;
  std::cout << std::endl;
    std::cout << "second contains:";
  for (double& x: second) std::cout << " " << x;
  std::cout << std::endl;
  first.merge (third, std::greater<double>());

  std::cout << "first contains:";
  for (double& x: first) std::cout << " " << x;
  std::cout << std::endl;
    std::cout << "second contains:";
  for (double& x: second) std::cout << " " << x;
  std::cout << std::endl;

  return 0;
}
