#include <cstdio> //c语言的所有头文件 cpp都可以兼容  stdio.h -> cstdio
#include <deque> //双端队列 支持头插和尾插 queue仅支持头出尾插
#include <iostream>
#include <map> //map 映射自带排序
#include <queue> //queue包括 普通数组实现的queue  还有堆实现的priority_queue
#include <set>    //set 集合 包括普通set和multi_set multi_set是可重集
#include <stack>  //栈 后进先出
#include <string> //字符串类型，类似于c语言中的char数组
#include <unordered_map> //无序映射  基于hash
#include <unordered_set> //无序集合  基于hash
#include <vector>        //加强版数组
#include <algorithm>  //算法库
#include <sstream>  //string流库
/**
 * cpp 容器操作时间复杂度
 * map,set,multi_map,multi_set 插入，删除，查找 log(n)
 * unordered_map,unordered_set 一般情况 O(1)
 */

using namespace std;
// c++ 泛型<>尖括号定义存储类型 vector<你想存放的类型,也可以是结构体和class> v;

struct myst {
    int data;
};

void test() {
    vector<int> v1;     //定义
    vector<int> v2(10); //指明大小定义
    vector<int> v3(3, 666);
    //大小
    printf("v1 size = %d  v2 size = %d v3.size = %d\n", v1.size(), v2.size(),
           v3.size());
    //访问
    printf("%d\n", v3[2]);
    //遍历
    vector<int>::iterator it = v3.begin(); //迭代器 rbegin rend反向迭代器
    for (; it != v3.end(); it++) {
    }
    // for(auto it = v3.begin(); it != v3.end(); it++)
    for (auto v : v3) {
    }
    // set和map只能使用迭代器遍历 查找使用s.find() != s.end()
    set<int> set1;
    set1.insert(1);
    set1.insert(2);
    set<int> set2;
    set2.insert(2);
    set2.insert(3);
    for (auto st : set1) {
        cout << st << endl;
    }
    set<int> set3;

}

int main() {
    //关闭 c++的io和c语言的io 同步 提高c++iostream速度 c语言io就不要用了
    //std::ios::sync_with_stdio(false);
    // cout << true << endl; //c++ 中bool变量其实就是 typedef int bool; true =
    // 1, false = 0;

    test();
    vector<vector<int> > i;
    i.push_back(vector<int> it());
    return 0;
}