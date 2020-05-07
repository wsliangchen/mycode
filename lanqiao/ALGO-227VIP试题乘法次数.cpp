#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cctype>
typedef long long ll;

#define PI acos(-1.0)
using namespace std;
char a[2000],b[2000];
int x,y;
int main(int argc, char const *argv[]){
    char c;
    scanf("%c", &c);
    if(c == 'a') printf("zab");
    else if(c == 'z') printf("yza");
    else if(c == 'A') printf("ZAB");
    else if(c == 'Z') printf("YZA");
    else {
        printf("%c%c%c", c-1,c,c+1);
    }
    return 0;
}