#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char str[12], a[12], b[12];
    int cnt = 0;
    while(scanf("%s", str) == 1 && str[0] != '.'){
        cnt++;
        if (cnt == 2) {
            strcpy(a, str);
        }
        if (cnt == 14) {
            strcpy(b, str);
        }
    }
    if (cnt < 2) {
        printf("Momo... No one is for you ...");
    }else if (cnt < 14) {
        printf("%s is the only one for you...", a);
    }else
    {
        printf("%s and %s are inviting you to dinner...", a,b);
    }
    
    
    

    return 0;
}
