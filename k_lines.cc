#include <iostream>
#include <fstream>

using namespace std;

int main(){
  const int k = 4;

  ifstream in("BST.cpp");

  string line[k];
  string tmp;
  int lines = 0, begin, count;

  while ( getline(in, tmp) ) {
    line[lines % k] = tmp;
    lines++;
  }

  if (lines < k) {
    begin = 0;
    count = lines;
  } else {
    begin = lines % k;
    count = k;
  }

  for (int i=0; i<count; i++) {
    cout << line[(begin+i) % k] << endl;
  }

  in.close();
  return 0;
}
