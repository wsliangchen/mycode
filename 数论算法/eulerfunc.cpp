#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

typedef long long ll;

#define PI acos(-1.0)
using namespace std;

int phi(int x) {
    int res = x;
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0) {
            res = res / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    if (x > 1)
        res = res / x * (x - 1);

    return res;
}

int main(int argc, char const *argv[]) {
    /*
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        cout << phi(a) << endl;
    }*/
    cout << phi(190000);
    return 0;
}