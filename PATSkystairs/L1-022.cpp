#include <cstdio>
#include <cstring>
#include <set>

using namespace std;
int main()
{
    int n,j = 0, o = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        temp &= 1;
        if (temp == 0)
            o++;
        else
            j++;
    }
    printf("%d %d", j, o);

    return 0;
}
