#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int inf = 0x3f3f3f3f;

//排序找最小差 O(n*log2(n))
void fun_a(){
    int n;
    vector<int> v;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
    //最多的时间用在排序上
    sort(v.begin(), v.end());

    int mind = inf;

    for(int i = 0; i < v.size()-1; i++)
    {
        int tempd = v[i + 1] - v[i];
        if (tempd < mind)
            mind = tempd;
    }
    printf("%d\n", n==1?0:mind);
}

//不排序+空间换时间 O(n)
void fun_b(){
    int arr[100000];
    memset(arr, 0, sizeof(arr));

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        arr[temp]++;
    }

    int mind = inf;
    int lastindex = inf;

    bool findfirst = false;
    for(int i = 0; i < 100000; i++)
    {
        //数组中含有两个或以上相同的数据时最小差为0
        if (arr[i] > 1) {
            mind = 0;
            break;
        }
        if (findfirst && arr[i] != 0) {
            int temp = i - lastindex;
            if (temp < mind) {
                mind = temp;
            }
            lastindex = i;
        }
        //找到最小的数的下标
        if (!findfirst && arr[i] != 0) {
            findfirst = true;
            lastindex = i;
        }
    }
    printf("%d\n", n==1?0:mind);
}

//暴力求解 O(n²)
void fun_c(){
    int n;
    vector<int> v;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }

    int mind = inf;

    for(int i = 0; i < v.size()-1; i++)
    {
        for(int j = i+1; j < v.size(); j++)
        {
            int temp = v[j] - v[i];
            //去掉相减为负数的情况
            if (temp >= 0 && temp < mind) {
                mind = temp;
            }
        }
        
    }
    printf("%d\n", n==1?0:mind);
}


int main(int argc, char const *argv[])
{
    fun_a();
    fun_b();
    fun_c();
    return 0;
}