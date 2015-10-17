#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

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

    int i, len=strlen(str);
    for(i=0; i<len; ++i) {
        if(str[i]>c)
            return str[i];
    }
    return str[0];
}



int main(int argc, char* argv[])
{
    assert(argc == 2 && "Please input 'length of array'");
    int len=atoi(argv[1]);
    char *str=(char*)malloc(len*sizeof(char));
    assert(str!=NULL && "input string is null");

    /* create test case */
    createStr(str, len);
    char c = 'a'+rand()%26;

    printf("smallest_character(%s, %c) = %c.\n",str, c, smallest_character(str,c));
    return 0;
}
