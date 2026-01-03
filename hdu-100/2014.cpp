#include<iostream>
#include<iomanip>
#include <cstdint>
using namespace std;

int n;
int temp;
int main(){
    while(cin>>n){
        int all = 0;
        int min = INT32_MAX;
        int max = 0;
        for(int i=0;i<n;i++){
            cin >> temp;
            if (temp < min) min = temp;
            if (temp > max) max = temp;
            all += temp;
        }
        all -= min+max;
        cout << fixed << setprecision(2) << 1.0 * all / (n-2) << endl;
    }
    return 0;
}