#include<iostream>
#include<cstdint>
using namespace std;
int a[105];
int n;
int main(){
    while(cin >> n){
        if (!n) break;
        int min = INT32_MAX;
        int min_i = -1;
        for (int i=0; i<n; i++){
            cin >> a[i];
            if (a[i] < min) {
                min = a[i];
                min_i = i;
            }
        }
        int temp = a[min_i];
        a[min_i] = a[0];
        a[0] = temp;
        for (int i=0;i<n;i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}