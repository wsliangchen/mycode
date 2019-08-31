#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    char a[25]; 
    int x[10] = {0}, y[10] = {0}, b[25] = {0};

    scanf("%s", a);
    int remind = 0, cnt = 0;
    for(int i = strlen(a)-1; i >= 0; i--)
    {
        x[a[i]-'0']++;
        remind += (a[i]-'0')*2;
        b[cnt++] = remind%10;
        y[b[cnt-1]]++;
        remind /= 10;
    }
    while(remind != 0){
        b[cnt++] = remind % 10;
        y[b[cnt-1]]++;
        remind /= 10;
    }
    bool flag = false;
    for(int i = 0; i < 10; i++)
        if(x[i] != y[i]) flag = true;
    printf("%s\n", flag == true?"No":"Yes");
    for(int i = cnt - 1; i >= 0; i--)
        printf("%d", b[i]);
    
    return 0;
}