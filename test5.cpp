#include <iostream>
#include <cstdio>

using namespace std;
int Sum(int arr[], int start, int len);
int Coin(int low, int heigh, int n, int arr[]);
int flag = -1;//0：较轻， 1：较重
int sum = 0;
int main()
{
    printf("硬币的数量:\n");
    int n;
    scanf("%d", &n);
    int coin[n];
    printf("请输入硬币的重量:\n");

    for(int i = 0; i < n; i++){
        scanf("%d", &coin[i]);
        sum += coin[i];//硬币总重量
    }
    int index = Coin(0, n, n, coin);
    printf("%d", index);
    return 0;
}
//求和
int Sum(int arr[], int start, int len){
    int sum = 0;
    for(int i = start; i < len; i++)
        sum += arr[i];
    return sum;
}
/**
   比较三组硬币的平均重量，假币存在于不同于另外两组的一组中
 */
int Coin(int low, int heigh, int n, int arr[]){
    int num1, num2, num3;// numn存储硬币的数量
    int w1 = 0, w2 = 0, w3 = 0;//存储三组硬币的平均重量
    
    if(n == 1)
        return low+1;
    if(n % 3 == 0)
        num1 = num2 = n/3;
    else
        num1 = num2 = n/3+1;
    num3 = n - num1 - num2;

    int add1 = Sum(arr, low, low+num1);
    int add2 = Sum(arr, low+num1, low+num1+num2);

    w1 = Sum(arr, low, low+num1) / num1;
    w2 = Sum(arr, low+num1, low+num1+num2) / num2;
    w3 = (sum - add1 - add2) / num3;

    if(w1 == w2)
        return Coin(low+num1+num2, heigh, num3, arr);
    else if(w1 == w3)
        return Coin(low+num1, low+num1+num2-1, num2, arr);
    else
        return Coin(low, low+num1-1, num1, arr);
}
