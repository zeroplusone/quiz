#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <limits.h>

/* create test caes */
int* createArray(int A[], int len,int maxVal)
{

    int i;
    srand(time(NULL));

    for(i=0; i<len; ++i) {
        A[i]=rand()%maxVal;
        A[i]=rand()%2==0?A[i]:(-1)*A[i];
    }

    return A;
}

int maxSubSum(int sum, int ans, int now, int A[], int n)
{
    if(now == n)
        return ans;

    int addTmp=sum+A[now];
    if(addTmp>0)
        return maxSubSum(addTmp, ans>addTmp?ans:addTmp, now+1, A, n);
    else
        return maxSubSum(A[now], ans>addTmp?ans:addTmp, now+1, A, n);
}

int maxSubArray(int A[],int n)
{
    /* use greedy to calculate */
    assert(A != NULL && "input array is null!");

    return maxSubSum(A[0], A[0], 1, A, n);
}

int main(int argc, char* argv[])
{
    assert(argc == 3 && "Please input 'length of array' and 'max valur' in argv");

    int len=atoi(argv[1]);
    int maxVal=atoi(argv[2]);
    int i;

    int *A=(int*)malloc(len*sizeof(int));
    assert(A != NULL && "malloc error");

    /* create test case */
    A=createArray(A, len, maxVal);

    printf("The max sum of subarray of array\n[");
    for(i=0; i<len; ++i)
        printf(" %d%c",A[i],i==len-1?']':',');
    printf("\nis %d.\n",maxSubArray(A, len));

    free(A);
    return 0;
}
