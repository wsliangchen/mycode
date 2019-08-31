#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char const* argv[])
{
    string dist[4] = { "Beijing", "Washington", "London", "Moscow" };
    string day[3] = { "Yesterday", "Today", "Tomorrow" };
    int cost[4][4] = { 0, -13, -8, -5, 13, 0, 5, 8, 8, -5, 0, 3, 5, -8, -3, 0 };
    int time[72] = {12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 , 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int h, m, a, b;
        scanf("%d:%d", &h, &m);
        string from, to, test, pday;
        cin >> test >> from >> to;
        if (test == "PM")
            h += 12;
        for (int j = 0; j < 4; j++) {
            if (dist[j] == from)
                a = j;
            if (dist[j] == to)
                b = j;
        }
        h += cost[a][b];
        //printf("h = %d\n", h);
        if (h < 0) {
            h += 24;
            pday = day[0];
            printf("Case %d: %s %d:%02d %s", i + 1, pday.c_str(), h >= 12 ? time[h - 12] : time[h], m ,h >= 12?"PM":"AM");
        } else if (h >= 24) {
            h -= 24;
            pday = day[2];
        } else
            pday = day[1];
        
    }
    return 0;
}