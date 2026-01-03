#include<iostream>
#include<iomanip>
using namespace std;
int n;
int a;
int main(){
    cin >> n;
    while (n--){
        cin >> a;
        double result = 0.0;
        for (int i=1;i<=a;i++){
            if (i % 2 == 1) result += 1.0 / i;   
            else result -= 1.0 / i;             
        }
        cout << fixed << setprecision(2) << result<<endl;
    }
    return 0;
}