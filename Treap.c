/*
input
16
insert 35 99
insert 3 80
insert 1 53
insert 14 25
insert 80 76
insert 42 3
insert 86 47
insert 21 12
insert 7 10
insert 6 90
print
find 21
find 22
delete 35
delete 99
print

output
 1 3 6 7 14 21 35 42 80 86
 35 6 3 1 14 7 21 80 42 86
yes
no
 1 3 6 7 14 21 42 80 86
 6 3 1 80 14 7 21 42 86
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *right;
  struct node *left;
  int key;
  int priority;
};

typedef struct node * Node;

#define NIL NULL

Node root;

Node delete(Node t, int key);

Node _delete(Node t, int key);

Node treeSearch(Node u, int k)
{
  Node ret = NIL;
  if (u->key == k)
    return u;
  else if (u->key > k) {
    if (u->left != NIL)
      return treeSearch(u->left, k);
  } else if (u->right != NIL)
    return treeSearch(u->right, k);
  return ret;
}

Node rightRotate(Node t)
{
  Node s = t->left;
  if (t == root)
    root = s;
  t->left = s->right;
  s->right = t;
  return s;
}

Node leftRotate(Node t)
{
  Node s = t->right;
  if (t == root)
    root = s;
  t->right = s->left;
  s->left = t;
  return s;
}

Node insert(Node t, int key, int priority)
{
  if (t == NIL) {
    Node s = malloc(sizeof(struct node));
    s->right = NIL;
    s->left = NIL;
    s->key = key;
    s->priority = priority;
    if (root == NIL)
      root = s;
    return s;
  }
  if (key == t->key)
    return t;
  if (key < t->key) {
    t->left = insert(t->left, key, priority);
    if (t->priority < t->left->priority)
      t = rightRotate(t);
  } else {
    t->right = insert(t->right, key, priority);
    if (t->priority < t->right->priority)
      t = leftRotate(t);
  }
  return t;
}

Node delete(Node t, int key)
{
  if (t == NIL)
    return NIL;
  if (key < t->key)
    t->left = delete(t->left, key);
  else if (key > t->key)
    t->right = delete(t->right, key);
  else
    return _delete(t, key);
  return t;
}

Node _delete(Node t, int key)
{
  if (t->left == NIL && t->right == NIL)
    return NIL;
  else if (t->left == NIL)
    t = leftRotate(t);
  else if (t->right == NIL)
    t = rightRotate(t);
  else {
    if (t->left->priority > t->right->priority)
      t = rightRotate(t);
    else
      t = leftRotate(t);
  }
  return delete(t, key);
}

void inorder(Node u)
{
  if (u->left != NIL)
    inorder(u->left);
  printf(" %d", u->key);
  if (u->right != NIL)
    inorder(u->right);
}

void preorder(Node u)
{
  printf(" %d", u->key);
  if (u->left != NIL)
    preorder(u->left);
  if (u->right != NIL)
    preorder(u->right);
}

int main(void)
{
  int n, i;
  char com[20];
  root = NIL;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", com);
    if (com[0] == 'f') {
      int x;
      scanf("%d", &x);
      Node t = treeSearch(root, x);
      if (t != NIL)
	printf("yes\n");
      else
	printf("no\n");
    } else if (com[0] == 'i') {
      int k, p;
      scanf("%d %d", &k, &p);
      insert(root, k, p);
    } else if (com[0] == 'p') {
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    } else if (com[0] == 'd') {
      int x;
      scanf("%d", &x);
      Node t;
      t = treeSearch(root, x);
      if (t != NIL)
	delete(root, x);
    }
  }
  return 0;
}
