#include <cstdio>
#include <cstring>
//next数组当做指针 指向该输出的字符串的第一个数组下标
//cur当做指针ss
using namespace std;

const int maxn = 30;

int main(int argc, char const *argv[])
{
    int last, cur, next[maxn];
    char s[maxn];
    while(scanf("%s", s+1) == 1 && s[1] != '#'){
        int n = strlen(s + 1);
        last = cur = 0;
        next[0] = 0;

        for(int i = 1; i <= n; i++)
        {
            char ch = s[i];

            if (ch == '[') {
                cur = 0;
            }
            else if (ch == ']') {
                cur = last;
            }else{
                next[i] = next[cur];
                next[cur] = i;
                if (cur == last)
                    last = i;
                cur = i;
            }
        }
        for(int i = next[0]; i != 0; i = next[i])
        {
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}