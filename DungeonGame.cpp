/* 
Leetcode Problem. Detailed Explanation: 
https://www.geeksforgeeks.org/minimum-positive-points-to-reach-destination/
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> mat = dungeon;
        int n = dungeon.size();
        int m=0;
        if(n>0){
            m = dungeon[0].size();
        }
        mat[n-1][m-1]= mat[n-1][m-1]>0? 1:1-mat[n-1][m-1];
        for(int i=n-2; i>=0; i--){
            mat[i][m-1]= max(mat[i+1][m-1]-mat[i][m-1],1);
            //cout<<mat[i][0]<<endl;
        }
        for(int j=m-2; j>=0; j--){
            mat[n-1][j] = max(mat[n-1][j+1]-mat[n-1][j], 1);
            //cout<<mat[0][j]<<endl;
        }
        for(int i=n-2; i>=0; i--){
            for(int j=m-2; j>=0; j--){
                mat[i][j]=max(min(mat[i+1][j], mat[i][j+1]) - mat[i][j], 1);
                //cout<<i<<j<<" "<<mat[i][j]<<endl;
            }
        }
        return mat[0][0];
    }
};
