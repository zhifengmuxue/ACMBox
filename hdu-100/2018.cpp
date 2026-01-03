#include<iostream>
using namespace std;
/* 1 2 3  4  6  9 13 动态规划 (生兔子·改)*/
int n;
int main(){
    while(cin >> n){
        if (!n) break;

        if (n <= 3) {
            cout << n << endl;
            continue;
        }

        int a=1, b=2, c=3,d;
        for (int i = 4; i<= n; i++){
            d = c + a;
            a = b;
            b = c;
            c = d;
        }
        cout << c << endl;
    }
    return 0;
}