#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

typedef struct NODE {
    int index;
    struct NODE *left, *right;
} node;

typedef struct STACKNODE {
    node* val;
    struct STACKNODE* pre;
} snode;

void push(snode** sp, node* in)
{
    snode* newNode = (snode*)malloc(sizeof(snode));
    newNode->val = in;
    if((*sp) == NULL) {
        (*sp) = newNode;
        (*sp)->pre = NULL;
    } else {
        newNode->pre = (*sp);
        (*sp) = newNode;
    }
}

void pop(snode** sp)
{
    assert((*sp) != NULL && "pop an empty stack");
    snode* tmp;
    tmp = (*sp);
    (*sp) = (*sp)->pre;
    free(tmp);
}

void createTree(node* root, int len, int now)
{
    if(len == 0) {
        free(root);
        root = NULL;
        return;
    }

    assert(root != NULL && "root is null.");
    root->index = now;
    root->right = NULL;
    root->left = NULL;
    if(len > 1) {
        int leftNum = rand() % len;
        if(leftNum != 0) {
            root->left = (node*)malloc(sizeof(node));
            createTree(root->left, leftNum, now + 1);
        }
        if(len-1-leftNum != 0) {
            root->right = (node*)malloc(sizeof(node));
            createTree(root->right, len-1-leftNum, now + leftNum + 1);
        }
    }
}

void printTree(node* root, char position, int pa)
{
    if(root == NULL)
        return;
    printf("%c %d[%d]\n", position, root->index, pa);

    printTree(root->left, 'l', root->index);
    printTree(root->right, 'r', root->index);

}

void flatten(node* root)
{
    /* use stack to implement iteratice version */
    snode* sp = NULL;

    while(root != NULL || sp != NULL) {
        if(root->right != NULL)
            push(&sp, root->right);
        if(root->left != NULL) {
            root->right = root->left;
            root->left = NULL;
        } else if(sp != NULL) {
            root->right = sp->val;
            pop(&sp);
        }
        root = root->right;
    }
}

void freeTree(node* root)
{
    if(root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(int argc, char* argv[])
{
    assert(argc == 2 && "Please input 'number of node'");
    int len = atoi(argv[1]);
    node *root = (node*)malloc(sizeof(node));

    assert(root != NULL && "root is null");

    /* create test case */
    srand(time(NULL));
    createTree(root, len, 1);

    printf("== Original tree ==\n");
    printTree(root, 'm', 0);
    printf("== Flatten tree ==\n");
    flatten(root);
    printTree(root, 'm', 0);

    freeTree(root);
    return 0;
}

