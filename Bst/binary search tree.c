// Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

struct node 
{
  int key;
  struct node *left, *right;
};


struct node *newNode(int item) 
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root)
 {
  if (root != NULL) 
  {
    inorder(root->left);
    printf("%d -> ", root->key);
    inorder(root->right);
  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

//Searching the node
struct node* search(struct node *root, int x)
{
    printf("Enter x: ");
    scanf("%d", &x);
    if(root==NULL || root->key==x)
        return root;
    else if(x>root->key)

         printf(search(root->right, x));

    else
        printf(search(root->left,x));
}



int main() 
{
  struct node *root = NULL;
  root = insert(root, 500);
  root = insert(root, 150);
  root = insert(root, 250);
  root = insert(root, 350);
  root = insert(root, 700);
  root = insert(root, 100);
  root = insert(root, 1000);
  root = insert(root, 2000);
  root = insert(root, 2500);

  printf("Inorder traversal: ");
  inorder(root);

  if (search(root,x)) {
        printf("Found:%d\n",x);
    }
    else {
        printf("Not Found:%d\n",x);
    }
    
  
}