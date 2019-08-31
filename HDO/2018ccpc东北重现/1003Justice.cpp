#include <algorithm>
#include <cstdio>
using namespace std;

struct card {
    int id, val;
} a[100050];
int vis[100050]; //记录分组情况 0和1区分两个分组
bool cmp(const card &a, const card &b) { return a.val < b.val; }

int main(int argc, char const *argv[]) {
    int t, n, caset = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i].val);
            a[i].id = i;
            vis[i] = 0;
        }
        sort(a + 1, a + 1 + n, cmp); //从小到大选择
        int flag = 1, pre = 1, cnt1 = 1, cnt2 = 1;
        for (int i = 1; i <= n; i++) {
            while (cnt1 + cnt2 <= n - i + 1 && pre < a[i].val)
                cnt1 *= 2, cnt2 *= 2, pre++; //转化为当前需要的pre以及数量
            if (cnt1 + cnt2 > n - i + 1){
                flag = 0;
                break; //剩下卡片的数量不够需求
            }

            if (cnt1 > 0)
                cnt1--, vis[a[i].id] = 1; //假想把第i个卡片分给某一组
            else
                cnt2--;

            if (cnt1 == cnt2 && cnt1 == 0)
                break; //两组都能凑够了
        }
        printf("Case %d ", caset++);
        if(flag == 0 || cnt1 != 0 || cnt2 != 0) printf("NO\n");
        else {
            printf("YES\n");
            for(int i = 1; i <= n; i++)
                printf("%d", vis[i]);
            printf("\n");
        }  
    }
    return 0;
}