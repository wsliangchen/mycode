#include <cstdio>
#include <iostream>
using namespace std;
//递归辗转相除找最大公约数
/*
int judge(int a, int b){
    return b == 0 ? a : judge(b, a % b);
}
*/
int judge(int a, int b)
{
    for(int r; (r = a % b); a = b, b = r) ;
    return b;
}

int main()
{
    int a,b,c,d,k,count = 0;
    scanf("%d/%d %d/%d %d", &a, &b, &c, &d, &k);

    if(a*d > b*c)//小的分数放前面
    {
        swap(a,c);
        swap(b,d);
    }

                    //需要注意上界不能等于
    for(int min = a*k/b+1; min*d < c*k ; min++)
    {
        if(judge(min, k) == 1)
            printf("%s%d/%d", count++?" ":"",min, k);
    }
    return 0;
}
