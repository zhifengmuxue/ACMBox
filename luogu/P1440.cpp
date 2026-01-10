#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;

int a[2000005];

signed main(){
 IOS;
int n, m;
cin >> n >> m;
for (int i = 1; i <= n; i++)
{
    cin >> a[i];
}
deque<int> dq;
for(int i=1;i<=n;i++){
    if (i==1)
    {
        cout<<0<<endl;
        dq.push_back(i);
        continue;
    }
    // 此时我们要输出第 i 行的答案（i 之前的最小值）
    // 如果下标 < i-m 则过期
    while (!dq.empty()&&dq.front()<i-m)dq.pop_front();
    //直接输出最小值，不需要先把当前的入队，因为是要输出下标 i 之前的最小值
    cout << a[dq.front()] << endl;

     // 将当前元素加入队列，为后面做准备
    while (!dq.empty()&&a[dq.back()]>=a[i])dq.pop_back();
    dq.push_back(i);
    
}

 return 0;
}