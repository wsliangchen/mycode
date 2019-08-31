#include <cstdio>
#include <cstring>

using namespace std;
int main() {
    int n,res=0;

    scanf("%d", &n);

    int temp = 1;

    for(int i = 1; i <= n; i++)
    {
        temp *= i;
        res += temp;
    }
    
    printf("%d", n?res:1);
    return 0;
}
