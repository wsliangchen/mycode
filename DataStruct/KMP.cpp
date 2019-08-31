#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

//对结果集按照元素出现次数从大到小排序

typedef pair<string, int> res_pair;

bool cmp(res_pair a, res_pair b) { return a.second > b.second; }

//计算kmp模式匹配算法的子串前缀表
void prefix_table(const string pattern, int *prefix) {
    prefix[0] = 0;
    int len = 0;
    size_t i = 1;
    while (i < pattern.length()) {
        if (pattern[i] == pattern[len]) {
            len++;
            prefix[i] = len;
            i++;
        } else {
            if (len > 0) {
                len = prefix[len - 1];
            } else {
                prefix[i] = len;
                i++;
            }
        }
    }
    //修正前缀表整体右移一位第一位变为-1
    for (int i = pattern.length() - 1; i > 0; i--) {
        prefix[i] = prefix[i - 1];
    }
    prefix[0] = -1;
}

int kmp_search(const char *text, const string pattern) {
    int cnt = 0;
    int n = pattern.length();
    int m = strlen(text);
    int *prefix = (int *)malloc(sizeof(int) * n);
    prefix_table(pattern, prefix); //计算前缀表
    // text[i] len(text) = m
    // pattern[j] len(pattern) = n
    int i = 0, j = 0;
    while (i < m) {
        if (j == n - 1 && text[i] == pattern[j]) {
            // printf("Found pattern at %d\n", i - j);
            cnt++;
            j = prefix[j];
        }
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            j = prefix[j];
            if (j == -1) {
                i++;
                j++;
            }
        }
    }
    free(prefix);
    return cnt;
}

void print_menu() {
    printf("*****************************\n\
  KMP Pattern Matching Menu\n\
-----------------------------\n\
1.Input find key words.\n\
2.Input text.\n\
3.Print result.\n\
4.Clear text and key words.\n\
5.Print menu.\n\
0.Exit programe.\n\
*****************************\n");
}

int main(int argc, char const *argv[]) {
    map<string, int> res; //结果集

    int op = -2;
    while (1) {
        if (op == -2) {
            print_menu();
        }
        printf("Please switch your operation(op 5 print menu):");
        cin >> op;
        if (op == 1) {
            ifstream infile;
            infile.open("cppkeywords.txt", ios::in);
            if (!infile.is_open())
                cout << "Open cppkeywords.txt failure" << endl;
            string temp;
            while (!infile.eof()) {
                infile >> temp;
                res[temp] = 0;
            }
            infile.close();
            printf("Key Words Input End.\nCount = %d\n", res.size());
        } else if (op == 2) {
            for (auto it = res.begin(); it != res.end();
                 it++) //上一轮的搜索结果重置
                res[it->first] = 0;

            FILE *fp;
            char buf[1024]; //每行最大读取的字符数
            if ((fp = fopen("input.txt", "r")) == NULL) //判断文件是否存在及可读
            {
                printf("Open input file error!\nCheck input file isn't "
                       "exist.\nPlease make the input file path same as this "
                       ".exe file.\n");
                return 0;
            }
            while (!feof(fp)) {
                fgets(buf, 1024, fp);
                if (buf[0] != '\n' && strlen(buf) >= 1)
                    for (auto it = res.begin(); it != res.end(); it++)
                        res[it->first] += kmp_search(buf, it->first);
            }
            fclose(fp);
            printf("Text Input End.\n");
        } else if (op == 3) {
            vector<res_pair> res_set;
            for (auto it = res.begin(); it != res.end(); it++)
                res_set.push_back(res_pair(it->first, it->second));
            //结果集从大到小排序
            sort(res_set.begin(), res_set.end(), cmp);
            for (size_t i = 0; i < res_set.size(); i++)
                printf("Key word:  %-15s Count= %d\n", res_set[i].first.c_str(),
                       res_set[i].second);

            cout << "Print End." << endl;
        } else if (op == 4) //清空搜索关键字
        {
            res.clear();
            printf("Clear Finished.\n");
        }

        else if (op == 5)
            print_menu();
        else if (op == 0)
            break;
        else
            cout << "Operation input wrong reinput it!" << endl;

        op = -1;
    }

    return 0;
}
