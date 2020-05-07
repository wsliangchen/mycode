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

int main(int argc, char const *argv[]){
    char c;
    while(scanf("%c", &c) && c != '\n')
        printf("%c", isupper(c)?tolower(c):toupper(c));
    string a,b;
    cin >> a>> b;
    cout << a << b;
    return 0;
}