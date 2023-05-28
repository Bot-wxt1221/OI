// assignment operator with deques
#include <iostream>
#include <deque>

int main ()
{
  std::deque<int> first (3);    // deque with 3 zero-initialized ints
  std::deque<int> second (5);   // deque with 5 zero-initialized ints

  second = first;
  first = std::deque<int>();

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  return 0;
}
