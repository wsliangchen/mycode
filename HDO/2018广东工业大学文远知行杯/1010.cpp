#include <map>
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

char mapped[][4] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};
map<char, int> mp;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);//关闭流同步加速iostream 500ms并不理想
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 3; j++)
            mp[mapped[i][j]] = i + 2; //对应到映射中
    }

    int n;
    map<string, int> res;
    while (cin >> n)
    {
        res.clear();//每轮清空res集
        for (int i = 0; i < n; i++)
        {
            string str, temp;
            cin >> str;
            int cnt = 0;
            for (int j = 0; j < str.length(); j++)
            {
                if (cnt == 3) //只有符合条件的才处理
                {
                    temp += '-';
                    cnt++;
                }
                if (isdigit(str[j]))
                {
                    temp += str[j];
                    cnt++;
                }
                else if (isalpha(str[j]))
                { //字母转数字
                    temp += (mp[str[j]] + '0');
                    cnt++;
                }
            }
            res[temp]++;
        }
        int cnt = 0;
        for (auto it = res.begin(); it != res.end(); it++)
        {
            if (it->second > 1)
            {
                cout << it->first << " " << it->second << endl;
                cnt = 1;
            }
        }
        if (cnt == 0)
            cout << "No duplicates." << endl;
    }

    return 0;
}