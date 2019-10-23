#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int trie[3000000][2],tot = 0,a[100010],n;
void insert(int x){
    int p = 0;
    for(int i = 30; i >= 0; i--){
        int &s = trie[p][x>>i & 1];
        if(!s) s = ++tot;
        p = s;
    }
}

int search(int x){
    int p = 0, res = 0;
    for(int i = 30; i >= 0; i--){
        int s = x >> i & 1;
        if(trie[p][!s]){
            res += 1 << i;
            p = trie[p][!s];
        }else p = trie[p][s];
    }
    return res;
}

int main(int argc, char const *argv[]){
    cin >> n;
    for(int i = 0; i  <n; i++){
        cin >> a[i];
        insert(a[i]);
    }
    int res = 0;
    for(int i = 0; i < n; i++) res = max(res, search(a[i]));
    cout <<res << endl;
    return 0;
}