#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string longsum(string s)
{
    string res;
    int redis = 0;//下一轮的余数
    for(size_t i = 0; i < s.length(); i++)
    {
        int temp = s[i]-'0' + s[s.length()-1-i]-'0' + redis;
        res += (temp%10+'0');
        redis = temp/10;
    }
    if(redis != 0)
        res += (redis+'0');//最后一轮剩下的数
    reverse(res.begin(), res.end());//相加之后是倒过来的
    return res;
}

bool judgePalindromic(string res)
{
    for(size_t i = 0; i <= res.length()/2; i++)
    {
        if(res[i] != res[res.length()-1-i])
            return false;
    }
    return true;
}

int main()
{
    string str;
    cin>>str;
    if(judgePalindromic(str))//本身给出的数就是回文数
    {
        cout<<str<<" is a palindromic number."<<endl;
        return 0;
    }

    int i = 0;
    for(; i < 10; i++)
    {
        string res = longsum(str);
        cout<<str<<" + ";
        reverse(str.begin(), str.end());
        cout<<str<<" = "<<res<<endl;
        if(judgePalindromic(res))
        {
            cout<<res<<" is a palindromic number."<<endl;
            return 0;
        }
        str = res;
    }
    if(i == 10)//循环到第十次还不是回文数
        cout<<"Not found in 10 iterations."<<endl;
    return 0;
}
