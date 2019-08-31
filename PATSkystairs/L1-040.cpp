#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++)
    {
        char c;
        double h;
        scanf("%c%lf", &c, &h);
        getchar();
        printf("%.2lf\n", c=='M'?h/1.09:h*1.09);
    }
    

    return 0;
}
