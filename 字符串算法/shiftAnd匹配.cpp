#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXN 100 //要大于模式串的长度

int shiftand(const char *text, const char *pattern) {
    int n = 0;
    bitset<(int)MAXN> p, d[128], sf; // d辅助数组空间可优化
    for (; pattern[n]; n++)
        d[pattern[n]] |= (1 << n); //转换掩码
    if (n == 0)
        return -1; // pattern为空
    sf[n - 1] = 1; //将最高位置为1，匹配成功标志
    for (int i = 0; text[i]; i++) {
        p <<= 1, p[0] = 1;
        p &= d[text[i]];
        if ((p & sf)[n - 1])  //访问最高位
            return i - n + 1; //匹配成功返回位置
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    char a[] = "123456", b[] = "56";
    printf("%d", shiftand(a, b));
    return 0;
}
