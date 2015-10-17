#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
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

char smallest_character(char str[],char c)
{
    char ret;
    /* find the first value which is strictly larger than c */
    if(str[0] > c) {
        ret = str[0];
    /* continue to travel array */
    } else {    
        
        int len = strlen(str);
        /* if there is no value larger than c, return '0' */
        if(len == 1)
            return '0';

        /* continue to travel */    
        char *substr = (char*)malloc(len);
        memcpy(substr, &str[1], len-1);
        ret = smallest_character(substr, c);
        free(substr);
    }
    return ret=='0'?str[0]:ret;
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
