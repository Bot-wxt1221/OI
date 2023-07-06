// inserting into a deque
#include <iostream>
#include <deque>
#include <vector>

int main ()
{
  std::deque<int> mydeque;

  // set some initial values:
  for (int i=1; i<6; i++) mydeque.push_back(i); // 1 2 3 4 5

  std::deque<int>::iterator it = mydeque.begin();
  ++it;

  it = mydeque.insert (it,10);                  // 1 10 2 3 4 5
  // "it" now points to the newly inserted 10

  mydeque.insert (it,2,20);                     // 1 20 20 10 2 3 4 5
  // "it" no longer valid!

  it = mydeque.begin()+2;

  std::vector<int> myvector (2,30);
  mydeque.insert (it,myvector.begin(),myvector.end());
                                                // 1 20 30 30 20 10 2 3 4 5

  std::cout << "mydeque contains:";
  for (it=mydeque.begin(); it!=mydeque.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
