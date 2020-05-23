class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n=0;
        if(m){
            n = matrix[0].size();
        }
        int sum=0;
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j]==0){continue;}
                int val = min(min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1]);
                matrix[i][j]=1+val;
                //cout<<matrix[i][j]<<endl;
                sum=sum+matrix[i][j];
            }
        }
        //cout<<sum<<endl;
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         sum=sum+matrix[i][j];
        //     }
        // }
        for(int i=0; i<m; i++){
            //cout<<matrix[i][0]<<endl;
            sum=sum+matrix[i][0];
        }
        for(int j=0; j<n; j++){
            //cout<<matrix[0][j]<<endl;
            sum=sum+matrix[0][j];
        }
        return sum-matrix[0][0];
    }
};
