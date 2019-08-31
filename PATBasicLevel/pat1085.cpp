#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdio>
#include <algorithm>
using namespace std;
//vector会超时 改用不自动排序的map
struct record
{
    string name;
    double score;
    int human;
};

bool compare(record a, record b)
{
    if ((int)a.score == (int)b.score)
    {
        if (a.human == b.human)
            return a.name < b.name;
        else
            return a.human < b.human;
    }
    else
        return (int)a.score > (int)b.score;
}

int main()
{
    int n;
    cin >> n;
    unordered_map<string, int> schuman;
    unordered_map<string, double> scscore;

    for (int i = 0; i < n; i++)
    {
        string s, sc;
        double tempscore;
        cin >> s >> tempscore >> sc;

        for (int j = 0; j < sc.length(); j++)
            sc[j] = tolower(sc[j]); //学校名转换成小写

        double thisscore = tempscore * (s[0] == 'B' ? (2.0/3) : (s[0] == 'A' ? 1 : 1.5));
        scscore[sc] += thisscore;
        schuman[sc]++;
    }

    vector<record> res;
    for(auto it = schuman.begin(); it != schuman.end(); it++)
        res.push_back(record{it->first, scscore[it->first], schuman[it->first]});
    

    sort(res.begin(), res.end(), compare);
    printf("%d\n",res.size());
    for (int i = 0, j = 1; i < res.size(); i++)
    {
        printf("%d %s %d %d\n", j, res[i].name.c_str(), (int)res[i].score, res[i].human);
        if ((int)res[i + 1].score != (int)res[i].score)
            j=i+2;
    }

    return 0;
}
