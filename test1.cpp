#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;
const int N = 100010;
int p[N], tmp[N];

ll merge(int l, int r){
    if(l >= r) return 0;
    int mid = l+r >> 1;
    ll res = merge(l,mid)+merge(mid+1, r);
    int i = l, j = mid +1, k = 0;
    while(i <= mid && j <= r){
        if(p[i] <= p[j]) tmp[k++] = p[i++];
        else{
            tmp[k++] = p[j++];
            res += mid-i+1;
        }
    }
    while(i <= mid) tmp[k++] = p[i++];
    while(j <= r) tmp[k++] = p[j++];
    for(i = l, j = 0; i<= r; i++,j++) p[i] = tmp[j];

    return res;
}

int main(int argc, char const *argv[]) {
    int n, t;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    cout << merge(0, n-1);
    return 0;
}