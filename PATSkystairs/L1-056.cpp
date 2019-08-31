#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main()
{
    int n,sum = 0;
    scanf("%d", &n);
    map<string, int> mp;
    for(int i = 0; i < n; i++)
    {
        string s;
        int temp;
        cin >> s >> temp;
        mp[s] = temp;
        sum += temp;
    }
    int aver = sum / n/2;
    string name;
    int minc = 999999999;
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        if (abs(it->second-aver) < minc) {
            minc = abs(it->second - aver);
            name = it->first;
        }
    }

    cout << aver << " " << name;

    return 0;
}
