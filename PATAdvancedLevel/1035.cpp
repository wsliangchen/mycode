#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

struct stu
{
    string a,b;
};

void string_replace(string & strBig, const string & strsrc, const string &strdst)
{
    string::size_type pos=0;
    string::size_type srclen=strsrc.size();
    string::size_type dstlen=strdst.size();
    while( (pos=strBig.find(strsrc, pos)) != string::npos)
    {
        strBig.replace(pos, srclen, strdst);
        pos += dstlen;
    }
}

bool judge(string &a){
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == '1' || a[i] == '0' || a[i] == 'l' || a[i] == 'O')
            return true;
    }
    return false;
}

void replace(string &a){
    string_replace(a, "1","@");
    string_replace(a, "0","%");
    string_replace(a, "l","L");
    string_replace(a, "O","o"); 
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    vector<stu> v;
    for(int i = 0; i < n; i++)
    {
        string a,b;
        cin >>a >> b;
        if(judge(b) == true){
            replace(b);
            v.push_back(stu{a,b});
        }
    }
    if(v.size() == 0) {
        printf("There %s %d %s and no account is modified\n", n > 1?"are":"is", n, n > 1?"accounts":"account");
        return 0;
    }
    printf("%d\n", v.size()); 
    for(int i = 0; i < v.size(); i++)
    {
        cout<<v[i].a<<" "<<v[i].b<<endl;
    }
    
    return 0;
}