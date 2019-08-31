#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int x,y;
    scanf("%d%d", &x,&y);
    int a = round((x+y)/2);
    int b = round((x-y)/2);
    printf("%d\n", a*b);
    return 0;
}