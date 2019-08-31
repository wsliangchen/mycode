#include <cstdio>
#include <cstring>

using namespace std;
int main() {
    int cnt = 0, twonum = 0, negative = false;

    char arr[55];
    scanf("%s", arr);
    int len = strlen(arr);
    for(int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] == '2') {
            cnt++;
        }
    }
    bool ism = false;
    if (arr[0] == '-') {
        len--;
        ism = true;
    }
    double res = (1.0*cnt/len);
    if (ism) {
        res *= 1.5;
    }
    
    if ((arr[strlen(arr)-1]-'0')%2 == 0) {
        res *= 2;
    }
    res *= 100;
    printf("%.2lf%%", res);
    

    return 0;
}
