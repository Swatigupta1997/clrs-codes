/*
Kth permutation:
Given n and k, return the kth permutation sequence.
*/

class Solution {
    string s;
public:
    void gp(vector<int>&v, int n, int k, int tot){ 
        if(n==0){return;}
        int fact=tot/n;
        int ind = k/fact;// k/(n-1)!
        k = k%fact;
        
        //cout<<ind<<" "<<v[ind]<<endl;
        s=s+to_string(v[ind]);
        //printvec(v);
        v.erase(v.begin()+ind);
        //cout<<n-1<<" "<<k<<" "<<fact<<endl;
        gp(v, n-1, k, fact);

    }
    string getPermutation(int n, int k) {
        s="";
        vector<int>v(n);
        int tot = 1;
        for(int i=0; i<n; i++){
            v[i]=i+1;
            tot=tot*(i+1);
        }
        //cout<<n<<" "<<k-1<<" "<<tot<<endl;
        gp(v, n, k-1, tot);
        return s;
    }
};
