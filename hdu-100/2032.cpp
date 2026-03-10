#include<iostream>
using namespace std;
int rec[32];
int n;
int main(){
    rec[0]=0;
    rec[1]=1;
    while(cin >> n){
       for (int i=1;i<=n;i++){
            rec[i]=1;

            for (int j=i-1;j>0;j--){
                rec[j] = rec[j] + rec[j-1];
            }

            for (int j=1;j<=i;j++) cout << rec[j] << " ";
            cout << endl;
       } 
    }
    return 0;
}