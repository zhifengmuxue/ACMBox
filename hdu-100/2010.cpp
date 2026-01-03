#include<iostream>
using namespace std;

int m,n;

bool is_sxh(int n){
    int a = n / 100;
    int b = n / 10 % 10;
    int c = n % 10;
    return (a*a*a + b*b*b + c*c*c == n);
}

int main(){
    while ( cin >> m >> n) {
        bool has = 0;
        for (int i = m; i<=n;i++){
            if (is_sxh(i)) {
                has = 1;
                cout << i << " ";
            }
        }
        if (!has) cout << "no" << endl;
        else cout << endl;
    }
    return 0;
}