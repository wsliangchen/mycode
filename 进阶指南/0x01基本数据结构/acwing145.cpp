#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct da {
    int p, d;
} data[10010];

bool cmp(da a, da b) { return a.d < b.d; }

da heap[10010];
int n;

void up(int p) {
    while (p > 1) {
        if (heap[p].p < heap[p / 2].p) {
            swap(heap[p], heap[p / 2]);
            p /= 2;
        } else
            break;
    }
}

void insert(da x) {
    heap[++n] = x;
    up(n);
}

void down(int p) {
    int s = p * 2;
    while (s <= n) {
        if (s < n && heap[s].p > heap[s + 1].p)
            s++;
        if (heap[s].p < heap[p].p) {
            swap(heap[s], heap[p]);
            p = s, s = p * 2;
        } else
            break;
    }
}

int main(int argc, char const *argv[]) {
    int t;
    while (scanf("%d", &t) == 1) {
        int ans = 0;
        n = 0;
        for (int i = 0; i < t; i++) {
            scanf("%d%d", &data[i].p, &data[i].d);
        }
        sort(data, data + t, cmp);
        for (int i = 0; i < t; i++) {
            if (data[i].d > n) {
                insert(data[i]);
                ans += data[i].p;
            } else if (data[i].d == n && data[i].p > heap[1].p) {
                ans = ans + data[i].p - heap[1].p;
                down(1);
            }

            printf("%d\n", ans);
        }
        return 0;
    }
}