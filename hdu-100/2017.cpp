#include<iostream>
using namespace std;
string s;
int n;
int main(){
    cin >> n;
    while(n--){
        int cnt=0;
        cin >> s;
        for (int i=0;i<s.length();i++){
            if (s[i] >= '0' && s[i] <= '9') cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}