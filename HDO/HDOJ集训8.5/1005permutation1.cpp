#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
    int arr[] = {1,2,3};
    for(int i = 0; i < 6; i++)
    {
        next_permutation(arr,arr+3);
            for(int i = 0; i < 3; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    }

    return 0;
}