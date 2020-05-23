class Solution {
public:
    int kadane(vector<int>& A, int n){
        if(n==0){return 0;}
        int max_sum=A[0];
        int max_prev=0;
        for(int i=0; i<n; i++){
            if(A[i]>max_prev+A[i]){
                max_sum = max(max_sum, A[i]);
                max_prev=A[i];
            }else{
                max_sum=max(max_sum, max_prev+A[i]);
                max_prev=max_prev+A[i];
            }
        }
        return max_sum;
    }
    int maxSubarraySumCircular(vector<int>& A) {
        int max_sum=kadane(A, A.size());
        //cout<<max_sum<<endl;
        int tsum=0;
        vector<int>A1;
        for(int i=0; i<A.size(); i++){
            tsum=tsum+A[i];
            A1.push_back(-1*A[i]);
        }
        int max_rev=kadane(A1, A1.size());
        //cout<<max_rev<<" "<<tsum+max_rev<<endl;
        if(tsum+max_rev==0){
            return max_sum;
        }
        return max(max_sum, tsum+max_rev);
    }
};
