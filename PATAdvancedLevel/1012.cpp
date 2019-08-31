#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

struct stu {
    int c, m, e, ave; //id成绩
};

int main(int argc, char const* argv[])
{
    map<int, stu> mp;
    int t1, t2, rank[4][101] = { 0 }; //rank存放名次

    scanf("%d%d", &t1, &t2);
    for (int i = 0; i < t1; i++) {
        int arr[5], tsum = 0;
        scanf("%d", &arr[0]); //读取id
        for (int j = 1; j < 4; j++) {
            scanf("%d", &arr[j]);
            tsum += arr[j];
        }
        arr[4] = tsum / 3;
        mp[arr[0]] = stu{ arr[1], arr[2], arr[3], arr[4] };
        for (int j = 0; j < 4; j++) {
            rank[j][arr[j + 1]]++; //统计0-100的每个分数的人数
        }
    }

    for (int i = 0; i < 4; i++) { //分别计算出c,m,e,ave每个分数的名次
        int last = 1;
        for (int j = 100; j >= 0; j--) {
            if (rank[i][j] != 0) {
                int temp = rank[i][j];
                rank[i][j] = last;
                last += temp;
            }
        }
    }
    char ch[] = "ACME";
    for (int i = 0; i < t2; i++) {
        int q, arr[4];
        scanf("%d", &q);
        if (mp.find(q) == mp.end()) {
            printf("N/A\n");
            continue;
        }
        arr[0] = rank[3][mp[q].ave];
        arr[1] = rank[0][mp[q].c];
        arr[2] = rank[1][mp[q].m];
        arr[3] = rank[2][mp[q].e];
        int mx = 0;
        for (int i = 0; i < 4; i++)
            if (arr[i] < arr[mx])
                mx = i;

        printf("%d %c\n", arr[mx], ch[mx]);
    }

    return 0;
}