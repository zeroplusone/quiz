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

int maxSubArray(int A[],int n)
{
    assert(A != NULL && "input array is NULL!");

    int i,j,k;
    long long int ans,sum;
    ans=A[0];
    for(i=0; i<n; ++i) {
        for(j=i+1; j<n; ++j) {
            /* subarray from i to j */
            sum=0;
            for(k=i; k<j; ++k)
                sum+=A[k];
            ans=sum>ans?sum:ans;
        }
    }
    return ans;
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
