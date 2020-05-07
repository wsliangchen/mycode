
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a[1010][1010];
int turn[4][2]={{-1,0},{0,1},{1,0},{0,-1}};//不动，右，下，左，上
int main(){
    int n,m,r,c;
	cin>>n>>m>>r>>c;
    int cnt=1,x=1,y=1;
    memset(a,0,sizeof(a));
    a[1][1]=1;
    for(int i=2;i<=n*m;i++) {
        int tx = x + turn[cnt % 4][0];
        int ty = y + turn[cnt % 4][1];
        if (tx < 1 || tx > n || ty < 1 || ty > m || a[tx][ty]) {
            cnt++;
        }
        x = x + turn[cnt % 4][0];
        y = y + turn[cnt % 4][1];
        a[x][y] = i;
    }/*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<a[r][c]<<endl;
    return 0;
}