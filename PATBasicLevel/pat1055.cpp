#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

struct student
{
    string name;
    int height;
};

bool cmp(student a, student b)
{
    return (a.height == b.height) ? a.name < b.name : a.height > b.height;
}
/**每一行从左开始先倒序输出奇数位的人名，再顺序输出偶数位的人名。这里按照已排好的顺序从0计数。
 *  输出7个人名就是5 3 1 0 2 4 6，
 */
void printrow(student s[], int num)
{
    for(int i = num / 2 * 2 - 1; i > 0; i -= 2)     // on the left
        printf("%s ", s[i].name.c_str());
    for(int i = 0; i < num; i += 2)                 // on the right
        printf("%s%c", s[i].name.c_str(), i + 2 < num ? ' ' : '\n');
}

int main(int argc, char const *argv[])
{
    int n, row;
    scanf("%d%d", &n, &row);
    student stu[n];

    for (int i = 0; i < n; i++)
        cin >> stu[i].name >> stu[i].height;

    sort(stu, stu + n, cmp); //因为要倒着输出所以倒着排序
    //每行几个人	        最后一行多少人
    int rownum = n / row, lastrownum = rownum + n % row;

    student *p = stu;
    printrow(p, lastrownum);//先打印第一行
    for(p += lastrownum; p < stu + n; p += rownum)
        printrow(p, rownum);

    return 0;
}