#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

struct stu
{
    int id;
    string name;
    int g;
};

bool cmp1(stu a, stu b){
    return a.id<b.id;
}
bool cmp2(stu a, stu b){
    if(a.name == b.name)
        return a.id<b.id;
    else return a.name < b.name;
}
bool cmp3(stu a, stu b){
    if(a.g == b.g)
        return a.id<b.id;
    else return a.g < b.g;
}
int main(int argc, char const *argv[])
{
    int n,c;
    scanf("%d%d", &n, &c);
    vector<stu> v;
    for(int i = 0; i < n; i++)
    {
        int id,g;
        string name;
        cin >>id>>name>>g;
        v.push_back(stu{id,name,g});
    }
    
    if(c == 1) sort(v.begin(), v.end(), cmp1);
    else if(c == 2) sort(v.begin(), v.end(), cmp2);
    else sort(v.begin(), v.end(), cmp3);
    for(int i = 0; i < v.size(); i++)
    {
        printf("%06d %s %d\n", v[i].id, v[i].name.c_str(), v[i].g);
    }
    
    return 0;
}