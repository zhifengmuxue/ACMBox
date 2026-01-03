#include<iostream>

using namespace std;

int s;
int main(){
    while (cin>>s){
        if (s > 100 || s < 0) {
            cout << "Score is error!"<< endl;
            continue;
        }
        if (s >= 90)  cout << "A" << endl;
        else if (s >=80) cout << "B" << endl;
        else if (s >= 70) cout << "C" << endl;
        else if (s >= 60) cout << "D" << endl;
        else if (s >= 0) cout << "E"<< endl;
    }
    return 0;
}