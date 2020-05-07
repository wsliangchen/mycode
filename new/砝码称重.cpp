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

const int fm[7] = {0, 1, 2, 3, 5, 10, 20};
const int N = 1005;
int a[7], w[N]; //w[1] ~ w[i]里存放已经能够称出不重复的重量
int used[N];//重量去重 去重数组 思想很常见

int main() {
    for (int i = 1; i <= 6; i++)
        cin >> a[i];
    w[0] = 1; //存储能称出的重量数，初始为1个
    w[1] = 0; //初始时，能称0，算一个
    for (int i = 1; i <= 6; i++) {
        int t = w[0];                //已称出个数
        for (int j = 1; j <= t; j++) //在已经称出的重量中，加砝码得到新值
            for (int k = 1; k <= a[i]; k++) {
                int add = w[j] + k * fm[i];//新增的重量
                if (used[add] == 0) { //重量去重
                    used[add] = 1; //标记
                    w[++w[0]] = add;  //存储新值
                }
            }
    }
    cout << "Total=" << w[0] - 1 << endl; // -1就是减去称出0的情况
    return 0;
}