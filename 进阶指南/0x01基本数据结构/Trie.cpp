#include <cstdio>
#include <cstring>

using namespace std;

const int SIZE = 100010;

int trie[SIZE][26], tot = 1;
bool end[SIZE];
void insert(char *str) {
    int len = strlen(str), p = 1;
    for (int i = 0; i < len; i++) {
        int ch = str[i] - 'a';
        if(trie[p][ch] == 0) trie[p][ch] = ++tot;
        p = trie[p][ch];
        printf("%d ", p);
    }
    end[p] = true;
}

bool search(char *str) {
    int p = 1;
    for(int i = 0; str[i]; i++){
        p = trie[p][str[i] - 'a'];
        if(p == 0) return false;
    }
    return end[p];
}

int main(int argc, char const *argv[]) { 
    char *s = "xcc";
    insert(s);
    char *t = "tcc";
    insert(t);
    return 0; 
}