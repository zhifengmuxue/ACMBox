#include<bits/stdc++.h>
#define max_size 100050
using namespace std;
int N,a,b; 
int D[max_size], A[max_size];

int main(){
    while(cin >> N){
        if (!N) break;
        memset(A,0,sizeof(A));
        memset(D,0,sizeof(D));
        for(int i=0;i<N;i++){
            cin >> a >> b;
            D[a] ++;
            D[b+1] --;
        }

        for (int i=1; i<=N;i++){
            A[i] = A[i-1] + D[i];
            cout << A[i] << " ";
        }
        cout << endl;
    }
    

    return 0;
}