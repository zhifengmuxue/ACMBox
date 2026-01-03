#include<iostream>
using namespace std;
char a,b,c;
int main(){
    while(cin>>a >> b >> c){
        if (a > b) swap(a,b);
        if (b > c) swap(b,c);
        if (a > b) swap(a,b);
        cout << a << " " << b << " " << c << '\n';
    }
    return 0;
}