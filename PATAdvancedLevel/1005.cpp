#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    char num[10][8] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char str[10005],res[10005];
    scanf("%s", str);
    double sum = 0;
    for(int i = 0; i < strlen(str); i++)
        sum += str[i] - '0';

    sprintf(res, "%.0lf", sum);

    for(int i = 0; i < strlen(res); i++)
        printf("%s%s",i?" ":"",num[res[i]-'0']);

    return 0;
}