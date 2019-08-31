#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int score = 0, tempo = 0;
        char s[85];
        scanf("%s", s);
        
        for (int j = 0; j < strlen(s); j++)
            s[j] == 'O'?(score += ++tempo):(tempo = 0);
        printf("%d\n", score);
    }
    
    return 0;
}
