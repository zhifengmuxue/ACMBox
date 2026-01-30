#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<cstring>
#include<unordered_map>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;


//哈希计数法 - 时间复杂度O(n),空间复杂度O(n)
signed main(){
 IOS; 

int n;  // 数的个数
ll c;   // 目标差值
cin>>n>>c;  

unordered_map<ll,ll> mp;  // 哈希表,键为数值,值为该数值出现的次数

// 遍历n个数,统计每个数字出现的次数
for(int i=0;i<n;i++){
    ll x;
    cin>>x;       // 读入当前数字
    mp[x]++;      // 在哈希表中对应位置计数+1
}

ll ans=0;  

// 遍历哈希表中的每个键值对
for(auto &p:mp){
   ll x=p.first;      // 当前数字的值
   ll num=p.second;   // 当前数字出现的次数
   
   // 查找是否存在x-c这个数字(即查找是否存在y,使得x-y=c)
   if(mp.count(x-c)){
    ans+=num*mp[x-c];  // 如果存在,则配对数为两个数字出现次数的乘积
   }
}

cout<<ans<<endl;  // 输出结果
 return 0;
}


//尺取法(双指针) - 时间复杂度O(nlogn),空间复杂度O(n)
signed main1(){
 IOS;  
 
    int n;    // 数的个数
    ll c;     // 目标差值
    cin>>n>>c;
    
    vector<ll> a(n);  
    // 读入n个数字
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    sort(a.begin(),a.end());  
    
    ll ans=0;      
    int l=0,r=0;   // 左右指针,初始都指向起点
    
    // 双指针遍历
    while (l<n &&r<n)
    {
        // 如果左右指针指向同一位置,右指针向右移动
        if(l==r){
            r++;
            continue;
        }
        
        ll diff=a[r]-a[l];  // 计算当前两个位置数字的差值
        
        // 如果差值小于c,说明r需要继续向右找更大的数
        if(diff<c){
            r++;
        }
        // 如果差值大于c,说明l需要向右移动找更大的数(缩小差距)
        else if(diff>c){
            l++;
        }
        // 如果差值等于c,找到一组符合条件的配对
        else {
            ll cntl=1,cntr=1;  // 统计l和r位置相同数字的个数
            
            // 统计从l开始有多少个连续相同的数字
            while(l+cntl<n&&a[l+cntl]==a[l])cntl++;
            
            // 统计从r开始有多少个连续相同的数字
            while(r+cntr<n&&a[r+cntr]==a[r])cntr++;
            
            ans+=cntl*cntr;  // 配对数为两组数字个数的乘积
            
            l+=cntl;  // 左指针跳过所有相同的数字
            r+=cntr;  // 右指针跳过所有相同的数字
        }
    }
    
cout<<ans<<endl;  // 输出结果

return 0;
}

