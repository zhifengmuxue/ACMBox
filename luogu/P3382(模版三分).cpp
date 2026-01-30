#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<cstring>
#include <iomanip>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;

const double eps = 1e-6;
int n;
double a[15];

double f(double x){                     //计算函数值，高效计算多项式的值。
    double s=0;
    for(int i=n;i>=0;i--) s=s*x + a[i]; //注意函数求值的写法
    return s;
}
//a[i] 就是系数数组，n 是最高次幂。f(x)=(((an​x+an−1​)x+an−2​)x+⋯+a0​)不断乘 x、加系数

signed main(){
 IOS;
    double L,R;
    cin>>n>>L>>R;
    for(int i=n;i>=0;i--) cin>>a[i];
    while(R-L>eps){//for(int i=0;i<100;i++){也可以
        double mid=(R-L)/3.0;
        double mid1=L+mid;
        double mid2=R-mid;
        if(f(mid1)>f(mid2)) R=mid2;//在mid2左侧
        else L=mid1;//在mid1右侧
    }
cout<<fixed<<setprecision(5)<<L<<endl;
// fixed + setprecision(5)	小数点后 5 位
 return 0;
}

//近似二分法求函数极值
signed main(){
    IOS;
        double L,R;
        cin>>n>>L>>R;
        for(int i=n;i>=0;i--) cin>>a[i];

        while(R-L>eps){//for(int i=0;i<100;i++){也可以
           double mid=L+(R-L)/2;
           if((mid-eps)>f(mid))R=mid;
           else L=mid;

        }
        cout<<fixed<<setprecision(5)<<L<<endl;
        return 0;
}