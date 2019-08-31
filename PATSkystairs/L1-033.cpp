#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <set>
using namespace std;

int dif;

bool judge(int y){
    char t[5];
    set<char> s;

    sprintf(t, "%04d", y);
    for(int i = 0; i < strlen(t); i++)
    {
        s.insert(t[i]);
    }
    if (s.size() == dif) {
        return true;
    }
    return false;
}

int main()
{
    int y;
    scanf("%d%d", &y, &dif);

    for(int i = y; i < 4000; i++)
    {
        if (judge(i)) {
            printf("%d %04d", i-y, i);
            break;
        }
    }
    
    return 0;
}
