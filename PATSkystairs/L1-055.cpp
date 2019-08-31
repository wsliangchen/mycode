#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int pa, pb, a = 0, b = 0;
    scanf("%d%d", &pa, &pb);
    for(int i = 0; i < 3; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (temp) {
            b++;
        }else
        {
            a++;
        }
    }
    
    if ((pa > pb && a > 0) || (pa < pb && a == 3)) {
        printf("The winner is a: %d + %d", pa, a);
    }else
    {
        printf("The winner is b: %d + %d", pb, b);
    }
    
    
    return 0;
}
