#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

bool finded(map<string, vector<int>>& mp, string& s)
{
    if (mp[s].empty())
        return false;
    return true;
}

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    map<string, vector<int>> title_id, author_id, key_id, publisher_id, year_id;

    for (int i = 0; i < n; i++) {
        int id, year;
        cin >> id;
        getchar();
        string s[5], buf;
        for (int i = 0; i < 5; i++)
            getline(cin, s[i]);

        stringstream ss(s[2]); //切割keywords
        while (ss >> buf) {
            key_id[buf].push_back(id);
        }
        title_id[s[0]].push_back(id);
        author_id[s[1]].push_back(id);
        publisher_id[s[3]].push_back(id);
        year_id[s[4]].push_back(id);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int op;
        string se;
        cin >> op;

        getchar();
        getchar();
        getline(cin, se);
        cout << op << ": " << se << endl;
        switch (op) {
        case 1:
            if (finded(title_id, se)) {
                sort(title_id[se].begin(), title_id[se].end());
                for (int j = 0; j < title_id[se].size(); j++) {
                    printf("%07d\n", title_id[se][j]);
                }
            }else printf("Not Found\n");
            break;
        case 2:
            if (finded(author_id, se)) {
                sort(author_id[se].begin(), author_id[se].end());
                for (int j = 0; j < author_id[se].size(); j++) {
                    printf("%07d\n", author_id[se][j]);
                }
            }else printf("Not Found\n");
            break;
        case 3:
            if (finded(key_id, se)) {
                sort(key_id[se].begin(), key_id[se].end());
                for (int j = 0; j < key_id[se].size(); j++) {
                    printf("%d\n", key_id[se][j]);
                }
            }else printf("Not Found\n");
            break;
        case 4:
            if (finded(publisher_id, se)) {
                sort(publisher_id[se].begin(), publisher_id[se].end());
                for (int j = 0; j < publisher_id[se].size(); j++) {
                    printf("%07d\n", publisher_id[se][j]);
                }
            }else printf("Not Found\n");
            break;
        case 5:
            if (finded(year_id, se)) {
                sort(year_id[se].begin(), year_id[se].end());
                for (int j = 0; j < year_id[se].size(); j++) {
                    printf("%07d\n", year_id[se][j]);
                }
            }else printf("Not Found\n");
            break;
        default:
            break;
        }
    }

    return 0;
}