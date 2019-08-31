#include <cstdio>
typedef long long ll;

#define PI acos(-1.0)
using namespace std;

int arr[200020];

int main(int argc, char const *argv[]){
    int k,n;
    scanf("%d%d", &n,&k);
    int i;
    for(i = 2; i < n; i+=2)
        scanf("%d%d", &arr[i], &arr[i+1]);

    arr[i] = 0, arr[i+1] = 0;

    return 0;
}