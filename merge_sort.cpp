#include <cstdio>
#include <iostream>

using namespace std;

void merge_sort(int *A, int x, int y, int* T){
    if(y-x > 1){
        int m = (x+y)/2;
        int p = x, q = m, i = x;
        merge_sort(A,x,m,T);
        merge_sort(A,m,y,T);

        while(p < m || q < y){
            if(q >= y || (p < m && A[p] <= A[q])) T[i++] = A[p++];
            else T[i++] = A[q++];
        }
        for(int i = x; i < y; i++) A[i] = T[i];
    }
}

int main(int argc, char const *argv[])
{
    int a[6] = {5,6,4,1,2,3}, t[6];
    merge_sort(a,0,6,t);
    for(int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
    
    return 0;
}

