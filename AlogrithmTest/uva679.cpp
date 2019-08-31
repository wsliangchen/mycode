#include <cstdio>
#include <iostream>

using namespace std;

/*
*所有正整数的按位取反是其本身+1的负数。
所有负整数的按位取反是其本身+1的绝对值。
零的按位取反是 -1。
*/

int main(int argc, char const *argv[])
{
    int b = 0x000001;
    int a = -1;
    if (a>>31) {
        printf("-");
    }
    printf("0x%X", a>>31);
    return 0;
}