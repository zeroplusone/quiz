#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

typedef struct NODE {
    int index;
    struct NODE *left, *right;
} node;

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
    if(root == NULL)
        return;

    node *last;

    if(root->left != NULL) {
        flatten(root->left);
        flatten(root->right);

        /* find the leaf of flatten left tree */
        last = root->left;
        while(last->right!=NULL)
            last = last->right;

        /* move left tree to right */
        last->right = root->right;
        root->right = root->left;
        root->left = NULL;

    } else {
        /* left tree is NULL */
        flatten(root->right);
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

