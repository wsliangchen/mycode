#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int maxlevel = 1;
vector<vector<int>> v;
set<int> s;

void dfs(int node, int level){
    if (level > maxlevel) {
        maxlevel = level;
        s.clear();
        s.insert(node);
    }else if (level == maxlevel) {
        s.insert(node);
    }
    for(int i = 0; i < v[node].size(); i++)
        dfs(v[node][i], level + 1);

}

int main(int argc, char const *argv[])
{
    int n,tp,root = 0;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++)
    {
        scanf("%d", &tp);
        if(tp == -1){
            root = i;
            continue;
        }
        v[tp].push_back(i);
    }

    dfs(root, 1);
    cout << maxlevel << endl;
    for(auto i = s.begin(); i != s.end(); i++)
    {
        printf("%s%d", i == s.begin()?"":" ", *i);
    }
    
    return 0;
}