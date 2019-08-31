#include <iostream>
#include <algorithm>
//最后不到k个元素不反转，前面的元素只要多与k要反转多次
using namespace std;

int main(int argc, char const *argv[])
{
    int firstAdd, n, k;
    scanf("%d %d %d", &firstAdd, &n, &k);
    int data[100002], next[100002], res[100002];//list放排序后的地址

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        scanf("%d %d", &data[temp], &next[temp]);
    }
    //测试用例中不一定所有的输入的结点都是有用的,只需要找出连续可用的节点地址就OK
    int sum = 0, p = firstAdd; 
    while (p != -1)//直接将连续的地址放入res中
    {
        res[sum++] = p;
        p = next[p];
    }

    //最后不到k个元素不反转
    for (int i = 0; i < (sum-sum%k); i += k)
        reverse(begin(res) + i, begin(res) + i + k);

    for (int i = 0; i < sum - 1; i++)
        printf("%05d %d %05d\n", res[i], data[res[i]], res[i + 1]);
    printf("%05d %d -1", res[sum - 1], data[res[sum - 1]]);
    
    return 0;
}