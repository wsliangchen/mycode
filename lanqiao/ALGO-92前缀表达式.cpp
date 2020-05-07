#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

typedef long long ll;

#define PI acos(-1.0)
using namespace std;

int add(int a, int b){
    return a+b;
}
int sub(int a, int b){
    return a-b;
}
int mul(int a, int b){
    return a*b;
}
int dive(int a, int b){
    return a/b;
}
int main(int argc, char const *argv[]){
    char c;
    int a,b;
    scanf("%c %d%d",&c, &a,&b);
    if(c == '+') printf("%d", add(a,b));
    if(c == '-') printf("%d", sub(a,b));
    if(c == '*') printf("%d", mul(a,b));
    if(c == '/') printf("%d", dive(a,b));
    return 0;
}