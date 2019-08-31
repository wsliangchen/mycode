#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f
#define CLR(a, b) memset(a, b, sizeof(a))
#define PI acos(-1.0)
LL toNum(char c) //转化为阿拉伯数字
{
    if (c >= '0' && c <= '9')
        return c - '0';
    return c - 'a' + 10;
}
LL toDecimal(string str, LL radix) //转到十进制
{
    LL num = 0;
    LL ant = 1;
    for (int i = str.size() - 1; i >= 0; i--, ant *= radix) {
        num += ant * toNum(str[i]);
        if (num < 0 || ant < 0) //需要判断这个，也许进制太大了呢
            return -1;
    }
    return num;
}
int main() {
    string a, b;
    int tag, radix;
    LL l, r, mid;
    cin >> a >> b >> tag >> radix;
    if (tag == 2)
        swap(a, b);
    LL base = toDecimal(a, radix);
    l = 2;
    r = base;
    for (int i = 0; i < b.size(); i++) //算出最低的进制数
    {
        l = max(l, toNum(b[i]) + 1);
    }
    while (r >= l) //二分查找第一个大于base的进制数
    {
        mid = (l + r) >> 1;
        LL t = toDecimal(b, mid);
        if (t >= base || t == -1) //-1时太大溢出了
            r = mid - 1;
        else
            l = mid + 1;
    }
    if (toDecimal(b, l) == base) //验证一下是否相等
        cout << l << endl;
    else
        puts("Impossible");
    return 0;
}