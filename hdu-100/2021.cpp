#include<iostream>
using namespace std;

int N;
int m;
int main(){
    while(cin >> N){
        if (!N) break;
        int result = 0;
        while (N--) {
            cin >> m;
            result += m / 100;
            m %= 100;
            result += m / 50;
            m %= 50;
            result += m / 10;
            m %= 10;
            result += m / 5;
            m %= 5;
            result += m / 2;
            m %= 2;
            result += m;
        }
        cout << result << endl;
    }
    return 0;
}