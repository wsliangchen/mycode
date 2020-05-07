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
void GetTwoInts(int *a, int *b){
    scanf("%d%d", &*a, &*b);
}
int main(int argc, char const *argv[]){
    int c,d;
    int *a = &c,*b = &d;
    GetTwoInts(a,b);
    printf("%d", c+d); 
    return 0;
}