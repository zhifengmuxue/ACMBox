#include<iostream>
using namespace std;

int n;
int a;
int main(){
    while(cin >> n){
        int result = 1;
        while(n--){
            cin >> a;
            if (a % 2 ==1 ) result *= a;
        }
        cout << result << endl;
    }

    return 0;
}