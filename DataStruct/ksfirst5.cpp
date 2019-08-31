#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stack>

using namespace std;

stack<char> mystack;

int judge_line(char *str)
{
    if (str[0] != '(') {
        int temp;
        sscanf(str, "%d", &temp);
        return temp;
    }else if (str[0] == '(') {
        int res = 0, tempsum = 0;
        for(int i = 0; i < strlen(str); i++)
        {
            tempsum = 0;
            if (str[i] == '+'  || str[i] == '-' || str[i] == '*' || str[i] == '/') {
                mystack.push(str[i]);
                int j;
                for(j = i+1; isdigit(str[j]); j++)
                    tempsum += str[j] - '0';
                if (str[j] == ')') {
                    char ch = mystack.top();
                    mystack.pop();
                    if (ch == '+') {
                        res += tempsum;
                    }else if (ch == '-') {
                        res -= tempsum;
                    }else if (ch == '*') {
                        res *= tempsum;
                    }else if (ch == '/') {
                        if (tempsum != 0) {
                            res /= tempsum;
                        }else
                            printf("Error!");
                    }
                }
            }
        }
        return res;
    }
}

int main(int argc, char const *argv[])
{
    char line[1001];
    while(line[0] != '#'){
        fgets(line, 1001, stdin);
        printf("result = %d\n",judge_line(line));
    }
    return 0;
}