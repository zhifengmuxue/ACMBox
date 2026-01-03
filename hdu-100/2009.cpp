#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int n,m;
int main(){
    while(cin >> n >> m){
        double temp = n;
        double result = n;
        while(--m){
            temp= sqrt(temp);
            result += temp;
        }
        cout << fixed << setprecision(2) << result<<endl;
    }
    return 0;
}