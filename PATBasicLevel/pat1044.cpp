#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

char *units[] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly",
	"aug", "sep", "oct", "nov", "dec" };
char *tens[] = {" ", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo",
	"syy", "lok", "mer", "jou" };

int MarsToEarth(char *s)
{
    if (s) {
        for(int i = 0; i < 13; i++)//如果是个位数字
            if (strcmp(s, units[i]) == 0)
                return i;
        for(int i = 1; i < 13; i++)
            if (strcmp(s, tens[i]) == 0)
                return i * 13;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int n;
    char line[20];
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++)
    {
        int m;
        fgets(line, 20, stdin);//使用stdin流
        if (isdigit(line[0])) {//判断第一个字符是否为数字
            sscanf(line, "%d", &m);
            if (m/13 != 0&& m%13 != 0)//13进制2位数
                printf("%s %s\n", tens[m/13], units[m%13]);
            else if(m/13 != 0 && m%13 == 0)//13进制个位为0
                printf("%s\n", tens[m/13]);
            else
                printf("%s\n", units[m%13]);//十三进制一位
        }
        else
        {
            m = MarsToEarth(strtok(line, " \n"));//高位
            int temp = MarsToEarth(strtok(NULL, " \n"));//低位
            if (temp >= 0) {//没有低位的话strtok函数会返回-1不能加在m上
                m += temp;
            }
            printf("%d\n", m);
        }
    }

    return 0;
}