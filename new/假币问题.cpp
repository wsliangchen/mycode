#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

typedef long long ll;

#define PI acos(-1.0)
using namespace std;

int heavy[26];

int judge(string x, string y, string z) {
    int xv = 0, yv = 0;
    for (int i = 0; i < x.length(); i++)
        xv += heavy[x[i] - 'A'];
    for (int i = 0; i < y.length(); i++)
        yv += heavy[y[i] - 'A'];
    if (xv == yv && z == "even")
        return 1;
    if (xv > yv && z == "up")
        return 1;
    if (xv < yv && z == "down")
        return 1;
    return 0;
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    while (n--) {
        for (int i = 0; i < 26; i++)
            heavy[i] = 1; //初始heavy数组为1
        vector<string> v[3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                string s;
                cin >> s;
                v[i].push_back(s);
            }
        }
        for (int i = 0; i < 12; i++) {
            heavy[i] = 2;
            if (judge(v[0][0], v[0][1], v[0][2]) &&
                judge(v[1][0], v[1][1], v[1][2]) &&
                judge(v[2][0], v[2][1], v[2][2])) {
                printf("%c is the counterfeit coin and it is heavy.\n",
                       i + 'A');
                break;
            }
            heavy[i] = 0;
            if (judge(v[0][0], v[0][1], v[0][2]) &&
                judge(v[1][0], v[1][1], v[1][2]) &&
                judge(v[2][0], v[2][1], v[2][2])) {
                printf("%c is the counterfeit coin and it is light.\n",
                       i + 'A');
                break;
            }
            heavy[i] = 1;
        }
    }
    return 0;
}