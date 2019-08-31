#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define symble 18140906

int Judge(int date1, int data2)
{
    if(date1-data2 >= 0 && date1 <= 20140906)
        return 0;
    else
        return 1;
}

int main()
{
    int year,month,day;
    int dateAmount;//生日总数
    int effDateAmount = 0;//有效生日个数
    int i;

    if(scanf("%d", &dateAmount) <= 0)
        return 0;

    int date[dateAmount];
    char name[dateAmount][6];
    for(i = 0;i < dateAmount; i++)
    {
        char temp[6];
        if(scanf("%s%d/%d/%d", temp, &year, &month, &day) <= 0)
            return 0;

        int cal = year*10000+month*100+day;
        if(Judge(cal, symble) == 0)
        {
            date[effDateAmount] = cal;
            strcpy(name[effDateAmount], temp);
            effDateAmount++;
        }
    }

    int maxIndex = 0,minIndex = 0;

    for(i = 0; i < effDateAmount; i++)
    {
        if(Judge(date[maxIndex], date[i]) == 0)
            maxIndex = i;
        if(Judge(date[minIndex], date[i]) == 1)
            minIndex =i;
    }

    //有效生日为0的时候只需要输出一个0即可
    if(effDateAmount == 0)
        printf("%d", 0);
    else
        printf("%d %s %s", effDateAmount, name[maxIndex], name[minIndex]);

    return 0;
}
