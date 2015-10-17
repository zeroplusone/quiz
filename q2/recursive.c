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
