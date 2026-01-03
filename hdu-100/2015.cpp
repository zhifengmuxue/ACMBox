#include<iostream>
using namespace std;
int n,m;
int main(){
    while(cin>>n >> m){
        int it = m;
        int mean = 0;
        for (int i=2;i<=2 * n;i+=2){
            it --;
            mean += i;
            if (it == 0){
                cout << mean / m << " ";
                it = m;
                mean = 0;
            }
        }
        if(it != m) cout << mean / (m-it) << " ";
        cout << endl;
    }
    return 0;
}