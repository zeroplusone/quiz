#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <limits.h>

/* create test caes */
int* createArray(int A[], int len,int maxVal) {
    
    int i;
    srand(time(NULL));

    for(i=0; i<len; ++i) {
        A[i]=rand()%maxVal;
        A[i]=rand()%2==0?A[i]:(-1)*A[i];
    }

    return A;
}

int max(int a,int b) {
    return a>b?a:b;
}

int back_tracking(int from, int to, int ans, int A[], int n) {

    /* procedure of fixing 'from' and increasing 'to' finish */
    if(to == n)
        return ans;
    /* procedure of fixing 'to' and increasing 'from' finish */
    if(from==n-1)
        return ans;

    /* travel every combination */
    if(to-from==1)
        return max(max(ans, back_tracking(from, to+1, ans+A[to], A, n)),back_tracking(from+1, to+1, ans-A[from]+A[to], A, n));
    else
        return max(ans, back_tracking(from, to+1, ans+A[to], A, n));
}

int maxSubArray(int A[],int n) {
    assert(A != NULL && "input array is NULL!");
    
    return back_tracking(0, 1, A[0], A, n);    
}

int main(int argc, char* argv[]) {
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
