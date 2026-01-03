#include<iostream>
using namespace std;

int x,y;

bool is_prime(int n){
    if (n<=1) return false;
    for (int i=2; i*i<=n ; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    while(cin>>x>>y){
        bool flag = 1;
        if (!x && !y) break;
        for (int i=x;i<=y;i++) 
            if (!is_prime(i*i + i + 41)) flag = 0;
        if(flag) cout << "OK" << endl;
        else cout << "Sorry" << endl;
    }
    return 0;
}