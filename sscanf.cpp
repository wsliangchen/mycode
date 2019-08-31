#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{/*
    char a[50], b[50];
    gets(a);	
    double temp;
    sscanf(a, "%lf", &temp);
    sprintf(b, "%.2lf", temp);

    puts(a);
    puts(b);*/
    char str[512] = {0};
    sscanf("123456", "%s", str);
    printf("str=%s\n", str);

    sscanf("123456abAcdedfBCDEF","%[1-9a-z]",str);
    printf("str=%s\n",str);

    sscanf("123456a0bcd edf","%[^ ]",str);
    printf("str=%s\n",str);

    sscanf("123456a0bcd edf","%[^0]",str);
    printf("str=%s\n",str);

    sscanf("123456abcRdedfBCDEF","%[1-9a-z]",str);//遇到空格也会停止读取
    printf("str=%s\n",str);
/*
    string stime("2009-01-02_11:12:13");
    sscanf(stime.c_str(), "%4d-%2d-%2d_%2d:%2d:%2d",)
    sscanf(stime.c_str(), "%4d%c%2d%c%2d%c%2d%c%2d%c%2d",
    sscanf(stime.c_str(), "%4d%1s%2d%1s%2d%1s%2d%1s%2d%1s%2d",
*/
    return 0;
}