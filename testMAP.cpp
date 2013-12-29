#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

int main() {
  map<char,int> mymap;
  pair<map<char,int>::iterator, bool> pRet;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  mymap.insert(pair<char,int>('d',400));
  mymap.insert(pair<char,int>('e',500));

  pRet = mymap.insert(pair<char,int>('f',600));
  if (pRet.second)
    cout << "Correct!" << endl;

  map<char,int>::iterator it = mymap.begin();
  mymap.insert(it, pair<char,int>('g',700));
  mymap.insert(it, pair<char,int>('h',800));

  map<char,int> anothermap;

  // [begin, 'd')
  anothermap.insert(mymap.begin(), mymap.find('d'));

  cout << "mymap:" << endl;
  for (it=mymap.begin(); it!=mymap.end(); it++)
    cout << (*it).first<<"=>" << (*it).second << endl;

  cout << "anothermap:" << endl;
  for(it=anothermap.begin(); it!=anothermap.end(); it++)
    cout << (*it).first << "=>" << (*it).second << endl;

  return 0;
}
