#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
struct node {
    int key;
    struct node *left, *right;
};
struct node* newNode(int item);
struct node* insert(struct node* node, int key);
struct node* deleteNode(struct node* root, int key);
struct node* search(struct node* root, int key);
 //Queue functions for level order traversal
struct node** createQueue(int* front, int* rear)
{
    struct node** queue = (struct node**)malloc(
        sizeof(struct node*) * MAX_SIZE);
 
    front = rear = 0;
    return queue;
}
 
void enQueue(struct node** queue, int* rear,
             struct node* new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}
 
struct node* deQueue(struct node** queue, int* front)
{
    (*front)++;
    return queue[*front - 1];
}
struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);
 
    if (key <= node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
struct node* maxValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->right != NULL)
        current = current->right;
 
    return current;
}
 
struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        struct node* temp = minValueNode(root->right);
 
        root->key = temp->key;
 
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
struct node* search(struct node* root, int key)
{

if (root == NULL || root->key == key)
return root;
if (root->key < key)
return search(root->right, key);

return search(root->left, key);
}
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
void preorder(struct node* root)
{
    if (root != NULL) {
        printf("%d \n", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root)
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d \n", root->key);
    }
}

void levelorder(struct node* root)
{
    int rear, front;
    struct node** queue = createQueue(&front, &rear);
    struct node* temp_node = root;
 
    while (temp_node) {
        printf("%d ", temp_node->key);
 
        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);
 
        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);

        temp_node = deQueue(queue, &front);
    }
}