#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int arr[100100];

int main(int argc, char const *argv[])
{
    int n,q,l,r;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for(int i = 0; i < q; i++)
    {
        scanf("%d%d", &l, &r);
        if(r-l < 2){
            printf("-1\n");
            continue;
        }
        vector<int> v;
        for(int j = l; j <= r; j++)
            v.push_back(arr[j]);
        sort(v.begin(),v.end());
        int ans = -1;
        for(int j = 0; j < v.size()-2; j++)
        {
            int len = v[j]+v[j+1]+v[j+2];
            if(v[j]+v[j+1] > v[j+2]) ans = max(ans,len);
        }
        printf("%d\n", ans);
    }   

    return 0;
}