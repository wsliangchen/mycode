#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

//寻找最小
int FindMaxIndex(int n,double aver[])
{
    int maxIndex = 0;
    for(int i = 0; i < n; i++)
    {
        if(aver[maxIndex] < aver[i])
            maxIndex = i;
    }
    return maxIndex;
}

int main()
{
    int n,d;
    cin>>n>>d;
    double storage[n];
    double price[n];
    double aver[n];

    for(int i = 0; i < n; i++)
        cin>>storage[i];
    for(int i = 0; i < n; i++)
        cin>>price[i];

    for(int i = 0; i < n; i++)//求每吨的平均利润
        aver[i] = price[i]/storage[i];

    double needed = 1.0*d;
    double profit = 0;

    for(int i = 0; i < n; i++)
    {
        int m = FindMaxIndex(n,aver);
        if(storage[m] < needed)
        {
            profit += price[m];
            needed -= storage[m];
            aver[m] = 0;
        }else
        {
            profit += (needed/storage[m])*price[m];
            break;
        }
    }

    cout<<fixed<<setprecision(2)<<profit;
    return 0;
}
