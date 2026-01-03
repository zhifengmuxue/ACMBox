#include<iostream>
using namespace std;

int n;
double num;
int main(){
    while(cin >> n){
        int a =0, b =0 , c = 0;
        if(n == 0) break;
        while(n--){
            cin >> num ;
            if (num < 0) a++;
            else if (num > 0) c ++ ;
            else  b ++ ;
        }
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}