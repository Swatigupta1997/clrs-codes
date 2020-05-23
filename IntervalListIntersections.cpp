class Solution {
public:
    void fun(vector<vector<int>>& A, vector<vector<int>>& B, int i, int j, vector<vector<int>>& v){
        if(i>=A.size() || j>=B.size()){
            return;
        }
        //cout<<i<<j<<endl;
        int ax=A[i][0];
        int ay=A[i][1];
        int bx=B[j][0];
        int by=B[j][1];
        //cout<<ax<<" "<<ay<<" h "<<bx<<by<<endl;
        if(ay<bx){
            return fun(A,B,i+1,j, v);
        }else if(by<ax){
            return fun(A,B,i,j+1, v);
        }
        else{
            vector<int>tmp;
            tmp.push_back(max(ax,bx));
            tmp.push_back(min(ay,by));
            //cout<<max(ax,bx)<<" "<<min(ay,by)<<endl;
            v.push_back(tmp);
            if(ay>by){
                fun(A,B,i,j+1, v);
            }else{
                fun(A,B,i+1,j, v);
            }
        }
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>>v;
        fun(A, B, 0,0, v);
        //cout<<"here"<<endl;
        return v;
        
    }
};
