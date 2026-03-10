#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int D[1005][1005];

int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int i=x1;i<=x2;i++){
            D[i][y1]++;D[i][y2+1]--;
        }
    }

    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            a[i][j]=a[i][j-1]+D[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}