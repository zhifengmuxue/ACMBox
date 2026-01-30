#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<cstring>
#include<cmath>
#include <iomanip>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;

const int N=100005;
ll A,B,C,ans;//不愉快度,每等待一天就会产生 C 不愉快,课程调配老师（A）,增加老师（B）
int n,m;//学生数和课程数
int t[N];//每个学生希望的公布时间,第 ti天或之前得知所有课程的成绩，就没有不满意
int b[N];//每个课程的公布时间

//最终最晚出成绩时间 p
ll check1(int p){//课程调整代价,max(bi′​)=p
    ll x=0,y=0;
//操作 1（代价 A）
    //1 天从一个课程转移到另一个课程
    // 所以：用 x 去抵消 y
// 操作 2（代价 B）
    // 凭空减少 1 天
for(int i=1;i<=m;i++)
    {
        if(b[i]<p)  x+=p-b[i];//x可以被推迟的天数
        else        y+=b[i]-p;// y必须提前的天数
    }
//如果 A < B：
    // 先用操作 1（更便宜）
    // 用完再用操作 2
    if(A<B)
        return min(x,y)*A+(y-min(x,y))*B;
    else 
        return y*B;
// 如果 A ≥ B：
    // 操作 1 不划算
    // 直接全部用操作 2
}

ll check2(int p){//学生不愉快度
    ll sum=0;
    for(int i=1;i<=n;i++){
        if(t[i]<p)sum+= (p - t[i]) * C;//随 p 单调递增的凸函数
    }
    return sum;
}

signed main(){
 IOS;
    cin>>A>>B>>C;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>t[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    sort(b+1,b+m+1);
    sort(t+1,t+n+1);

    if(C>=1e16)//数学剪枝,c太大了，最优一定是p = min(t_i)，最小时间，不能让学生等
    {
        cout<<check1(t[1])<<endl;
        return 0;
    }
    ans=1e16;

    int l=1,r=N;
    while(r-l>2){
        int mid1=l+(r-l)/3;
        int mid2=r-(r-l)/3;
        ll c1=check1(mid1)+check2(mid1);//凸函数,学生代价，单调递增；课程调整代价，先降后升
        ll c2=check1(mid2)+check2(mid2);
        if(c1<=c2)r=mid2;
        else l=mid1;
    }
    //暴力扫剩下几个点
    for (int i = l; i <= r; i++)
    {
        ll x=check1(i)+check2(i);
        ans=min(ans,x);
    }
    cout<<ans<<endl;

 return 0;
}