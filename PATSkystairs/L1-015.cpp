#include <cstdio>
#include <cstring>

using namespace std;
int main() {
    int n, row;
    char c;
    scanf("%d %c", &n, &c);
    row = (n * 1.0) / 2 + 0.5;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%c", c);
        }
        printf("\n");
    }
    

    return 0;
}
