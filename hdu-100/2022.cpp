#include<iostream>
using namespace std;

int m,n;
long long x;
int main(){
    while(cin>>m>>n){
        long long max = 0;
        long long max_i = -1;
        long long max_j = -1;
        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++){
                cin >> x;
                if ( abs(x) > abs(max)) {
                    max = x;
                    max_i = i;
                    max_j = j;
                } 
            }
        cout << max_i << " " << max_j << " " << max << endl;

    }

    return 0;
}