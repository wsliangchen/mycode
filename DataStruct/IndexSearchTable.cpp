#include <cstdio>
#include <iostream>

using namespace std;

struct ist
{
    int max_key;
    int start_index;
};

int main(int argc, char const *argv[])
{
    int arr[] = {0,22,12,13,8,9,20,33,42,44,38,24,48,60,58,74,49,86,53};
    ist index_table[4] =
    {
        {22,1},
        {48,7},
        {86,13},
        {0,19}
    };

    int find;
    printf("输入要查找的关键字:");
    scanf("%d", &find);

    bool isfind = false;
    for(int i = 0; i < 3; i++)
    {
        int count = 0;
        count++;
        if (find <= index_table[i].max_key)
        {
            for(int j = index_table[i].start_index; j < index_table[i+1].start_index; j++)
            {
                count++;
                if (arr[j] == find)
                {
                    isfind = true;
                    printf("对比查找%d次找到关键字%d下标为%d\n", count,find, j);
                }
            }
        }
        if (isfind)
        {
            break;
        }
    }
    if (!isfind)
    {
        printf("没有找到关键字%d\n", find);
    }
    return 0;
}
