#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < k; i++)
    {
        stack<int> s;
        int res = 1;
        int arr[n];
        for(int j = 0; j < n; j++)
            scanf("%d", &arr[j]);

        for(int j = 0; j < n; j++)
        {
            int t = arr[j];
            if (t == res) {
                res++;
            }else{
                while(s.top() == res){
                    s.pop();
                    res++;
                }
                s.push(t);
            }
            if(s.size() > m)
                break;
        }

        printf("%s\n", res-1==n?"YES":"NO");
        printf("res = %d\n", res);
    }
    
    return 0;
}