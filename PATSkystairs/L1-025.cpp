#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool is_leagl(string s)
{
    if (s.length() == 0)
        return false;
    for (int i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
            return false;
    }

    int temp = stoi(s);
    if (temp < 1 || temp > 1000)
        return false;
    return true;
}

int main()
{
    string a, b, t;
    getline(cin, t);//a可能为空字符串
    for(int i = 0; i < t.length(); i++)//找到第一个空格切出a,b
    {
        if (t[i] == ' ') {
            a = t.substr(0, i);
            b = t.substr(i + 1, t.length() - i - 1);
            break;
        }
    }
    
    if (!is_leagl(a))
        a = "?";
    if (!is_leagl(b))
        b = "?";

    cout << a << " + " << b << " = ";
    if (a != "?" && b != "?") {
        int atemp = atoi(a.c_str()), btemp = atoi(b.c_str());
        cout << atemp + btemp;
    }else
    {
        cout << "?";
    }
    

    return 0;
}
