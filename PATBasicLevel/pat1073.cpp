#include <stdio.h>

using namespace std;
//typedef是c中声明结构体的方式cpp中使用会出错
struct question
{
    int maxScore;
    int optionNum;
    int bingoOptionNum;
    char bingo[5];
    int errorTimes[5] = {0};
};

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    question q[m];
    double stuScore[n];
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &q[i].maxScore, &q[i].optionNum, &q[i].bingoOptionNum);
        for (int j = 0; j < q[i].bingoOptionNum; j++)
            scanf("%*[ ]%c", &q[i].bingo[j]);
    }

    //第i+1个学生
    for (int i = 0; i < n; i++)
    { //初始化计分数组
        stuScore[i] = 0;
        //第j+1道题目
        for (int j = 0; j < m; j++)
        {
            int k;
            scanf("%*[^0-9]%d", &k);
            char tempAnswer[k]; //先把每道题答案读进来
            for (int l = 0; l < k; l++)
                scanf("%*[() ]%c", &tempAnswer[l]);
            //判断对错情况并记录错误选项
            int bingoCount = 0;
            for (int ii = 0; ii < k; ii++)
            {                               //2.学生选出的错误答案统计
                bool isChooseBingo = false; //该选项是否正确
                for (int jj = 0; jj < q[j].bingoOptionNum; jj++)
                {
                    if (q[j].bingo[jj] == tempAnswer[ii])
                    {
                        isChooseBingo = true;
                        bingoCount++;
                    }
                }

                if (isChooseBingo == false)
                {
                    q[j].errorTimes[tempAnswer[ii] - 'a']++;
                }
            }
            //2.统计学生没有选出来的正确答案
            for (int ii = 0; ii < q[j].bingoOptionNum; ii++)
            {
                bool isChooseExist = false;
                for (int jj = 0; jj < k; jj++)
                {
                    if (q[j].bingo[ii] == tempAnswer[jj])
                        isChooseExist = true;
                }
                if (isChooseExist == false)
                    q[j].errorTimes[q[j].bingo[ii] - 'a']++;
            }
            //全对
            if (k == bingoCount && bingoCount == q[j].bingoOptionNum)
            {
                stuScore[i] = q[j].maxScore + stuScore[i];
            }
            else if (k == bingoCount && bingoCount < q[j].bingoOptionNum) //半对
            {
                stuScore[i] = stuScore[i] + 1.0*q[j].maxScore / 2;
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%.1lf\n", stuScore[i]);

    int count = 0;
    int maxErrorTime = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q[i].optionNum; j++)
        {
            if (q[i].errorTimes[j] > maxErrorTime)
            {
                maxErrorTime = q[i].errorTimes[j];
                count++;
            }
        }
    }

    if (count == 0)
        printf("Too simple\n");
    else
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < q[i].optionNum; j++)
            {
                if (q[i].errorTimes[j] == maxErrorTime)
                {
                    printf("%d %d-%c\n", maxErrorTime, i + 1, j + 'a');
                }
            }
        }
    }
    return 0;
}
