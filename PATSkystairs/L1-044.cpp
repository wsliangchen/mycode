#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string c = "ChuiZi", j = "JianDao", b = "Bu";

int main()
{
    string s;
    int n, cnt = 0;
    cin >> n;
    while (cin >> s && s != "End")
    {
        if (cnt < n)
        {
            string o = (s == c ? b : (s == j ? c : j));
            cout << o << endl;
            cnt++;
        }else{
            cnt = 0;
            cout << s << endl;
        }
    }

    return 0;
}
