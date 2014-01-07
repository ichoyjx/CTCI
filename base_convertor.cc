#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

const int BUFFSIZE = 100;

string DToA(int dvalue, int base){

  if(base < 2 || base > 36) return 'ERROR';

  char buff[BUFFSIZE] = {0};
  int pos = BUFFSIZE - 1, tmpValue = dvalue, tv;

  while(true){
    tv = tmpValue % base;
    buff[--pos] = tv > 9 ? (tv - 10) + char('A') : tv + char('0');
    if((tmpValue /= base) == 0)
      break;
  }
  string result (&buff[pos]);
  return result;
}

int AToD(string dvalue, int base){
  if(base < 2 || base > 36) return -1;

  int result = 0;
  int maxPos = dvalue.length();
  int tv;
  for(int index = 0; index < maxPos; index++){
    tv = dvalue[index];
    if(isalpha(tv)){
      if(islower(tv)) tv = toupper(tv);
      tv -= char('A');
      tv += 10;
      if(tv > base) return int(-1);
    }
    else if(isdigit(tv)){
      tv -= char('0');
      if(tv > base) return int(-1);
    }
    else return int(-1);//invilad string
    result += tv * pow(base, maxPos - index - 1);
  }
  return result;
}

int main() {
  int num, base;
  cin >> num >> base;
  cout << DToA(num, base) << endl;
  //cout << AtoD(num, base) << endl;

  return 0;
}
