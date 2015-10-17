#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>


/* produce test case */
int compare(const void* ch1, const void *ch2)
{
    return *(char*)ch1 - *(char*)ch2;
}

char* createStr(char str[], int len)
{
    int i;
    for(i=0; i<len; ++i) {
        str[i] = 'a' + rand()%26;
    }
    qsort((void*)str,len,sizeof(char),compare);
    return str;
}

int binary_search(int L,int R, int mid, char str[], char c)
{
    if(L >= R)
        return str[mid]<=c?0:mid;

    /* choose the array range by checking whether middle value is larger than c or not */
    mid = (L+R+1)>>1;
    if(str[mid] <= c)
        return binary_search(mid, R, mid, str, c);
    else
        return binary_search(L, mid-1, mid, str, c);
}

char smallest_character(char str[], char c)
{
    /* use binary search to implemet */
    return str[binary_search(0, strlen(str)-1, 0, str, c)];
}

int main(int argc, char* argv[])
{
    assert(argc == 2 && "Please input length of array'");
    int len=atoi(argv[1]);
    char *str=(char*)malloc(len*sizeof(char));

    /* create test case */
    srand(time(NULL));
    createStr(str,len);
    char c = 'a'+rand()%26;

    printf("smallest_character(%s, %c) = %c.\n",str, c, smallest_character(str,c));
    return 0;
}
