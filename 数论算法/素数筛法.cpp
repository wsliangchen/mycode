#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define maxn 100000

int v[maxn], prime[maxn];

bool is_prime(int n) {
    int k = sqrt(n);
    for (int i = 2; i <= k; i++)
        if (n % i == 0)
            return false;
    return true;
}

// eratosthenes筛法 接近线性
void eratosthenes(int n) {
    memset(v, 0, sizeof(v));
    for (int i = 2; i <= n; i++) {
        if (v[i])
            continue;
        for (int j = i; i <= n / i; j++)
            v[i * j] = 1;
    }
}

//线性筛法 限定合数只被最小质因子筛一次
void primes(int n) {
    memset(v, 0, sizeof(v));
    int m = 0; //素数数量
    for (int i = 2; i <= n; i++) {
        if (v[i] == 0)
            v[i] = i, prime[++m] = i;
        for (int j = 1; j <= m; j++) {
            if (prime[j] > v[i] || prime[j] > n / i)
                break;
            v[i * prime[j]] = prime[j];
        }
    }
    // for (int i = 1; i <= m; i++)
    //     printf("%d\n", prime[i]);
    // for (int i = 1; i <= n; i++)
    //     if (v[i] == i)
    //         printf("%d\n", v[i]);
}

int main(int argc, char const *argv[]) {
    primes(1000);
    getchar();
    return 0;
}