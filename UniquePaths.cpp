/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
(m+n-2)Comb(m-1)

(a+b)C(a) = (a+b-1)C(a) + (a+b-1)C(a-1)
*/

class Solution {
public:
    int comb(int m, int n){
        int dp[m][n];
        for(int i=0; i<m; i++){
            dp[i][0]=1;
        }
        for(int i=0; i<n; i++){
            dp[0][i]=1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
                //cout<<dp[i][j]<<endl;
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        if(m+n<=2){return 1;}
        //cout<<m<<" "<<n<<endl;
        return comb(m, n);
    }
};
