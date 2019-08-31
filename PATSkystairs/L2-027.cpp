#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

struct stu
{
    int rank, sc;
    string name;
};

bool cmp(stu a, stu b){
    return a.sc == b.sc ? a.name < b.name : a.sc > b.sc;
}

int main()
{
    int n,g,k,a = 0,b = 0;
    scanf("%d%d%d", &n, &g, &k);
    stu s[n];
    for(int i = 0; i < n; i++)
    {
        cin >> s[i].name >> s[i].sc;
        if (s[i].sc >= g) {
            a++;
        }else if (s[i].sc >= 60) {
            b++;
        }
    }
    sort(s, s + n, cmp);
    for(int trank = 1, i = 0, rank = 1; i < n; i++, rank++)
    {
        if (i && s[i].sc != s[i-1].sc) {
            trank = rank;
        }
        s[i].rank = trank;
    }
    printf("%d\n", a*50+b*20);
    for(int i = 0; i < n; i++)
    {
        if (s[i].rank > k) {
            break;
        }
        cout << s[i].rank << " " << s[i].name << " " << s[i].sc << endl;
    }
    
    
    return 0;
}
