/*
 * 2.1, 2.3, 2.6
 * Brian
 */

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef char Type;
#define INPUT "FOLLOW UP DUDE"

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

LNode * deleteNext (LNode *L) {
  if (L == NULL) { return L; }

  LNode *deleted = L->next;
  L->next = L->next->next;
  //L->next->next = NULL;

  delete deleted;
  return L->next;
}

void deleteDups (LNode *L) {
  // p, q will point to the first real node
  LNode *p = L->next;
  LNode *q = p;
  LNode *pre = L; // point to the previous one

  while (p) {
    while (q) {
      if ( (p!=q) && (q->elem==p->elem) ) {
        cout << "deleting " << pre->next->elem << endl;
        q = deleteNext(pre);   
      } else {
        pre = pre->next;
        q = q->next;
      }
    }

    pre = p;
    p = p->next;
    q = p;
  }
}

int main() {
  LNode *Head = NULL, *p = NULL, *tmp;
  Head = (LNode *) malloc (sizeof(LNode));
  Head->elem = '$';
  Head->next = NULL;
  p = Head;
  tmp = Head;

  string s = INPUT;
  int i;
  for (i=0; i<s.length(); i++) {
    tmp = p;
    p = insertNode(p, s[i]);
    //cout << p->elem << endl;
  }

  printList(Head);

  // delete the duplicate nodes
  deleteDups(Head);
  printList(Head);

  return 0;
}
