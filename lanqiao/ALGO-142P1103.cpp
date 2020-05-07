#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

typedef long long ll;

#define PI acos(-1.0)
using namespace std;

struct fs {
    double shi;
    double xu;
} res;

fs* add(fs a, fs b){
    res.shi = a.shi+b.shi;
    res.xu = a.xu+b.xu;
    return &res;
}

fs* sub(fs a, fs b){
    res.shi = a.shi-b.shi;
    res.xu = a.xu-b.xu;
    return &res;
}

fs* mul(fs a, fs b){
    res.shi = a.shi*b.shi-a.xu*b.xu;
    res.xu = a.xu*b.shi+a.shi*b.xu;
    return &res;
}

fs* div(fs a, fs b){
    double d = b.shi*b.shi+b.xu*b.xu;
    res.shi = (a.shi*b.shi+a.xu*b.xu)/d;
    res.xu = (a.xu*b.shi-a.shi*b.xu)/d;
    return &res;
}

int main(int argc, char const *argv[]) {
    char op;
    fs f1, f2;
    scanf("%c %lf%lf%lf%lf", &op, &f1.shi,&f1.xu,&f2.shi,&f2.xu);
    if(op == '+')
        add(f1,f2);
    if(op == '-')
        sub(f1,f2);
    if(op == '*')
        mul(f1,f2);
    if(op == '/')
        div(f1,f2);
    printf("%.2lf+%.2lfi", res.shi,res.xu);   
    return 0;
}