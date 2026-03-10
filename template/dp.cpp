#include<iostream>
#define max_size 1005
using namespace std;

int n,C;
int value[max_size];
int weight[max_size];
int dp[max_size][max_size];


int solve(int n,int C){
    for(int i=0;i<n;i++)
        for(int j=0;j<C;j++)
            if(weight[i] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-weight[i]]+value[i]);
    return dp[n][C];
}


int main(){
    cin >> n >> C;

    for (int i=0;i<n;i++) cin >> value[i] >> weight[i];

    cout << solve(n,C);
    return 0;
}