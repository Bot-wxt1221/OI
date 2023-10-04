// stack::emplace
#include <iostream>       // std::cin, std::cout
#include <stack>          // std::stack
#include <string>         // std::string, std::getline(string)

int main ()
{
  std::stack<std::string> mystack;

  mystack.emplace ("First sentence");
  mystack.emplace ("Second sentence");

  std::cout << "mystack contains:\n";
  while (!mystack.empty())
  {
    std::cout << mystack.top() << '\n';
    mystack.pop();
  }

  return 0;
}
