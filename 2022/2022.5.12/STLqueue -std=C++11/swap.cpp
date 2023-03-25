// queue::swap
#include <iostream>       // std::cout
#include <queue>          // std::queue

int main ()
{
  std::queue<int> foo,bar;
  foo.push (10); foo.push(20); foo.push(30);
  bar.push (111); bar.push(222);

  foo.swap(bar);//using C++11, or Compiler Error 元素个数不一样，成功交换 

  std::cout << "size of foo: " << foo.size() << '\n';
  while(!foo.empty()){
  	std::cout<<foo.front()<<' '; 
  	foo.pop();
  }
  std::cout<<std::endl;
  std::cout << "size of bar: " << bar.size() << '\n';
   while(!bar.empty()){
  	std::cout<<bar.front()<<' '; 
  	bar.pop();
  }
  std::cout<<std::endl;
  
 
  return 0;
}
