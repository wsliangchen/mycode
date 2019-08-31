#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int sum(int *arr, int a, int b){
    if(a > b) return 0;
    int res = 0;
    for(int i = a; i < b; i++) res += arr[i];
    return res;
}

bool isequal(double a, double b){
    return fabs(a-b)<1e-6?true:false;
}

int findcoin(int *arr, int a, int b){
    int n = b-a;
    if(n == 3)
        return arr[a] == arr[a+1]?a+2:(arr[a] == arr[a+2]?a+1:a);
    else if(n == 2){
        return arr[a] == arr[0]?a+1:a;
    }else if(n == 1){
        return a+1;
    }else{
        double ave1 = 0, ave2 = 0, ave3 = 0;//every part's weight average
        int n1,n2,n3,s1 = 0,s2 = 0,s3 = 0;//n:every part's count s:every part's weight sum
        n1 = n2 = int(n*1.0/3+0.5);//partition
        n3 = n-n1-n2;

        s1 = sum(arr, a, a+n1);
        s2 = sum(arr, a+n1, a+n1+n2);
        s3 = sum(arr, a+n1+n2, b);
        ave1 = s1*1.0/n1;
        ave2 = s2*1.0/n2;
        ave3 = s3*1.0/n3;
        //part 3
        if(isequal(ave1,ave2) && !isequal(ave2, ave3))
            return findcoin(arr,a+n1+n2, b);
        //part 2
        if(isequal(ave1,ave3) && !isequal(ave2, ave3))
            return findcoin(arr,a+n1, a+n1+n2);
        //part 1
        if(isequal(ave3,ave2) && !isequal(ave1, ave3))
            return findcoin(arr,a, a+n1);
    }
}

int main(int argc, char const *argv[])
{

    int len1 = 8;
    int arr1[len1] = {2,2,3,2,2,2,2,2};
    int len2 = 3;
    int arr2[len2] = {2,2,3};
    int len3 = 6;
    int arr3[len3] = {2,2,2,2,1,2};

    printf("%d\n", findcoin(arr1,0,len1)+1);
    printf("%d\n", findcoin(arr2,0,len2)+1);
    printf("%d\n", findcoin(arr3,0,len3)+1);
    return 0;
}
