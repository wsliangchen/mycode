#include <cstdio>
#include <cstring>
using namespace std;
char str[100010];
int main() {
    char yuan[6] = "aeiou";
    int ans = 0;
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++) {
        for (int j = 0; j < 5; j++) {
            if (str[i] == yuan[j]) {
                ans++;
                break;
            }
        }
    }
    printf("%d\n%d", ans, strlen(str)-ans); 
    return 0;
}
