#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long ll;

#define PI acos(-1.0)
using namespace std;

int main(int argc, char const *argv[]) {
    char s[110];

    while (scanf("%s", s) == 1) {
        vector<int> pos;
        int len = strlen(s);
        for(int i = 0;i < len; i++){
            if(!pos.empty() && s[i] == ')' && s[pos.back()] == '(')
                pos.pop_back();
            else if(s[i] == '(' || s[i] == ')')
                pos.push_back(i);
        }
        printf("%s\n", s);
        while(!pos.empty()){
            int t = pos.back();
            pos.pop_back();
            if(s[t] == '(') s[t] = '$';
            if(s[t] == ')') s[t] = '?';
        }
        for(int i = 0; i < len; i++)
            printf("%c", (s[i] == '?' || s[i] == '$')?s[i]:' ');
        printf("\n");
    }

    return 0;
}