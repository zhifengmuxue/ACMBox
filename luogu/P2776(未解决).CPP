#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <deque>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;

int a[100005]; // a[i]表示元素i所属的小组

signed main(){
    IOS;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int T;
    cin >> T;
    
    deque<int> dq; // 主队列,存储元素
    map<int, int> last_idx; // 每个小组最后一个元素在队列中的索引位置
    
    while (T--) {
        string op;
        int x;
        cin >> op >> x;
        
        if (op == "push") {
            int group = a[x]; // x所属的小组
            
       
        }
    return 0;
}