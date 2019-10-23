#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > v(2);

int main() {
    fstream out("output.txt", ios::out);
    int a;
    int cnt = 0;
    while (cin >> a) {
        if (a == -1)
            break;
        v[cnt % 2].push_back(a);
        cnt++;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < v[i].size(); j++) {
            v[i][j] += v[i][j - 1];
        }
    }
    cout << "enter" << endl;
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        int sum = 0;
        for (int j = 0; j < v[i].size(); j++) {
            sum += v[i][j];
        }
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}
