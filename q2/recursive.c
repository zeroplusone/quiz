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

int binary_search(int L,int R, int mid, char str[], char c) {
    if(L >= R) 
        return str[mid]<=c?0:mid;
    
    /* choose the array range by checking whether middle value is larger than c or not */ 
    mid = (L+R+1)>>1;
    if(str[mid] <= c)
        return binary_search(mid, R, mid, str, c);
    else
        return binary_search(L, mid-1, mid, str, c);
}

char smallest_character(char str[], char c) {
    /* use binary search to implemet */
    return str[binary_search(0, strlen(str)-1, 0, str, c)];
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
