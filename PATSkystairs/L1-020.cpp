#include <cstdio>
#include <cstring>
#include <set>

using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    set<int> s,res;

    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        if (k > 1)
        {
            for (int j = 0; j < k; j++)
            {
                int temp;
                scanf("%d", &temp);
                s.insert(temp);
            }
        }else
        {
            scanf("%*d");
        }
        
    }
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (s.find(temp) == s.end() && res.find(temp) == res.end())
        {
            res.insert(temp);
            printf("%s%05d", cnt == 0 ? "" : " ", temp);
            cnt++;
        }
    }
    if (cnt == 0)
    {
        printf("No one is handsome");
    }

    return 0;
}
