#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int choose(int n, int r){
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<=n; i++){
        dp[i][0]=1;
        dp[i][i]=1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        }
    }
    return dp[n][r];
}

int main(){
    int n; int r;
    cin>>n>>r;
    cout<<choose(n, r)<<endl;

    return 0;
}
