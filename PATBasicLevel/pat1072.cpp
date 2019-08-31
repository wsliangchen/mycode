#include <stdio.h>

bool isIlleagl(int *items, int m, int sth)
{
    for (int i = 0; i < m; i++)
    {
        if (sth == items[i])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n, m, issueStuCount = 0, issueItemsCount = 0;
    scanf("%d%d", &n, &m);
    int items[m];
    char name[5];
    for (int i = 0; i < m; i++)
        scanf("%d", &items[i]);

    for (int i = 0; i < n; i++)
    {
        int num, count = 0;
        scanf("%s %d", name, &num);
        int stu[num];
        for (int i = 0; i < num; i++)
        {
            scanf("%d", &stu[i]);
            if (isIlleagl(items, m, stu[i]) == false)
            {
                count++;
                issueItemsCount++;
            }
        }

        if (count != 0)
        {
            issueStuCount++;
            printf("%s:", name);
            for (int i = 0; i < num; i++)
            {//测试点2注意输出违禁物品的格式，如0001要输出0001 
                if (isIlleagl(items, m, stu[i]) == false)
                    printf(" %04d", stu[i]);
            }
            printf("\n");
        }
    }
    printf("%d %d", issueStuCount, issueItemsCount);
    return 0;
}
