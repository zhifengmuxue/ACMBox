#include<iostream>
#define max_size 1005
using namespace std;

int N;
char M[max_size][max_size];
int visit[max_size][max_size];
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int flag;
int ans;


void solve(int x,int y){
    visit[x][y]=1;
    if(M[x+1][y]=='#'&&M[x][y+1]=='#' && M[x-1][y]=='#' && M[x][y-1]=='#'){
        flag=1;
    }
    for (int i = 0; i < 4; i++)
    {
        int x1=x+dir[i][0];int y1=y+dir[i][1];
        if(visit[x1][y1]==0 && M[x1][y1]=='#')
        solve(x1,y1);
    }
}

int main(){
    cin >> N;
    for (int i=1;i<=N;i++)
        for (int j=1;j<=N;j++)
            cin >> M[i][j];
for(int i=2;i<=N;i++)
    for (int j = 2; j <= N; j++)
    {
        if(visit[i][j]==0&&M[i][j]=='#'){
            flag=0;
            solve(i,j);
            if(flag==0)ans++;
        }
    }
    cout << ans;


    return 0;
}