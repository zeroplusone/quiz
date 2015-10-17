#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} node;

typedef struct sublist {
    node* subHead;
    node* subTail;
} sub;

void swap(int *a, int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

/* create test case */
node* createArray(node* head, int len, int maxVal)
{
    int i;
    node* newNode=head;

    for(i=0; i<len; ++i) {
        newNode->val = rand()%maxVal+1;
        newNode->next=(node*)malloc(sizeof(node));
        newNode = newNode->next;
    }
    return head;
}

/* print list */
void printList(node* head, int len)
{
    int i;
    node* tmp = head;
    printf("[");
    for(i=0; i<len; ++i) {
        printf(" %d%c",tmp->val,i==len-1?']':',');
        tmp = tmp->next;
    }
    printf("\n");
}

/* release memory */
void freeList(node* head)
{
    node* tmp;
    while(head!=NULL) {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

sub* reverseSub(node* head)
{

    sub* ret=(sub*)malloc(sizeof(sub));

    node *tmp, *new_head;
    ret->subTail=head;
    while(head) {
        tmp = head->next;
        head->next=new_head;
        new_head=head;
        head=tmp;
    }
    ret->subHead=new_head;
    return ret;
}

node* reverseBetween(node* head, int m, int n)
{
    assert( m<=n && "Wrong range of m and n");
    assert( head && "head is null");

    node *pre=head, *back=NULL, *tmp;
    sub *mnSub;

    int i;
    for(i = 1; i < m - 1 ; ++i)
        pre = pre->next;
    for(i = 0, back=m==1?head:pre->next; i < n - m; ++i)
        back = back->next;
    tmp = back;
    back = back->next;
    tmp->next=NULL;

    if(m==1) {
        /* m is the first node */
        mnSub = reverseSub(head);
        head = mnSub->subHead;
    } else {
        mnSub=reverseSub(pre->next);
        pre->next=mnSub->subHead;
    }
    mnSub->subTail->next=back;

    return head;
}

int main(int argc, char* argv[])
{
    assert(argc == 3 && "Please input 'length of array' and 'max valur' in argv");

    srand(time(NULL));
    int len=atoi(argv[1]);
    int maxVal=atoi(argv[2]);
    int m=rand()%maxVal+1, n=rand()%maxVal+1;
    if(m>n)
        swap(&m, &n);

    node *head=(node*)malloc(len*sizeof(node));
    assert(head != NULL && "malloc error");

    /* create test case */
    head = createArray(head, len, maxVal);

    printf("Origin list:\n");
    printList(head, len);
    printf("Reverse between %d %d:\n",m,n);
    head = reverseBetween(head, m, n);
    printList(head,len);

    /* release the memory */
    freeList(head);

    return 0;
}

