#include<iostream>
#include<iomanip>
#define PI 3.1415927
using namespace std;

double r;
int main(){

    while(cin>>r){
        cout << fixed << setprecision(3) << PI * r * r * r * 4.0 / 3.0  <<endl;
    }

    return 0;
}