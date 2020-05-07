#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <cmath>

typedef long long ll;

#define PI acos(-1.0)
using namespace std;

int main(int argc, char const *argv[]){
    unordered_map<string, string> mp;
    string t,s;
    while(1){
        cin >> t >> s;
        mp[s] = t;
        getchar();
        if(cin.peek() == '\n') break;
    }

    while(cin >> t){
        if(mp[t] != "") cout << mp[t] << endl;
        else cout <<"eh"<<endl;
    }
    return 0;
}