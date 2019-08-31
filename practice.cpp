#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int k, i, j;
	scanf("%d", &k);
	int storage[k];
	int flag[k];
	//flag[i] = 0 表示stroage[i] 这个地方存的数没有覆盖
	for (i = 0; i < k; i++)
	{
		scanf("%d", &storage[i]);
		flag[i] = 0;
	}

	sort(storage, storage + k);

	for (i = k - 1; i >= 0; i--)
	{
		if (flag[i] != 0)
			continue;
		int n = storage[i];
		while (n != 1)
		{
			if (n % 2 == 0)
				n /= 2;
			else
				n = (3 * n + 1) / 2;

			//这个for循环的作用是遍历每个storage里面存的数字
			//将每个计算出来的n跟他们做对比，重复则说明被覆盖flag
			for (j = k - 1; j >= 0; j--)
			{
				if (n == storage[j])
				{
					flag[j] = 1;
					break;
				}
			}
		}
	}

	int blank = 0;

	for (i = k - 1; i >= 0; i--)
	{
		if (flag[i] == 0)
		{
			printf("%s%d", blank == 0 ? "" : " ", storage[i]);
			blank++;
		}
	}
	return 0;
}
