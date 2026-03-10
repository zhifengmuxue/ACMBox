#include<iostream>
#define int long long 
using namespace std;

signed main(){
    int a,b;
    while(cin >> a >> b) {
        if (!a && !b) break;
        int res = 1;
        int mod = 1000;
        while(b>0){
            if (b&1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        cout << res << endl;
    }


    return 0;
}