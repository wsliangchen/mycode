#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;
//
int main(int argc, char const *argv[])
{
    int n, m, t1, t2;
    scanf("%d%d", &n, &m);
    unordered_map<int, vector<int>> b;

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &t1, &t2);
        b[t1].push_back(t2);
        b[t2].push_back(t1);
    }

    for (int l = 0; l < m; l++)
    {
        int num, temp[100010] = {0};//存放该组数据存在情况
        scanf("%d", &num);
        vector<int> arr(num);

        for (int i = 0; i < num; i++)
        {
            scanf("%d", &arr[i]);
            temp[arr[i]] = 1;//用下标表示该数 1 为存在
        }

        bool isboom = false; //用来判断是否boom
        for (int i = 0; i < arr.size(); i++)
        {
            for(int j = 0; j < b[arr[i]].size(); j++)
                if(temp[b[arr[i]][j]] == 1)
                    isboom = true;
        }
        printf("%s\n", isboom ? "No" : "Yes");
    }

    return 0;
}
