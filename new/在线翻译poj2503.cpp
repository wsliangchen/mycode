#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

typedef long long ll;

#define PI acos(-1.0)
using namespace std;

const int N = 100010;

struct ST{
    char eng[11];
    char fore[11];
}st[N];

bool cmp(ST s1, ST s2){
    return strcmp(s1.fore,s2.fore) < 0;
}

int main(int argc, char const *argv[]){
    int num = 0;
    char word[11];
    while(1){
        scanf("%s%s", st[num].eng,st[num].fore);
        num++;
        getchar();
        if(cin.peek() == '\n') break;
    }
    sort(st, st+num, cmp);
    while(scanf("%s", word) == 1){
        int l = 0, r = num-1;
        int n = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            n = strcmp(st[mid].fore, word);
            if(n < 0) l = mid + 1;
            else if (n > 0) r = mid - 1;
            else{
                printf("%s\n", st[mid].eng);
                break;
            }
        }
        if(n != 0) printf("eh\n");
    }
    return 0;
}