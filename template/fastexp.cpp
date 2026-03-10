#include<iostream>
#define mod 1000
using namespace std;
int n,m;

int qe(int n,int m){
    int res = 1;
    while(m){
        if (m & 1) res *= n % mod;
        n *= n % mod;
        m >>= 1;
    }
   
    return res;
}



int main(){

    cin >> n >> m;
    cout << qe(n,m) << endl;

    return 0;
}
