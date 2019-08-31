#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int cnt, stack[31];

void rev(int p)
{
    for(int i = 0; i < p-i; i++)
    {
        swap(stack[i], stack[p - i]);
    }
    printf("%d ", cnt-p);
}

int main(int argc, char const *argv[])
{
    string s;

    while(getline(cin,s)){
        cout << s << endl;
        stringstream ss(s);

        cnt = 0;
        while(ss >> stack[cnt])
            cnt++;
        
        for(int i = cnt-1; i >= 0; i--)
        {
            int p = max_element(stack, stack + cnt) - stack;
            if (i == p)
                continue;
            
            if (p > 0)
                rev(p);
            rev(i);
        }
        printf("0\n");
    }

    return 0;
}