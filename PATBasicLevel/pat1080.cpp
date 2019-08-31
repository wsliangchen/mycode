#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct score
{
    string name;
    int gp = -1, gmid = -1, gf = -1;
    int g = 0;
};

bool cmp(score a, score b)
{
    if (a.g == b.g)
        return a.name < b.name;
    return a.g > b.g;
}

int main(int argc, char const *argv[])
{
    int n[3];
    cin>>n[0]>>n[1]>>n[2];

    unordered_map<string, score> stu;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n[i]; j++)
        {
            string name;
            int sc;
            cin >> name >> sc;
            if (i == 0)
                stu[name].gp = sc;
            else if (i == 1)
                stu[name].gmid = sc;
            else
                stu[name].gf = sc;
            stu[name].name = name;
        }
    }

    vector<score> v; //放到数组里排序
    int i = 0;
    for (auto it = stu.begin(); it != stu.end(); it++, i++)
    {
        v.push_back(stu[it->first]);   //+0.5四舍五入向下取整
        v[i].g = ((v[i].gmid > v[i].gf) ? (v[i].gmid * 0.4 + v[i].gf * 0.6) : 1.0*v[i].gf)+0.5;
    }
    sort(v.begin(), v.end(), cmp);
    
    for( i = 0; i < v.size(); i++)
    {
        if(v[i].g < 60)
            break;
        if(v[i].gp < 200)
            continue;
        cout<<v[i].name<<" "<<v[i].gp<<" "<<v[i].gmid<<" "<<v[i].gf<<" "<<v[i].g<<endl;
    }
    
    return 0;
}
