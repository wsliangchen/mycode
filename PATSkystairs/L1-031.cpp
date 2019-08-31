#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int h, w;
        scanf("%d%d", &h, &w);

        double std = (1.0 * h - 100) *1.8;
        if (fabs(std-w) < std*0.1) {
            printf("You are wan mei!\n");
        }else if (fabs(std-w) >= std*0.1 && std < w) {
            printf("You are tai pang le!\n");
        }else if (fabs(std-w) >= std*0.1 && std > w) {
            printf("You are tai shou le!\n");
        }
    }
    
    
    return 0;
}
