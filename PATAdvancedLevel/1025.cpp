#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct stu {
    string id;
    int sc, lc, lcrank;
};

bool cmp(stu a, stu b){
    if(a.sc == b.sc) return a.id<b.id;
    return a.sc > b.sc;
}

void calrank(int *a){
    int t = 1;
    for(int i = 100; i >= 0; i--)
    {
        if(a[i] > 0){
            int temp = a[i];
            a[i] = t;
            t += temp;
        }
    }
}

int main(int argc, char const* argv[])
{
    int frank[101] = { 0 };

    int n, k;
    scanf("%d", &n);
    vector<stu> res;//总表
    for (int l = 0; l < n; l++) {
        scanf("%d", &k);
        getchar();
        int localrank[101] = { 0 };
        vector<stu> v;//分表
        for (int j = 0; j < k; j++) {
            string s;
            cin >> s;
            int sc;
            cin >> sc;
            v.push_back(stu{s,sc,l+1,0});
            localrank[sc]++;//批次分数名次
            frank[sc]++;//总分数名次
        }
        calrank(localrank);
        for(int i = 0; i < v.size(); i++)//合并到总表
            res.push_back(stu{v[i].id, v[i].sc,v[i].lc,localrank[v[i].sc]});
        
    }
    calrank(frank);
    sort(res.begin(), res.end(), cmp);
    printf("%d\n", res.size());
    for(int i = 0; i < res.size(); i++)
    {
        printf("%s %d %d %d\n", res[i].id.c_str(), frank[res[i].sc],res[i].lc,res[i].lcrank);
    }
    
    return 0;
}