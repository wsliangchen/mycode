#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    vector< vector<char> > v;
    char str[1010];
    int cnt = 0;
    char c;
    while(scanf("%c", &c) == 1 && c != '\n'){
        str[cnt] = c;
        cnt++;
    }
    str[cnt] = '\0';
    int row = strlen(str)/n;
    if (strlen(str) %n != 0) {
        row++;
    }
    
    for(int i = 0; i < row; i++)
    {
        vector<char> t;
        for(int j = 0; j < n && i*n+j < strlen(str); j++)
        {
            t.push_back(str[i*n + j]);
        }
        if (t.size() < n) {
            for(int k = 0; k < n-t.size(); k++)
            {
                t.push_back(' ');
            }
        }
        v.push_back(t);
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = v.size()-1; j >= 0; j--)
        {
            printf("%c", v[j][i]);
        }
        printf("\n");
    }
    

    return 0;
}
