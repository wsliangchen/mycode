#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main()
{
    char c;
    int n;
    scanf("%c%d", &c, &n);
    getchar();
    vector<string> s;
    for(int i = 0; i < n; i++)
    {
        string t;
        getline(cin, t);
        s.push_back(t);
    }

    bool flag = true;
    for(int i = 0; i < s.size()/2; i++)
    {
        if (s[i] != s[s.size()-1-i]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        printf("bu yong dao le\n");
    }
    
    for(int i = s.size()-1; i >= 0; i--)
    {
        for(int j = s[i].size()-1; j >= 0; j--)
        {
            if (s[i][j] != ' ') {
                printf("%c", c);
            }else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    

    return 0;
}
