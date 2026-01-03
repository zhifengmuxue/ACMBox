#include<iostream>
#include<iomanip>

using namespace std;
double n;
int main(){
    while(cin>>n){
        cout << fixed << setprecision(2) << abs (n)  << endl;
    }
    return 0;
}