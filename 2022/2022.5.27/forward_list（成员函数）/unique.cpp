// forward_list::unique  去重   相邻的两个元素如果满足传入的函数，则删掉较小的 
#include <iostream>
#include <cmath>
#include <forward_list>

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
bool is_near_object(double a,double b){
	if(fabs(a-b)<5){
		return 1;
	}
	return 0;
}
bool cmp(double a,double b){
	return a>b;
} 
int main ()
{

  std::forward_list<double> mylist = { 15.2, 73.0, 3.14, 15.85, 69.5,
                                       73.0, 3.99, 15.2, 69.2,  18.5 };

  mylist.sort();                       //   3.14,  3.99, 15.2, 15.2, 15.85
                                       //  18.5,  69.2,  69.5, 73.0, 73.0

  mylist.unique();                     //   3.14,  3.99, 15.2, 15.85
                                       //  18.5,  69.2,  69.5, 73.0

  mylist.unique (same_integral_part);  //  3.14, 15.2, 18.5,  69.2, 73.0
  std::cout << "mylist contains:";
  for (double& x: mylist) std::cout << ' ' << x;
  std::cout << '\n';

  mylist.unique (is_near_object);      //  3.14, 15.2, 69.2

  std::cout << "mylist contains:";
  for (double& x: mylist) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}
