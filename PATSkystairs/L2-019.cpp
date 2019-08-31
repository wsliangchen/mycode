#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct people
{
    string name;
    int ts;
};

bool cmp(string a, string b)
{
    return a < b;
}
int main()
{
    int n, m;
    cin >> n;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mp[s]++;
    }

    cin >> m;
    people p[m];
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> p[i].name >> p[i].ts;
        sum += p[i].ts;
    }
    double aver = sum * 1.0 / m;
    vector<string> res;
    for (int i = 0; i < m; i++)
    {
        if (p[i].ts > aver && mp[p[i].name] == 0)
            res.push_back(p[i].name);
    }
    sort(res.begin(), res.end(), cmp);
    if (res.size() != 0)
    {
        for (int i = 0; i < res.size(); i++)
            printf("%s\n", res[i].c_str());
    }
    else
        printf("Bing Mei You");

    return 0;
}
