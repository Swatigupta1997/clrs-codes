class Solution {
public:
    int is_full(vector<vector<char>>& matrix, int i, int j, int y){
        //cout<<"I"<<i<<j<<y<<endl;
        for(int k=i; k<=i+y; k++){
            for(int l=j; l<=j+y; l++){
                //cout<<"m"<<matrix[k][l]<<endl;
                if(matrix[k][l]=='0'){
                    //cout<<"here"<<endl;
                    return 0;
                }
            }
        }
        return 1;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int lr = matrix.size();
        if(lr==0){return 0;}
        int lc = matrix[0].size();
        int maxsize=0, flag=0;
        for(int i=0; i<lr; i++){
            for(int j=0; j<lc; j++){
                if(matrix[i][j]=='0'){
                    continue;
                }else{
                    flag=1;
                    int y=1;
                    while(i+y<lr && j+y<lc){
                        //cout<<y<<endl;
                        if (is_full(matrix, i, j, y)){
                            //cout<<i<<j<<y<<endl;
                            maxsize = max(maxsize, y);
                        }else {break;} 
                        y++;
                    }
                }
            }
        }
        if(flag==1){
            return (maxsize+1)*(maxsize+1);
        }
        return 0;
    }
};
