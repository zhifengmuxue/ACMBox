#include<iostream>
using namespace std;

int T;
int main(){
    cin >> T;
    cin.ignore(); 
    while(T--){
        string s;
        int cnt=0;
        getline(cin, s); 
        for (int i=0; i<s.length(); i++){
            if (s[i] < 0) {
                cnt++;
                i++;
            } 
        }
        cout << cnt << endl;
    }
    return 0;
}