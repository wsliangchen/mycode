#include <cstdio>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[])
{
    char c;
    scanf("%c", &c);
    getchar();
    char res[1001];
    int count = 0, num[1001] = {0};
    if (c == 'C')
    {
        char last = '\0', temp;
        int tempCount = 1;
        while (scanf("%c", &temp) == 1 && temp != '\n')
        {
            if (temp != last)
            {
                res[count] = temp;
                num[count++] = tempCount;
                last = temp;
                tempCount = 1;
            }
            else
            {
                tempCount++;
            }
        }
        num[count] = tempCount;//存入最后一个字符重复的次数

        for (int i = 0; i < count; i++)
        {
            if (num[i + 1] > 1)
                printf("%d", num[i + 1]);
            printf("%c", res[i]);
        }
    }else if(c == 'D')
    {
        char temp;
        while (scanf("%c", &temp) == 1 && temp != '\n')
        {
            if (isdigit(temp))//遇到数字将一连串的数字字符处理成数值
            {
                char ch;
                int pnum = temp - '0';
                while(scanf("%c", &ch) == 1 && isdigit(ch))
                    pnum = pnum*10 + ch-'0';
                for(int i = 0; i < pnum; i++)
                    printf("%c", ch);
            }
            else//单个字符直接打印
            {
                printf("%c", temp);
            }
        }
    }

    return 0;
}