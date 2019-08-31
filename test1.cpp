#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <typeinfo>
#include <vector>
using namespace std;

vector<set<string>> v[101];

int main(int argc, char const *argv[]) {
    printf("%s\n", typeid(v[0]).name());
    map<int, int> mp;
    for (int i = 0; i < 10; i++) {
        mp[i] = i * 2;
    }

    for (auto &&i : mp) {
        printf("%d  ->%d\n", i.first, i.second++);
    }
    for (auto &&i : mp) {
        printf("%d  ->%d\n", i.first, i.second);
    }
	
    return 0;
}