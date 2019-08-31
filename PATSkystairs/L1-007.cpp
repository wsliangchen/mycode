#include <cstdio>

using namespace std;
int main() {

    char arr[10][6] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

    char c;
    int cnt = 0;
    while(scanf("%c", &c) == 1 && c != '\n'){
        if (c == '-') {
            printf("fu");
            cnt++;
        }else
        {
            printf("%s%s", cnt?" ":"", arr[c-'0']);
            cnt++;
        }
        
        
    }
    

    return 0;
}
