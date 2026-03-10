#include<iostream>
#include<cstring>
using namespace std;

int n,m;
int a[105];
int main(){
    while(cin>>n>>m){
        if (!n && !m) break;
        memset(a,0,sizeof(a));
        for (int i=0;i<n;i++){
            int num;
            cin >> num;
            a[num] = 1;
        }
        for (int i=0;i<m;i++){
            int num;
            cin >> num;
            if (a[num]==1) a[num] = 0;
        }
        bool flag = 0;
        for (int i=0;i<105;i++){
            if (a[i]==1) {
                cout << i << " ";
                flag=1;
            }
        }
        if (!flag) cout << "NULL";
        cout << endl;
    }
    
    return 0;
}