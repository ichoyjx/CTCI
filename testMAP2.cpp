#include <iostream>
#include <map>
using namespace std;

bool fncomp(char lhs,char rhs)
{
  return lhs<rhs;
}

struct classcomp
{
  bool operator()(const char& lhs,const char& rhs)
  {
    return lhs<rhs;
  }
};

int main(int argc, char* argv[]) {
  map<char,int> mymap;
  mymap['a']=10;
  mymap['b']=60;
  mymap['c']=30;
  mymap['d']=90;
  mymap['e']=50;

  map<char,int> second(mymap);
  map<char,int> third(mymap.begin(),mymap.end());
  map<char,int,classcomp> fourth;
  bool(*fn_pt)(char,char)=fncomp;
  map<char,int,bool(*)(char,char)> fifth(fn_pt);
  map<char,int>::key_compare key_comp;

  map<char,int>::iterator it;
  it=mymap.begin();
  for (it; it!=mymap.end(); it++) {
    cout << it->first << ":" << it->second << endl;
  }

  cout<<"================================="<<endl;
  second.clear();
  second['a'] = 1002;
  second['b'] = 10023;
  second['c'] = 100234;
  second['d'] = 1002345;

  // output one, then abandon it
  while (!second.empty()) {
    cout << second.begin()->first << " => ";
    cout << second.begin()->second << endl;
    second.erase(second.begin());
  }
  cout<<"================================="<<endl;
  mymap.insert(pair<char,int>('f',100) );
  mymap.insert(pair<char,int>('g',200) );
  cout << "f => " << mymap.find('f')->second << endl;
  cout << "g => " << mymap.find('g')->second << endl;

  cout<<"================================="<<endl;
  key_comp=mymap.key_comp();
  cout << "mymap contains:\n";

  char highest = 'd';//(mymap.begin())->first;     // key value of last element

  it=mymap.begin();
  do {
    cout << (*it).first << " => " << (*it).second << endl;
  } while ( key_comp((*it++).first, highest) );

  cout << endl;
  return 0;
}
