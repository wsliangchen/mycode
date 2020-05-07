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

char a[100],b[100];

int main(int argc, char const *argv[]){
    scanf("%s%s", a,b);
    for(int i = 0; i < strlen(a); i++){
        if(isupper(a[i])) a[i] = tolower(a[i]);
        if(isupper(b[i])) b[i] = tolower(b[i]);
    }
    sort(a,a+strlen(a));
    sort(b,b+strlen(b));
    printf("%s", strcmp(a,b) == 0?"Y":"N");
    return 0;
}