#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ctnum[n + 1] = {0};
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> ctnum[i];
        sum += ctnum[i];
    }
    int seat[sum + 1] = {0};

    return 0;
}
