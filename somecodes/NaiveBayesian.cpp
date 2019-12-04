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

vector<string> attributes;     //���������
vector<vector<string>> data;   //���ݼ�
vector<vector<string>> backup; //���ݼ�����
vector<string> lable;          //��ŷ����ǩ
// vector<double> result;           //����ǩ�µĸ��� P = (Xi|Ci)
vector<int> continu;             //��������ֵ�����±���
unordered_map<int, double> mean; //��ֵ���о�ֵ
unordered_map<int, double> sd;   //��ֵ���з���
vector<string> in;               //Ҫ���з��������
int m, n;                        // m������  n������
int sedata, row;                 //ѡ��Ĳ��Լ���ţ��������Ա��

//�ж��������ǲ�����ֵ����
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
    unordered_map<int, double> sum; //��ֵ�����е��ܺ�
    ifstream in("NaiveBayesian.in");
    if (!in.is_open()) {
        cout << "Open file error!" << endl;
        return false;
    } else {
        int i = 0;
        while (!in.eof()) { //��ȡÿһ�е����ݲ�����
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
                    //�������ֵ���� �����ܺ� �˴��������ж���ֵ�����Ƿ�����
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
    n = attributes.size(); //������n�� m��
    m = data.size();
    //����������ֵ���Եľ�ֵ
    for (auto m : sum) {
        mean[m.first] = m.second / n;
        continu.push_back(m.first);
    }
    for (auto i : continu) {
        double t = 1.0;
        for (int j = 0; j < m; j++) {
            t *= (stod(data[j][i]) - mean[i]) * (stod(data[j][i]) - mean[i]);
        }
        sd[i] = sqrt(t / m); //��i�����Եı�׼��
    }
    return true;
}

//���������Եĸ�˹�ֲ� ����Ϊ ������ֵ   ��ֵ    ��׼��
double gaussian(double x, double mean, double sd) {
    return exp(-(x - mean) * (x - mean) / (2 * sd * sd)) / (sqrt(2 * PI) * sd);
}

//��ȡÿ�������ǩ �Ե�t�е�����Ϊ������
void getLable(int t) {
    lable.clear();
    for (int i = 0; i < m; i++) {
        if (count(lable.begin(), lable.end(), data[i][t]) == 0)
            lable.push_back(data[i][t]);
    }
}

//��ֵ������ĳ��ǩ�µĸ���  ��j��
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
    // cout << stod(in[j]) << " ��ֵ= " << tmean << " ��׼��=" << tsd<< " sum =
    // " << sum << endl;
    double ans = gaussian(stod(in[j]), tmean, tsd);
    return ans;
}

//���������ĳ��ǩ�µĸ��� ��j��
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

//ȡ��t�е�����ֵ��Ϊ����Ŀ�� ���з���
bool bayes(int t) {
    getLable(t);
    vector<double> ans; // X�ڸ���lable�µĸ���
    for (int i = 0; i < lable.size(); i++) {
        string lb = lable[i]; //ѡ����ǰ�ı�ǩ
        cout << "lable = " << lb << endl;
        double tans = 1.0;  //��ǰѡ����ǩ�µĸ���
        vector<int> select; //ѡ��ɸѡ����Ԫ����±�
        for (int j = 0; j < m; j++) {
            if (lb == data[j][t])
                select.push_back(j);
        }
        for (int j = 0; j < n; j++) {
            if (j == t) //ҪԤ����������� ������
                continue;
            //������ֵ���������
            if (count(continu.begin(), continu.end(), j) != 0) {
                tans *= numericAttribute(select, j);
            } else { //������������
                tans *= nominalAttribute(select, j);
            }
        }
        ans.push_back(tans);
    }
    for (int i = 0; i < lable.size(); i++) {
        cout << lable[i] << "��P(X|C)=" << ans[i] << endl;
    }
    int maxi; //��������lable���±�
    double maxp = -1;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] > maxp)
            maxp = ans[i], maxi = i;
    }
    cout << "��" << attributes[t] << "���Եķ�����Ϊ:" << lable[maxi]
         << ". ��ʵ���Ϊ:" << in[t];
    if (lable[maxi] == in[t]) {
        cout << "  Ԥ����ȷ" << endl;
        return true;
    } else {
        cout << "  Ԥ�����" << endl;
        return false;
    }
}

//��ӡ�ļ���Ϣ
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

//�ֶ�����
void handle() {
    cout << "ѡ����з���������б��:";
    cin >> sedata;
    //������ݴ�data��ת�Ƶ�in
    data[m - 1].swap(data[sedata]);
    in.swap(data[m - 1]);
    data.pop_back();
    m = data.size();
    //��ȡҪ��������Ա��
    for (int i = 0; i < n; i++) {
        if (count(continu.begin(), continu.end(), i) == 0)
            cout << i << attributes[i] << " ";
    }
    cout << endl;
    cout << "ѡ����з�������Ա��:";
    cin >> row;
    bayes(row);
}

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    if (readData() == false) {
        cout << "��ȡ�ļ�ʧ�ܣ�" << endl;
        return 0;
    } else
        cout << "��ȡ�ļ���ɣ�" << endl;
    backup.assign(data.begin(), data.end()); //��������
    cout << backup.size() << endl;
    print();
    handle();
    getchar();
    return 0;
}