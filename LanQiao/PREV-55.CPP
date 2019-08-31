#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <map>
using namespace std;
//小计算器
typedef long long LL;
//根据字符返回数字
int calDigit(char ch)
{
    if (isdigit(ch))
        return ch - '0';
    else
        return ch - 'A' + 10;
}
//数字转换字符
char returnCh(int t)
{
    if (t >= 0 && t <= 9)
        return t + '0';
    else
        return t + 'A' - 10;
}

//x进制的数转换成10进制的LL
LL turnLL(string s, int x)
{
    LL res = 0, tempx = 1;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        res += calDigit(s[i]) * tempx;
        tempx *= x; //低位高位依次乘以位的权
    }
    return res;
}

//十进制数转化为x进制
string turnX(LL d, int x)
{
    string res;
    while (1)
    {
        int redis = d % x;
//测试用printf("redis == == = %d   %c\n", redis,returnCh(redis));
        res += returnCh(redis);
        d = (d - redis) / x;
        if (d == 0)
            break;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(int argc, char const *argv[])
{
    //操作选择放进map里
    map<string, int> mp;
    string data[9] = {"NUM", "ADD", "SUB", "MUL", "DIV", "MOD", "CHANGE", "EQUAL", "CLEAR"};
    for (int i = 0; i < 9; i++)
        mp[data[i]] = i;

    int n;
    LL res = 0;
    scanf("%d", &n);

    int x = 10; //当前进制
    int op = 0; //初始化内操作op
    for (int i = 0; i < n; i++)
    {
        string s, temp;
        cin >> s;
        int tempop = mp[s];

        if (tempop == 0)
        {
            cin >> temp;
            if (op == 0)
                res = turnLL(temp, x);
            if (op == 1)
                res += turnLL(temp, x);
            if (op == 2)
                res -= turnLL(temp, x);
            if (op == 3)
                res *= turnLL(temp, x);
            if (op == 4)
                res /= turnLL(temp, x);
            if (op == 5)
                res %= turnLL(temp, x);
        }
        if (tempop >= 1 && tempop <= 5)
            op = tempop;
        if (tempop == 6)
            scanf("%d", &x);
        if (tempop == 7)
            cout << turnX(res, x) << endl;
        if (tempop == 8)
        {
            res = 0;
            op = 0;
        }
    }

    return 0;
}
