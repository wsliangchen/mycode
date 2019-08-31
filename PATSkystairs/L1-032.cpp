#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int n;
    char c;
    scanf("%d %c", &n, &c);
    getchar();
    string t;
    getline(cin, t);

    if (t.length()<n) {
        for(int i = 0; i < n-t.length(); i++)
        {
            printf("%c", c);
        }
    }
    if (t.length() > n) {
        t = t.substr(t.length() - n, t.length() - 1);
    }
    cout << t;
    return 0;
}
