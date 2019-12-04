//author:liangchen
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

const double PI = acos(-1.0);

vector<string> attributes;     //存放属性名
vector<vector<string>> data;   //数据集
vector<vector<string>> backup; //数据集备份
vector<string> lable;          //存放分类标签
// vector<double> result;           //各标签下的概率 P = (Xi|Ci)
vector<int> continu;             //连续的数值属性下标标号
unordered_map<int, double> mean; //数值各列均值
unordered_map<int, double> sd;   //数值各列方差
vector<string> in;               //要进行分类的数据
int m, n;                        // m行数据  n列属性
int sedata, row;                 //选择的测试集编号，测试属性编号

//判断列属性是不是数值属性
bool isNum(string str) {
    stringstream sin(str);
    double d;
    char c;
    if (!(sin >> d))
        return false;
    if (sin >> c)
        return false;
    return true;
}
bool readData() {
    unordered_map<int, double> sum; //数值属性列的总和
    ifstream in("NaiveBayesian.in");
    if (!in.is_open()) {
        cout << "Open file error!" << endl;
        return false;
    } else {
        int i = 0;
        while (!in.eof()) { //读取每一行的数据并插入
            if (i != 0)
                data.push_back(vector<string>());
            string line, t;
            getline(in, line);
            stringstream ss;
            ss << line;
            int j = 0;
            while (ss >> t) {
                if (i == 0)
                    attributes.push_back(t);
                else {
                    data[i - 1].push_back(t);
                    //如果是数值属性 计算总和 此处并不能判断数值属性是否连续
                    if (isNum(t)) {
                        double temp = stod(t);
                        sum[j] += temp;
                    }
                    j++;
                }
            }
            ss.clear();
            i++;
        }
    }
    in.close();
    n = attributes.size(); //数据有n行 m列
    m = data.size();
    //计算连续数值属性的均值
    for (auto m : sum) {
        mean[m.first] = m.second / n;
        continu.push_back(m.first);
    }
    for (auto i : continu) {
        double t = 1.0;
        for (int j = 0; j < m; j++) {
            t *= (stod(data[j][i]) - mean[i]) * (stod(data[j][i]) - mean[i]);
        }
        sd[i] = sqrt(t / m); //第i列属性的标准差
    }
    return true;
}

//求连续属性的高斯分布 参数为 属性数值   均值    标准差
double gaussian(double x, double mean, double sd) {
    return exp(-(x - mean) * (x - mean) / (2 * sd * sd)) / (sqrt(2 * PI) * sd);
}

//获取每个分类标签 以第t列的属性为分类结果
void getLable(int t) {
    lable.clear();
    for (int i = 0; i < m; i++) {
        if (count(lable.begin(), lable.end(), data[i][t]) == 0)
            lable.push_back(data[i][t]);
    }
}

//数值属性求某标签下的概率  第j列
double numericAttribute(vector<int> &select, int j) {
    double sum = 0.0, tmean = 0.0, tsd = 0.0;
    for (auto s : select) {
        sum += stod(data[s][j]);
    }
    tmean = sum / select.size();
    for (auto i : select) {
        tsd += (stod(data[i][j]) - tmean) * (stod(data[i][j]) - tmean);
    }
    tsd = sqrt(tsd / select.size());
    // cout << stod(in[j]) << " 均值= " << tmean << " 标准差=" << tsd<< " sum =
    // " << sum << endl;
    double ans = gaussian(stod(in[j]), tmean, tsd);
    return ans;
}

//标称属性求某标签下的概率 第j列
double nominalAttribute(vector<int> &select, int j) {
    int cid = 0;
    for (auto s : select) {
        // cout << "select = " << s << "j = "<<j << endl;
        if (in[j] == data[s][j])
            cid++;
    }
    // cout << attributes[j] << "p = " << 1.0 * cid / select.size() << endl;
    return 1.0 * cid / select.size();
}

//取第t列的属性值作为分类目标 进行分类
bool bayes(int t) {
    getLable(t);
    vector<double> ans; // X在各类lable下的概率
    for (int i = 0; i < lable.size(); i++) {
        string lb = lable[i]; //选定当前的标签
        cout << "lable = " << lb << endl;
        double tans = 1.0;  //当前选定标签下的概率
        vector<int> select; //选择筛选过的元组的下标
        for (int j = 0; j < m; j++) {
            if (lb == data[j][t])
                select.push_back(j);
        }
        for (int j = 0; j < n; j++) {
            if (j == t) //要预测的属性序列 不参与
                continue;
            //连续数值属性求概率
            if (count(continu.begin(), continu.end(), j) != 0) {
                tans *= numericAttribute(select, j);
            } else { //标称属性求概率
                tans *= nominalAttribute(select, j);
            }
        }
        ans.push_back(tans);
    }
    for (int i = 0; i < lable.size(); i++) {
        cout << lable[i] << "的P(X|C)=" << ans[i] << endl;
    }
    int maxi; //概率最大的lable的下标
    double maxp = -1;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] > maxp)
            maxp = ans[i], maxi = i;
    }
    cout << "对" << attributes[t] << "属性的分类结果为:" << lable[maxi]
         << ". 真实结果为:" << in[t];
    if (lable[maxi] == in[t]) {
        cout << "  预测正确" << endl;
        return true;
    } else {
        cout << "  预测错误" << endl;
        return false;
    }
}

//打印文件信息
void print() {
    for (auto at : attributes) 
        cout << " " << at;
    cout << endl;
    for (int i = 0; i < m; i++) {
        cout << i << " ";
        for (auto t : data[i])
            cout << t << " ";
        cout << endl;
    }
}

//手动输入
void handle() {
    cout << "选择进行分类的数据行编号:";
    cin >> sedata;
    //检测数据从data中转移到in
    data[m - 1].swap(data[sedata]);
    in.swap(data[m - 1]);
    data.pop_back();
    m = data.size();
    //读取要分类的属性编号
    for (int i = 0; i < n; i++) {
        if (count(continu.begin(), continu.end(), i) == 0)
            cout << i << attributes[i] << " ";
    }
    cout << endl;
    cout << "选择进行分类的属性编号:";
    cin >> row;
    bayes(row);
}

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    if (readData() == false) {
        cout << "读取文件失败！" << endl;
        return 0;
    } else
        cout << "读取文件完成！" << endl;
    backup.assign(data.begin(), data.end()); //备份数据
    cout << backup.size() << endl;
    print();
    handle();
    getchar();
    return 0;
}