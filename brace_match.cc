#include<iostream>
#include<stack>
#include<cstdio>
#include<cstring>
using namespace std;

bool is_brace(char c) {
  if (c!='{' && c!='}' &&
      c!='(' && c!=')' &&
      c!='[' && c!=']' &&
      c!='<' && c!='>') {
    return false;
  }
  return true;
}

bool cmp(char a, char b) {
  if (a=='{' && b=='}') return true;
  if (a=='(' && b==')') return true;
  if (a=='[' && b==']') return true;
  if (a=='<' && b=='>') return true;

  return false;
}

int main() {
  stack<char> s;
  char c[100];
  int i, l;
  scanf("%s", c);

  // test case 0: <fqg{wth(wrn{a} { }245f)}hw><>
  // test case 1: <fqg{wth(wrn{a} } }245f)}hw><>

  l = strlen(c);
  for (i=0; i<l; i++) {
    if (!is_brace(c[i])) continue;

    if (!s.empty() && cmp(s.top(),c[i]))
      s.pop();
    else s.push(c[i]);
  }

  if (!s.empty()) printf("NO\n");
  else printf("YES\n");

  return 0;
}
