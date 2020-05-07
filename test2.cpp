#include <cstdio>
#include <iostream>
using namespace std;
int n, c, a[22], i, j;
int main() {
    cin >> n;
    a[1] = 2;                //初值，只有一对盘子时，次数为2
    for (i = 2; i <= n; i++) //从第二对盘子开始，都将前面的结果*2+2
    {
        c = 0;                    //进位
        for (j = 1; j <= 20; j++) //压四位高精，故20足矣
        {
            a[j] = a[j] * 2 + c; //逐位*2，记得加进位
            if (j == 1)
                a[j] += 2;    //最低位+2
            c = a[j] / 10000; //进位
            a[j] %= 10000;    //余数
        }
    }
    i = 20;
    while (i > 1 && !a[i])
        i--;      //去除前导0
    cout << a[i]; //最高位直接输出，避免出现多余的0
    while (--i)
        printf("%04d", a[i]); //其他必须要输出0
    cout << endl;
    return 0;
}