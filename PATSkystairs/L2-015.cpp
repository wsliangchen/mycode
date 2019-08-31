#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    int score[k];
    vector<double> res;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
            scanf("%d", &score[j]);
        sort(score, score + k);
        int sum = 0;
        for(int j = 1; j < k-1; j++)
            sum += score[j];
        res.push_back(1.0 * sum / (k - 2));
    }
    sort(res.begin(), res.end());
    for(int i = res.size()-m; i < res.size(); i++)
    {
        printf("%s%.3lf", i==res.size()-m?"":" ", res[i]);
    }
    
    return 0;
}
