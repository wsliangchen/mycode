#include <cstdio>
#include <iostream>
//#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    char a[1000001], b[1000001];
    char ch = ' ';
    int alen = 0, blen = 0;
    int mp[128] = {0};
    //map<char, int> mp;

    while (scanf("%c", &ch) == 1 && ch != '\n')
    {
        if (mp[ch] == 0)
            a[alen++] = ch;
        mp[ch]++;
    }

    while (scanf("%c", &ch) == 1 && ch != '\n')
    {
        if (mp[ch] == 0)
            b[blen++] = ch;
        mp[ch]++;
    }

    for (int i = 0; i < alen; i++)
        printf("%c", a[i]);
    for (int i = 0; i < blen; i++)
        printf("%c", b[i]);

    return 0;
}