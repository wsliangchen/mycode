#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v;

void guang(vector<int> &v, int n){
    v.clear();
    for(int i = 0; i < n; i++)
        v.push_back(1);
}

int division(vector<int> v, int t, vector<int> &res){
    int remd = 0;
    for(int i = 0; i < v.size(); i++)
    {
        remd = remd*10 + v[i];
        int a = remd / t;
        if (a > 0) {
            remd = remd % t;
            res.push_back(a);
        }else if (a == 0 && res.size()!= 0)
        {
            res.push_back(0);
        }
    }

    return remd;
}

int main()
{
    int t;
    cin >> t;

    for(int i = 1;; i++)
    {
        guang(v, i);
        vector<int> res;
        int remd = division(v, t, res);
        if (remd == 0) {
            for(int i = 0; i < res.size(); i++)
            {
                cout << res[i];
            }
            cout << " " << v.size();
            break;
        }
    }
    

    return 0;
}
