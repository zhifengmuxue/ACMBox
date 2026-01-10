#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;

//求每次移动前输出被覆盖住的数字中最大的数是多少
int a[2000005];
signed main(){
 IOS;
int n,k;
cin>>n>>k;
for (int i = 1; i <= n; i++)
{
    cin >> a[i];
}

deque<int> dq; 
for (int i = 1; i <= n; i++)
{
    while (!dq.empty()&&dq.front()<=i-k)
    {
        dq.pop_front();
    }
    while (!dq.empty()&&a[dq.back()]<=a[i]) dq.pop_back();
    dq.push_back(i);
    if(i>=k){
        cout<<a[dq.front()]<<endl;
    }
    
}


 return 0;
}