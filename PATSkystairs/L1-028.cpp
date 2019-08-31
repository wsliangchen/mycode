#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

bool is_prime(int n){
    if (n < 2) {
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (is_prime(temp)) {
            printf("Yes\n");
        }else
        {
            printf("No\n");
        }
        
    }
    
    return 0;
}
