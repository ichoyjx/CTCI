#include <iostream>
#include <bitset>
using namespace std;

int main ()
{
  bitset<16> mybits(string("1010101000"));

  if (mybits.any())
    cout << mybits << " has " << (int)mybits.count() << " bits set.\n";
  else cout << "mybits has no bits set.\n";

  // ... 3 2 1 0
  cout<<mybits.flip(2)<<endl;
  cout<<mybits.flip()<<endl;

  cout << mybits<<" as an integer is: " << mybits.to_ulong()<< endl;

  return 0;
}
