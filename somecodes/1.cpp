#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

/*
*/
int main(int argc, char const *argv[]) {
    std::ifstream fin("2.txt", std::ios::in);
    char line[1024] = {0};
    int i = 2;
    while (fin.getline(line, sizeof(line))) {
        stringstream word(line);
        if(i==2){
            //cout <<"pm disable-user "<< line <<endl;
            cout <<"pm uninstall -k --user 0 "<< line <<endl;
            //cout <<"pm disable-user "<< line <<endl;
            //cout <<"pm enable-user "<< line <<endl;
            i = 0;
        }else{
            i++; 
        }

    }
    fin.clear();
    fin.close();
    getchar();
    return 0;
}

