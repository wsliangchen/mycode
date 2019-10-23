#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int heap[10010], n;

void up(int p){
    while(p > 1){
        if(heap[p] > heap[p/2]){
            swap(heap[p], heap[p/2]);
            p /=2;
        }else break;
    }
}

void down(int p){
    int s = p*2;
    while(s <= n){
        //取左右子节点中较大者
        if(s < n && heap[s] < heap[s+1]) s++;
        if(heap[s] > heap[p]){
            swap(heap[s], heap[p]);
            p = s;
            s = p*2;
        }else break;
    }
}

void insert(int v){
    heap[++n] = v;
    up(n);
}

void extract(){
    heap[1] = heap[n--];
    down(1);
}

void remove(int k){
    heap[k] = heap[n--];
    up(k),down(k);
}

int main(int argc, char const *argv[]){
    for(int i = 0; i < 10; i++){
        insert(i);
        printf("%d \n", heap[1]);
    }
    for(int i = 1; i <= 10; i++){
        printf("%d ", heap[i]);
    }
    
    return 0;
}