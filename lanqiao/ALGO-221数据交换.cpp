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

void myswap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(int argc, char const *argv[]){
    int a,b;
    cin >> a>> b;
    myswap(a,b);
    cout << a <<" "<<b;
    return 0;
}