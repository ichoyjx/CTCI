#include <iostream>
#include <cstring>

using namespace std;

struct Node {
  int data;
  Node *lchild, *rchild, *parent;
  Node(): lchild(NULL), rchild(NULL), parent(NULL) { }
};

class BST {
private:
  static const int kMax = 1000;
  Node *root_, *parent_, nodes_[kMax];
  int size_;

private:
  Node* minimum(Node* node);
  Node* maximum(Node* node);
  Node* successor(Node* node);
  Node* predecessor(Node* node);
  void Insert(Node* &node, int x);
  void InorderTraver(Node* node);
  Node* Find(Node* node, int x);

public:
  BST(): root_(NULL), parent_(NULL), size_(0) {
    memset(nodes_, '\0', sizeof(nodes_));
  }
  void Insert(int x);
  void InorderTraver();
  Node* Find(int x);
  void Remove(Node* z);
};

Node* BST::minimum(Node* node) {
  if(node == NULL) return NULL;
  while(node->lchild)
    node = node->lchild;
  return node;
}

Node* BST::maximum(Node* node) {
  if(node == NULL) return NULL;
  while(node->rchild)
    node = node->rchild;
  return node;
}

Node* BST::successor(Node* node) {
  if(node->rchild)
    return minimum(node->rchild);
  Node *y = node->parent;
  while(y && node==y->rchild) {
    node = y;
    y = node->parent;
  }
  return y;
}

Node* BST::predecessor(Node* node) {
  if(node->lchild)
    return maximum(node->lchild);
  Node *y = node->parent;
  while(y && node==y->lchild) {
    node = y;
    y = node->parent;
  }
  return y;
}

void BST::Insert(Node* &node, int x) {
  if(node == NULL) {
    nodes_[size_].data = x;
    nodes_[size_].parent = parent_;
    node = &nodes_[size_];
    ++size_;
    return;
  }
  parent_ = node;
  if(x < node->data)
    Insert(node->lchild, x);
  else
    Insert(node->rchild, x);
}

void BST::Insert(int x) {
  Insert(root_, x);
}

void BST::InorderTraver(Node* node) {
  if(node == NULL) return;
  InorderTraver(node->lchild);
  cout<<node->data<<" ";
  InorderTraver(node->rchild);
}

void BST::InorderTraver() {
  InorderTraver(root_);
}

Node* BST::Find(Node* node, int x) {
  if(node == NULL) return NULL;
  if(x < node->data) return Find(node->lchild, x);
  else if(x > node->data) return Find(node->rchild, x);
  else return node;
}

Node* BST::Find(int x) {
  return Find(root_, x);
}

void BST::Remove(Node* z) {
  if(!z->lchild && !z->rchild) {
    if(z == root_) root_ = NULL;
    else if(z == z->parent->lchild)
      z->parent->lchild = NULL;
    else
      z->parent->rchild = NULL;
  }

  else if(z->lchild==NULL || z->rchild==NULL) {
    if(z == root_) {
      if(z->lchild) root_ = z->lchild;
      else root_ = z->rchild;
      root_->parent = NULL;
    }
    else {
      if(z==z->parent->lchild && z->lchild) {
        z->parent->lchild = z->lchild;
        z->lchild->parent = z->parent;
      }
      else if(z==z->parent->lchild && z->rchild) {
        z->parent->lchild = z->rchild;
        z->rchild->parent = z->parent;
      }
      else if(z==z->parent->rchild && z->lchild) {
        z->parent->rchild = z->lchild;
        z->lchild->parent = z->parent;
      }
      else {
        z->parent->rchild = z->rchild;
        z->rchild->parent = z->parent;
      }
    }
  }

  else {
    Node *s = predecessor(z);
    z->data = s->data;
    if(z == s->parent)
      s->parent->lchild = s->lchild;
    else
      s->parent->rchild = s->lchild;

    if(s->lchild)
      s->lchild->parent = s->parent;
  }
}

int main () {
  BST test;

  int i;
  for (i=10; i>0; i--) {
    test.Insert(i);
  }

  test.InorderTraver();
  cout << endl;
  cout << test.Find(3)->data << endl;

  cout << endl;
  return 0;
}
