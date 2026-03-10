#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

string convertToBaseR(long long n, int r) {
    if (n == 0) return "0";
    
    bool isNegative = false;
    if (n < 0) {
        isNegative = true;
        n = -n; 
    }

    string res = "";

    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (n > 0) {
        res += digits[n % r]; 
        n /= r;            
    }

    if (isNegative) {
        res += '-';
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    long long n;
    int r;
    
    while (cin >> n >> r) {
        cout << convertToBaseR(n, r) << endl;
    }
    
    return 0;
}