#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
typedef long long ll;

#define PI acos(-1.0)
using namespace std;

int m = 4;
vector<int> chosen;
//生成k-subset
void cal(int x,int &n){
    //剪枝
    if(chosen.size() > m|| chosen.size() + (n-x+1) < m) return;
    if(x == n+1){
        for(int i = 0; i < chosen.size(); i++)
            printf("%d ", chosen[i]);
        puts("");
        return ;
    }
    cal(x+1, n);    //不选x
    chosen.push_back(x);
    cal(x+1, n);    //选x
    chosen.pop_back();//回溯
}

int main(int argc, char const *argv[]){
    int n = 4;
    cal(0, n);
    printf("%d", chosen.size());
    return 0;
}