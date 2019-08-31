#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    char id[n + 1][18];
    int test[n + 1], seat[n+1];
    for(int i = 0; i < n; i++)
    {
        char temp[18];
        int t, s;
        scanf("%s%d%d",temp, &t, &s);
        test[t] = s;
        strcpy(id[s], temp);
    }
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        int t;
        scanf("%d", &t);
        printf("%s %d\n", id[test[t]], test[t]);
    }
    

    return 0;
}