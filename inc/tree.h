#ifndef __TREE_H__ 
#define __TREE_H__
// Define a binary tree with <Key, Value> Pair search Function
#include "global.h"

// Create Node
typedef struct myTree {
  int key;
  void *value;
  struct myTree *left;
  struct myTree *right;
  int height;
}myTree;

struct myTree*new_tree(int key, void *data);
struct myTree *find_key(struct myTree *root, int key);
void free_tree(myTree* root);
struct myTree *insert_tree(struct myTree *node, int key, void *value);
#endif // !__TREE_H__
