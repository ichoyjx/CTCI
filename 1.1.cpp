#include <iostream>
#include <cstring>
#include <bitset>

#define INPUT_1 "qwfeprj8534#G*$H!)N"
#define INPUT_2 "asdfpienrghwthqwfxc"

using namespace std;

bool isUnique (string str) {
  bitset<256> ascii_bit;
  ascii_bit.reset();

  int i;
  for (i=0; i<str.length(); i++) {
    if ( !ascii_bit[str[i]] ) { // 0
      ascii_bit.flip(str[i]);
    } else {
      return false;
    }
  }

  return true;
}

int main() {

  if ( isUnique(INPUT_1) ) {
    cout << INPUT_1 << " is unique" << endl;
  }

  if ( isUnique(INPUT_2) ) {
    cout << INPUT_2 << " is unique" << endl;
  }

  cout << endl;
  return 0;
}
