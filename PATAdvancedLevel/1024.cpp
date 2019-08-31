#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int a[1010];

int cal(int *a, int len){
    int remind = 0, cnt = len, b[1010];
    for(int i = 0; i < len; i++)
    {
        remind += a[i] + a[len-1-i];
        b[i] = remind%10;
        remind /= 10;
    }
    while(remind != 0){
        b[cnt++] = remind %10;
        remind /= 10;
    }
    for(int i = 0; i < cnt; i++)
        a[i] = b[i];
    return cnt;
}

bool judge(int *a, int len){
    for(int i = 0; i < len/2; i++)
        if(a[i] != a[len-1-i]) return false;
    return true;
}

int main(int argc, char const *argv[])
{
    char temp[1010];
    int n, acnt = 0, ncnt = 0;
    scanf("%s%d", temp, &n);
    acnt = strlen(temp);
    for(int i = 0; i < acnt; i++) a[i] = temp[i]-'0';

    for(int i = 0;i < n; i++, ncnt++)
    {
        if(judge(a, acnt)) break;
        acnt = cal(a,acnt);
    }
    for(int i = acnt - 1; i >= 0; i--)
        printf("%d", a[i]);
    
    printf("\n%d", ncnt);
    return 0;
}