#include <iostream>
using namespace std;

const int MAXN = 100005;

int parent[MAXN];
int rankv[MAXN];   // 树的高度（秩）

// 初始化
void init(int n){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        rankv[i] = 0;
    }
}

// 查找根节点（路径压缩）
int find(int x){
    if(parent[x] != x){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// 合并两个集合
void unite(int x, int y){
    int rx = find(x);
    int ry = find(y);

    if(rx == ry) return;

    if(rankv[rx] < rankv[ry]){
        parent[rx] = ry;
    }
    else if(rankv[rx] > rankv[ry]){
        parent[ry] = rx;
    }
    else{
        parent[ry] = rx;
        rankv[rx]++;
    }
}

// 判断是否在同一集合
bool same(int x, int y){
    return find(x) == find(y);
}

int main(){

    int n = 10;
    init(n);

    unite(1,2);
    unite(2,3);
    unite(4,5);

    cout << same(1,3) << endl; // 1
    cout << same(1,5) << endl; // 0

    return 0;
}





int parent[MAXN];

int find(int x){
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x != y) parent[x] = y;
}