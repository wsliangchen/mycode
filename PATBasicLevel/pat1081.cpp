#include <cstdio>
#include <cctype>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        char c;
        int bit = 0;
        bool hasalphabet = false, hasnumber = false, leagle = true;
        while (scanf("%c", &c) == 1 && c != '\n')
        {
            if (isalpha(c))
            {
                hasalphabet = true;
            }
            if (isdigit(c))
            {
                hasnumber = true;
            }
            if (!isdigit(c) && !isalpha(c) && c != '.')
            {
                leagle = false;
            }
            bit++;
        }

        if (bit >= 6)
        {
            if (leagle && hasnumber && hasalphabet)
            {
                printf("Your password is wan mei.\n");
            }else if (hasnumber && hasalphabet)
            {
                printf("Your password is tai luan le.\n");
            }else if (hasalphabet && leagle)
            {
                printf("Your password needs shu zi.\n");
            }else if (hasnumber && leagle)
            {
                printf("Your password needs zi mu.\n");
            }
        }
        else
        {
            printf("Your password is tai duan le.\n");
        }
    }

    return 0;
}