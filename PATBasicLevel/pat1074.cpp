#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    char s[21], a[21], b[21], res[1000];
    scanf("%s%s%s", s, a, b);
    //要进位的数                         //第几位  //当前位的进制
    int quotient = 0, atemp = 0, btemp = 0, bit = 0, bitsystem;

    int i = strlen(a) - 1, j = strlen(b) - 1, k = strlen(s) - 1;
    for (;; i--, j--, k--, bit++)
    { //得到当前位的两个加数
        atemp = i >= 0 ? (a[i] - '0') : 0;
        btemp = j >= 0 ? (b[j] - '0') : 0;
        //得到当前位的进制数
        bitsystem = k >= 0 ? ((s[k] == 'd' || s[k] == '0') ? 10 : s[k] - '0') : 10;
        res[bit] = (atemp + btemp + quotient) % bitsystem + '0';              //余数
        quotient = (atemp + btemp + quotient - (res[bit] - '0')) / bitsystem; //商数

        if (atemp == 0 && btemp == 0 && quotient == 0 && i <= 0 && j <= 0)
            break;
    }

    bool zero = true;//从第一个不是0的数开始输出
    for (int i = bit; i >= 0; i--)
    {
        if (res[i] != '0')
            zero = false;
        if (zero == false)
            printf("%c", res[i]);
    }
    printf("%c", zero?'0':'\0');//测试点5结果为0输出0
    return 0;
}