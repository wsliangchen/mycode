#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        int a, b;
        cin >> s >> a >> b;
        if ((a < 15 || a > 20) || (b < 50 || b > 70)) {
            cout << s << endl;
        }
    }
    return 0;
}
