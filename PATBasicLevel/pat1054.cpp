#include <stdio.h>
#include <string.h> 
//此代码测试点2   题目给出的数据长度大于30数组要长一点
//第三个测试点考虑的是当K等于1的情况 
//第四个测试点考虑的是[-1000，1000]边界情况，但若考虑小数点位于数最后一位是非法数，则此测试点也不能通过
//更好的办法是        sscanf(a, "%lf", &temp);//按格式读出来
//                   sprintf(b, "%.2lf", temp);//再将读出的数放到数组  
//                      利用缓冲区进行格式化判定
using namespace std;

int isLeagle(const char*s)
{
    int i;
    int pointNum = 0,tailNumSum = 0,frontNumSum = 0;
    int tfflag = 0;
    for(i = 0; i < strlen(s); i++)
    {
        if(i == 0 && s[i] == '-')
            continue;
        if(s[i] > '9' || s[i] < '0')
        {
            if(s[i] != '.')
                return 0;
        }

        if(s[i] == '.')
        {
            pointNum++;
            tfflag = 1;
            continue;
        }
        if(tfflag == 0)
            frontNumSum++;
        else
            tailNumSum++;
    }

    if(tailNumSum > 2|| pointNum > 1 || frontNumSum > 4)
        return 0;
    double d;
    sscanf(s,"%lf", &d);
    if(d < -1000 || d > 1000)
       return 0;

    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    char str[n][50];

    int i;
    for(i = 0; i < n; i++)
        scanf("%s", str[i]);

    int leagleNum = 0;
    double leagleNumSum = 0;
    for(i = 0; i < n; i++)
    {
        if(isLeagle(str[i]) != 1)
        {
            printf("ERROR: %s is not a legal number\n", str[i]);
        }
        else
        {
            leagleNum++;
            double d;
            sscanf(str[i],"%lf", &d);
            leagleNumSum += d;
        }
    }

    if(leagleNum > 1)
        printf("The average of %d numbers is %.2lf", leagleNum, leagleNumSum/leagleNum);
    if(leagleNum == 1)
        printf("The average of 1 number is %.2lf",leagleNumSum);
    if(leagleNum == 0)
        printf("The average of 0 numbers is Undefined");

    return 0;
}
