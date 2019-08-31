#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

struct node
{
    char data;
    int weight;
    string *code; //string是对象  需要new构造并赋值给code指针
    node *left, *right;
} treenode;

typedef pair<char, int> mk_pair;   //char-weight pair
typedef pair<node *, int> aw_pair; //address-weight pair

//按权值大小排序
bool cmp(mk_pair a, mk_pair b)
{
    return a.second > b.second;
}

bool awcmp(aw_pair a, aw_pair b)
{
    return a.second > b.second;
}

//读取字符-权值对
int read_char_weight(vector<mk_pair> &v)
{
    FILE *fp;
    char in_filename[] = "hufman_char_weight.txt";
    if ((fp = fopen(in_filename, "r")) == NULL)
    {
        printf("%s not find!\n", in_filename);
        return -1;
    }
    else
    {
        char buf[1024];
        while (!feof(fp))
        {
            fgets(buf, 1024, fp);
            char c;
            int w;
            sscanf(buf, "%c%d", &c, &w);
            v.push_back(mk_pair(c, w));
        }
    }
    fclose(fp);
    sort(v.begin(), v.end(), cmp);
    return 0;
}

//读取没有编码的原数据并且根据权值大小排序
int read_original_input(vector<mk_pair> &v, string &s)
{
    map<char, int> mp; //frequence of every character

    FILE *fp;
    char in_filename[] = "hufman_string_original.txt";
    if ((fp = fopen(in_filename, "r")) == NULL)
    {
        printf("%s not find!\n", in_filename);
        return -1;
    }
    else
    {
        char c;
        do
        {
            c = fgetc(fp);
            if (feof(fp))
                break;

            if (c != '\n')
            {
                mp[c]++; //存入映射统计频数
                s += c;  //原文存到string里面
            }
        } while (1);
    }
    fclose(fp);
    for (auto it = mp.begin(); it != mp.end(); it++)
        v.push_back(mk_pair(it->first, it->second));

    sort(v.begin(), v.end(), cmp);

    return 0;
}

//创建新节点并初始化
node *mk_new_node()
{
    node *p = (node *)malloc(sizeof(node));

    p->data = '\0';
    p->weight = 0;
    p->left = NULL;
    p->right = NULL;

    p->code = new string; //特别注意string构造

    return p;
}

//构造哈夫曼树
node *mk_hufmantree(vector<mk_pair> &v, vector<aw_pair> &res)
{
    vector<aw_pair> aw;
    for (int i = 0; i < v.size(); i++)
    {
        node *p = mk_new_node();
        p->data = v[i].first;
        p->weight = v[i].second;
        aw.push_back(aw_pair(p, p->weight));
        res.push_back(aw_pair(p, p->weight));
    }

    while (aw.size() > 1)
    {
        sort(aw.begin(), aw.end(), awcmp);
        int size = aw.size();
        node *p = mk_new_node();
        p->weight = aw[size - 1].second + aw[size - 2].second;
        p->left = aw[size - 1].first; //合并节点权值小的放左边
        p->right = aw[size - 2].first;
        aw.pop_back();
        aw.pop_back();                       //删除最后两个最小的
        aw.push_back(aw_pair(p, p->weight)); //合成的节点导进去
    }

    return aw[0].first;
}

//前序递归遍历记录每个字符的哈夫曼编码
void traverse(node *root, string s)
{
    string str = s;
    if (root->left != NULL || root->right != NULL)
    {
        if (root->left != NULL)
        {
            traverse(root->left, str + '0');
        }
        if (root->right != NULL)
        {
            traverse(root->right, str + '1');
        }
    }
    else
    {
        *(root->code) = str;
        //cout << root->data << " = " << *(root->code) << endl;
    }
}

//编码转换成字符串
void code_to_string(string &s, node *root)
{
    node *p = root;
    printf("Hufman code to string : ");
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            p = p->left;
        }
        else if (s[i] == '1')
        {
            p = p->right;
        }
        if (p->left == NULL && p->right == NULL)
        {
            printf("%c", p->data);
            p = root;
        }
    }
    printf("\n");
}

//操作一整合 从文件读取字符串并且输出每个字符的哈夫曼编码
node *from_file_string_to_hufmancode(map<char, string> &code, string &s, vector<aw_pair> &res, vector<mk_pair> &v)
{
    if (read_original_input(v, s) == -1)
        return NULL;
    node *root = mk_hufmantree(v, res);

    string temp = "";
    traverse(root, temp);

    for (int i = 0; i < res.size(); i++)
        code[res[i].first->data] = *(res[i].first->code);
    return root;
}

//操作二整合 从文件读取字符-权值对输出哈夫曼编码
node *from_file_key_weight_to_hufmancode(map<char, string> &code, vector<aw_pair> &res, vector<mk_pair> &v)
{

    if (read_char_weight(v) == -1)
        return NULL;
    node *root = mk_hufmantree(v, res);

    string temp = "";
    traverse(root, temp);

    for (int i = 0; i < res.size(); i++)
        code[res[i].first->data] = *(res[i].first->code);
    return root;
}

//操作三整合   哈夫曼编码翻译成字符串
int hufmancode_to_string(string &hcode, node *root)
{

    FILE *fp;
    char in_filename[] = "hufmancode_original.txt";
    if ((fp = fopen(in_filename, "r")) == NULL)
    {
        printf("%s not find!\n", in_filename);
        return -1;
    }
    else
    {
        char c;
        do
        {
            c = fgetc(fp);
            if (feof(fp))
                break;

            if (c != '\n')
            {
                hcode += c; //编码原文存到string里面
            }
        } while (1);
    }

    code_to_string(hcode, root);
}

void print_menu()
{
    printf("*****************************\n\
     HufmanCode  Menu\n\
-----------------------------\n\
1.Read string from file to hufmancoed.\n\
2.Read key-weight pairs to hufmancode.\n\
3.Translae hufmancode to string.\n\
4.Clear hufmantree and last result.\n\
5.Print menu.\n\
0.Exit programe.\n\
operate order:1->3->2>->4->0\n\
*****************************\n");
}

int main(int argc, char const *argv[])
{
    map<char, string> code; //字符-哈夫曼编码对
    vector<aw_pair> res;    //每个包含字符的结构体地址-权值对
    vector<mk_pair> v;      //字符-权值对
    string str_to_code;     //原字符串
    node *root = NULL;      //树的根节点

    //交互框架
    int op = -2;
    while (1)
    {
        if (op == -2)
            print_menu();
        printf("\nPlease switch your operation(op 5 print menu):");
        cin >> op;
        if (op == 1)
        {
            root = from_file_string_to_hufmancode(code, str_to_code, res, v); //取得树的根节点
            cout << "\nOriginal text : " << str_to_code << endl;
            cout << "Each character's weight and hufmancode." << endl;
            for (auto it = res.begin(); it != res.end(); it++) //打印每个字符的哈夫曼编码
            {
                cout << "[" << it->first->data << "] weight = " << it->second << " code = " << (*(it->first->code)) << endl;
            }
            cout << "Hufmanode : ";
            for (int i = 0; i < str_to_code.length(); i++) //打印原字符串的编码
            {
                cout << code[str_to_code[i]];
            }
            cout << endl;
        }
        if (op == 2)
        {
            for (int i = 0; i < res.size(); i++)//重新根据文件中的字符权值生成树
                free(res[i].first);
            res.clear();
            code.clear();
            v.clear();
            free(root);
            root = from_file_key_weight_to_hufmancode(code, res, v);
            cout << "\nOriginal text : " << str_to_code << endl;
            cout << "Each character's weight and hufmancode." << endl;
            for (auto it = res.begin(); it != res.end(); it++) //打印每个字符的哈夫曼编码
            {
                cout << "[" << it->first->data << "] weight = " << it->second << " code = " << (*(it->first->code)) << endl;
            }
            cout << "Hufmanode : ";
            for (int i = 0; i < str_to_code.length(); i++) //打印原字符串的编码
            {
                cout << code[str_to_code[i]];
            }
            cout << endl;
        }
        if (op == 3)
        {
            string hcode;
            if (root == NULL)
                printf("Hufmantree Uninitialized! op 1 or 2 init it.\n");
            else
            {
                printf("\n");
                if (hufmancode_to_string(hcode, root) != -1)
                    cout << "Original hufmancode : " << hcode << endl;
            }
        }
        if (op == 4) //重置
        {
            code.clear();
            for (int i = 0; i < res.size(); i++)
                free(res[i].first);

            res.clear();
            v.clear();
            str_to_code.clear();
            free(root);
            root = NULL;
            cout << "Clear OK!" << endl;
        }
        if (op == 5)
            print_menu();

        if (op == 0)
            return 0;

        op = -1;
    }
    return 0;
}