#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef char Type;
#define INPUT "FOLLOW UP"

struct LNode {
  Type elem;
  LNode * next;
};

LNode * insertNode (LNode *L, Type _elem) {
  LNode *p = L->next;
  p = (LNode *) malloc (sizeof(LNode));
  p->elem = _elem;
  p->next = NULL;
  L->next = p;

  return p;
}

void printList (LNode *L) {
  LNode *p = L;
  cout << p->elem;
  p = p->next;

  while (p) {
    cout << " -> " << p->elem;
    p = p->next;
  }

  cout << endl;
}

int main() {
  LNode *Head = NULL, *p = NULL;
  Head = (LNode *) malloc (sizeof(LNode));
  Head->elem = '$';
  Head->next = NULL;
  p = Head;

  string s = INPUT;
  int i;
  for (i=0; i<s.length(); i++) {
    p = insertNode(p, s[i]);
    //cout << p->elem << endl;
  }

  printList(Head);

  return 0;
}
