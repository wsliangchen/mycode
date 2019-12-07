#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
typedef long long ll;

#define PI acos(-1.0)
using namespace std;

int bfs(string start) {
    string end = "12345678x";
    queue<string> q;
    unordered_map<string, int> d;
    d[start] = 0;
    q.push(start);
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

    while (q.size()) {
        auto t = q.front();
        q.pop();
        int dis = d[t];
        if(t == end) return dis;
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i],b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3) {
                swap(t[k], t[a * 3 + b]);
                if (!d.count(t)) {
                    d[t] = dis + 1;
                    q.push(t);
                }
                swap(t[k], t[a * 3 + b]);
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    string state;
    for (int i = 0; i < 9; i++) {
        char c;
        cin >> c;
        state += c;
    }
    cout << bfs(state);
    return 0;
}