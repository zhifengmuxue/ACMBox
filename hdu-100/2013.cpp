#include<iostream>
using namespace std;
int n;
int main(){
    while (cin>>n){
        int res = 1;
        while(--n){
            res = 2 * (res + 1);
        }
        cout << res << endl;
    }
    return 0;
}