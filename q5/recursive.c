#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>

typedef struct NODE {
    int index;
    struct NODE* next;
    bool visit;
} node;

void createList(node* head, int len)
{
    head->index = 1;
    head->visit = false;
    int i;
    node *tmp, *ori;
    /* malloc memory for link list */
    ori = head;
    for(i = 2; i <= len; ++i) {
        tmp = (node*)malloc(sizeof(node));
        tmp->index = i;
        tmp->visit = false;
        head->next = tmp;
        head = tmp;
        tmp = NULL;
    }

    int cycle = rand() % (len + 1);
    /* cycle = 0 means there is no cycle */

    if(cycle == 0)
        head->next = NULL;
    else {
        while(--cycle)
            ori = ori->next;
        head->next = ori;
    }
}

void printList(node* head, int len)
{
    while(len--) {
        printf("%d -> ", head->index);
        head = head->next;
    }
    if(head == NULL)
        printf("NULL\n");
    else
        printf("%d\n",head->index);
}

void freeList(node* head, int len)
{
    node* tmp;
    while(len--) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

node* detectCycle(node* head)
{
    assert(head != NULL && "head is null.");

    head->visit = true;
    if(head->next == NULL)
        return NULL;
    else if(head->next->visit)
        return head->next;
    else
        return detectCycle(head->next);
}

int main(int argc, char* argv[])
{
    assert(argc == 2 && "Please input 'length of list'");
    int len = atoi(argv[1]);
    node* head = (node*)malloc(sizeof(node));

    /* create test case */
    srand(time(NULL));
    createList(head, len);

    printList(head, len);
    node* result = detectCycle(head);
    printf("The cycle is at %d.\n",result == NULL? 0 : result->index);

    freeList(head, len);

    return 0;
}
