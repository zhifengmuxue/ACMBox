#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<stack>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;


int a[100005];
int ans[100005];
stack<int> s;//存储下标
//栈内元素单调递增或递减
signed main(){
 IOS;
int n;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}

//单调栈模板题目，从后往前遍历
for(int i=n;i>=1;i--){
    //栈顶元素小于等于当前元素，弹出栈顶元素
    while(!s.empty()&&a[s.top()] <= a[i]){
        s.pop();
    }
    //栈为空，说明没有比当前元素大的，答案为0
    if(s.empty())ans[i]=0;
    //栈不为空，栈顶元素即为下一个比当前元素大的元素
    //栈顶永远是比当前元素大的元素中下标最小的那个
    else ans[i]=s.top();
    s.push(i);
}

for (int i = 1; i <= n; i++)cout << ans[i] << endl;
 return 0;
}