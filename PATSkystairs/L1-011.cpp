#include <cstdio>
#include <cstring>

using namespace std;
int main() {

    char a[10000];
    int b[130] = {0};
    scanf("%[^\n]", a);

    getchar();

    char c;
    while(scanf("%c", &c) == 1 && c != '\n'){
        b[c]++;
    }
    
    for(int i = 0; i < strlen(a); i++)
    {
        if (b[a[i]] == 0) {
            printf("%c", a[i]);
        }
    }
    

    return 0;
}
