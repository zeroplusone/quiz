#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define STR_LENGTH 10

/* produce test case */
int compare(const void* ch1, const void *ch2)
{
    return *(char*)ch1 - *(char*)ch2;
}

char* createStr(char str[])
{   
    int i;
    for(i=0; i<STR_LENGTH; ++i) {
        str[i] = 'a' + rand()%26;
    }
    qsort((void*)str,STR_LENGTH,sizeof(char),compare);
    return str;
}

char smallest_character(char str[], char c) {
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

int main()
{
    char str[STR_LENGTH];

    /* create test case */
    srand(time(NULL));
    createStr(str);
    char c = 'a'+rand()%26;
    
    printf("smallest_character(%s, %c) = %c.\n",str, c, smallest_character(str,c));
    return 0;
}
