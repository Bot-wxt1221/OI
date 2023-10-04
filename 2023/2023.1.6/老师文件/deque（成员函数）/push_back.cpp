// deque::push_back
#include <iostream>
#include <deque>

int main ()
{
  std::deque<int> mydeque;
  int myint;

  std::cout << "Please enter some integers (enter 0 to end):\n";

  do {
    std::cin >> myint;
    mydeque.push_back (myint);
  } while (myint);

  std::cout << "mydeque stores " << (int) mydeque.size() << " numbers.\n";

  return 0;
}
