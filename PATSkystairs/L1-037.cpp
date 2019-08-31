#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    printf("%d/", a);
    if (b < 0) {
        printf("(%d)=", b);
    }else if (b > 0) {
        printf("%d=", b);
    }else{
        printf("0=");
    }
    if (b == 0) {
        printf("Error");
    }else
    {
        printf("%.2lf", 1.0*a/b);
    }
    
    

    return 0;
}
