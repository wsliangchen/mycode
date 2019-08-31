#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
    string dist[4] = { "Beijing", "Washington", "London", "Moscow" };
    int cost[4][4] = { 0, -13, -8, -5, 13, 0, 5, 8, 8, -5, 0, 3, 5, -8, -3, 0 };
    int time[72] = {12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 , 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int h, m, a, b, dis;
        scanf("%d:%d", &h, &m);
        string from, to, test, pday;
        cin >> test >> from >> to;
        if (test == "AM")
            for(int j = 24; j <= 35; j++)
                if(time[j] == h) dis = j;
        if (test == "PM")
            for(int j = 36; j <= 47; j++)
                if(time[j] == h) dis = j;        
        for (int j = 0; j < 4; j++) {
            if (dist[j] == from)
                a = j;
            if (dist[j] == to)
                b = j;
        }
        dis += cost[a][b];
        printf("Case %d: ",i+1);
        if(dis>=0 && dis <= 23) printf("Yesterday");
        else if(dis >= 24 && dis <= 47) printf("Today");
        else printf("Tomorrow");
        printf(" %d:%02d ", time[dis], m);
        if((dis>=0&&dis<=11) || (dis>=24&&dis<=35) || (dis>=48&&dis<=59)) printf("AM\n");
        else printf("PM\n");
    }
    return 0;
}