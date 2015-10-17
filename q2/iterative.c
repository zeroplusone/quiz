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

char* createStr(char str[],int len)
{
    int i;
    for(i=0; i<len; ++i) {
        str[i] = 'a' + rand()%26;
    }
    qsort((void*)str,len,sizeof(char),compare);
    return str;
}

char smallest_character(char str[], char c)
{
    /* use binary search to implemet */

    int mid;
    int L=0, R=strlen(str)-1;

    do {
        mid=(L+R+1)>>1;
        if(str[mid]<=c)
            L=mid;
        else
            R=mid-1;
    } while(L<R);

    return str[mid];
}

int main(int argc, char* argv[])
{
    assert(argc == 2 && "Please input 'length of array'");
    int len=atoi(argv[1]);
    char *str=(char*)malloc(len*sizeof(char));
    assert(str!=NULL && "input string is null");

    /* create test case */
    srand(time(NULL));
    createStr(str, len);
    char c = 'a'+rand()%26;

    printf("smallest_character(%s, %c) = %c.\n",str, c, smallest_character(str,c));
    return 0;
}
