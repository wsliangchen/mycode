#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n, temp;
    cin >> n;
    int count[10000] = {0};

    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        count[abs(i - temp)]++;
    }

    for (int i = 9999; i >= 0; i--)
    {
        if (count[i] > 1)
            cout << i << " " << count[i] << endl;
    }

    return 0;
}
