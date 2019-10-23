#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int match(char *exp, int n){
    char stack[100];
    int top = -1;
    for(int i = 0; i < n; i++)
    {
        if(exp[i] == '(' || exp[i] == '[')
            stack[++top] = exp[i];
        if(exp[i] == ')' && stack[top] == ')' && top != -1)
            top--;
        else return 0;
        if(exp[i] == ']' && stack[top] == ']' && top != -1)
            top--;
        else return 0;
    }
    printf("final top = %d\n", top);
    if(top == -1) return 1;
    else return 0;
}

int main(int argc, char const *argv[]) {
    char a[100];
    scanf("%s", a);
    printf("%d", match(a,strlen(a)));
    
    return 0;
}