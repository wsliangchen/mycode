#include <cstdio>
#include <cstring>

typedef long long ll;

using namespace std;
const int size = 1000020;
int trie[size][26], tot = 1;
int end[size];
char str[size];
void insert(char *s) {
    int len = strlen(s), p = 1;
    for (int i = 0; i < len; i++) {
        int ch = s[i] - 'a';
        if (trie[p][ch] == 0)
            trie[p][ch] = ++tot;
        p = trie[p][ch];
    }
    end[p]++;
}

int search(char *s) {
    int p = 1,ans = 0;
    for (int i = 0; s[i]; i++) {
        int ch = s[i] - 'a';
        if (trie[p][ch] == 0)
            return ans;
        p = trie[p][ch];
        ans += end[p];
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    int n, m, ans = 0;
    scanf("%d%d", &n,&m);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(str);
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", str);
        printf("%d\n", search(str));
    }

    return 0;
}