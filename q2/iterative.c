#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#define STR_LENGTH 10

/* produce test case */
int compare(const void* ch1, const void *ch2) {
    return *(char*)ch1 - *(char*)ch2;
}

char* createStr(char str[]) {
    int i;
    for(i=0;i<STR_LENGTH;++i) {
        str[i] = 'a' + rand()%26;
    }
    qsort((void*)str,STR_LENGTH,sizeof(char),compare);
    return str;
}

char smallest_character(char str[],char c) {

    int i;
    for(i=0;i<STR_LENGTH;++i) {
        if(str[i]>c)
            return str[i];
    }
    return str[0];
}



int main()
{
    char str[STR_LENGTH];

    /* create test case */
    createStr(str);
    char c = 'a'+rand()%26;

    smallest_character(str,c);

    return 0;
}
