#include <stdio.h>

using namespace std;
typedef struct question
{
    int maxScore;
    int optionNum;
    int bingoOptionNum;
    char bingo[5];
    int errorTimes = 0;
};

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    question q[m];
    int stuScore[n];
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
            bool isRight = true;
            scanf("%*[^0-9]%d", &k);
            if (k == q[j].bingoOptionNum)
            {
                for (int l = 0; l < k; l++)
                {
                    char c;
                    scanf("%*[() ]%c", &c);
                    if (q[j].bingo[l] != c)
                        isRight = false;
                }
            }
            else
            {
                q[j].errorTimes++;
                continue;
            }

            if (isRight == true)
                stuScore[i] += q[j].maxScore;
            else
                q[j].errorTimes++;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d\n", stuScore[i]);

    int count = 0;
    int maxErrorTime = 0;
    for (int i = 0; i < m; i++)
    {
        if (q[i].errorTimes > maxErrorTime)
        {
            maxErrorTime = q[i].errorTimes;
            count++;
        }
    }

    if (count == 0)
        printf("Too simple\n");
    else
    {
        printf("%d", maxErrorTime);
        for (int i = 0; i < m; i++)
        {
            if (q[i].errorTimes == maxErrorTime)
                printf(" %d", i+1);
        }
    }
    return 0;
}
