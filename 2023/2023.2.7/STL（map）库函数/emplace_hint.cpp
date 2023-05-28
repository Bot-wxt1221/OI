// map::emplace_hint
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;
  auto it = mymap.end();

  it = mymap.emplace_hint(it,'b',10);
  mymap.emplace_hint(it,'a',12);
  mymap.emplace_hint(mymap.end(),'c',14);

  std::cout << "mymap contains:";
  for (auto& x: mymap)
    std::cout << " [" << x.first << ':' << x.second << ']';
  std::cout << '\n';

  return 0;
}
