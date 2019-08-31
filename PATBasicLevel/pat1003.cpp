#include <cstdio>
#include <cstring>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    char str[101];
    while (n > 0)
    {
        int pcount = 0, tcount = 0, psit = 0, tsit = 0;
        n--;
        scanf("%s", str);
        bool istrue = true;
        for (int i = 0; i < strlen(str); i++)
        {  
             //先过滤PAT
            if (str[i] != 'P' && str[i] != 'A' && str[i] != 'T')
            {
                istrue == false;
                break;
            }//统计PT的数量和位置
            else if (str[i] == 'P')
            {
                psit = i;
                pcount++;
            }
            else if (str[i] == 'T')
            {
                tsit = i;
                tcount++;
            }
        }
        //PT只能有一个并且P在T前
        if (pcount != 1 || tcount != 1 || psit >= tsit-1 || istrue == false)
        {
            printf("NO\n");
            continue;
        }
        //T后面字符串的长度等于P前面*PT中间的长度
        if(psit*(tsit-psit-1) == (strlen(str)- tsit-1))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}