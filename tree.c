#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char Type;

typedef struct TNode {
  Type data;
  struct TNode *left;
  struct TNode *right;
} Node;

/*
 * Input Sample
 *
 *        r
 *      /   \
 *     a     b
 *    / \   / \
 *   c   d +   e
 *  / \ / \   / \
 * +   ++  + +   +
 *
 * $ rac++d++b+e++
 */

Node * create(Node *p) {
  Type ch;
  Node *t;
  scanf("%c", &ch);
  if (ch == '+') {
    p = NULL; // empty tree
  } else {
    p->data = ch;
    t = (Node *) malloc (sizeof(Node));
    p->left = create(t);
    t = (Node *) malloc (sizeof(Node));
    p->right = create(t);
  }

  return p;
}

void preorder (Node *root) {
  if (root != NULL) {
    printf( " %c ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
  return;
}

void inorder (Node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf(" %c ", root->data);
    inorder(root->right);
  }
  return;
}

void postorder (Node *root) {
  if (root != NULL) {
    postorder (root->left);
    postorder (root->right);
    printf(" %c ", root->data);
  }
  return;
}

void main() {
  Node *root, *q, n;
  q=&n;
  root=create(q);

  if (root == NULL) {
    printf("Empty tree!\n");
  } else {
    printf("preorder: root, left, right\n");
    preorder(root);
    printf("\n");

    printf("inorder: left, root, right\n");
    inorder(root);
    printf("\n");

    printf("postorder: left, right, root\n");
    postorder(root);
    printf("\n");
  }
}
