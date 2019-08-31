#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int maxmun(vector<int> arr)
{
    int thismax = 0, tempmax = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            printf("%4d", thismax);
            tempmax += arr[i];
            if (tempmax > thismax)
                thismax = tempmax;
            else if (tempmax < 0)
                tempmax = 0;
        }
    }
    return thismax;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    printf("%d", maxmun(arr));
    return 0;
}