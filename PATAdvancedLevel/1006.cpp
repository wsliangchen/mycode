#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    string first;
    string last;
    int last_time = -1, first_time = 100000000;
    for (int i = 0; i < n; i++)
    {
        int h1, m1, s1, h2, m2, s2;
        string tempid;
        cin >> tempid;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        if (h1 * 60 * 60 + m1 * 60 + s1 < first_time)
        {
            first_time = h1 * 60 * 60 + m1 * 60 + s1;
            first = tempid;
        }

        if (h2 * 60 * 60 + m2 * 60 + s2 > last_time)
        {
            last_time = h2 * 60 * 60 + m2 * 60 + s2;
            last = tempid;
        }
    }
    cout << first << " " << last << endl;
    return 0;
}