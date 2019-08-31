#include <cstdio>
#include <cmath>
using namespace std;
//仔细审题！
//该点像素值要比周围的像素值都大
//测试点3这个点的像素值只能在图像中出现一次
//测试点5矩阵只有一个元素
//改进后用map判断是否唯一的点会更快

//判断下标是否合法
bool judgeIndexIsLeagl(int i, int j, int m, int n)
{
    if (i >= m || i < 0 || j >= n || j < 0)
        return false;
    else
        return true;
}

int main(int argc, char const *argv[])
{
    int m, n, i, j, x = 0, y = 0, tol, sum = 0;
    scanf("%d %d %d", &n, &m, &tol);
    int maxtri[m][n];

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &maxtri[i][j]);
        }
    }
    //该点像素值要比周围的像素值都大
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            bool judgeFlag = true;
            //这两层循环是与该元素周围的8个元素进行对比
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (k == 0 && l == 0) //去除和自己判断
                        continue;
                    if (judgeIndexIsLeagl(i + k, j + l, m, n) == true)
                    {//下标合法再进一步判断//坑爹的测试点3  必须加abs绝对值
                        int sub = abs(maxtri[i][j] - maxtri[i + k][j + l]);
                        if (sub <= tol)
                        {
                            judgeFlag = false;
                            break;
                        }
                    }
                }
                if (judgeFlag == false)
                    break;
            }
            if (judgeFlag == true)
            { //测试点唯一的点：这个点的像素值只能在矩阵中出现一次.
                bool flag = true;
                for (int mm = 0; mm < m; mm++)
                {
                    for (int nn = 0; nn < n; nn++)
                    { //排除和自己本身比较
                        if (mm == i && nn == j)
                            continue;
                        if (maxtri[mm][nn] == maxtri[i][j])
                            flag = false;
                    }
                }
                if (flag == true)
                {
                    x = i;
                    y = j;
                    sum++;
                }
            }
        }
    }
    if (m == 1 && n == 1) //测试点5矩阵只有一个元素
    {
        printf("(%d, %d): %d", y + 1, x + 1, maxtri[x][y]);
        return 0;
    }
    if (sum == 0)
        printf("Not Exist");
    else if (sum == 1)
        printf("(%d, %d): %d", y + 1, x + 1, maxtri[x][y]);
    else
        printf("Not Unique");

    return 0;
}
