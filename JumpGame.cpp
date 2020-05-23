class Solution {
public:
    void dfs(vector<int> graph[], int l, int ind, int vis[]){
        if(vis[ind]==1 || vis[l-1]==1){return;}
        vis[ind]=1;
        for(auto i = graph[ind].begin(); i!= graph[ind].end(); i++){
            dfs(graph, l, *i, vis); 
        }
    }
    bool canJump(vector<int>& nums) {
        int l = nums.size();
        if(l==1){return true;}
        // vector<int> graph[l];
        // int vis[l], flag=0;
        // for(int i=0; i<l; i++){
        //     //cout<<i<<" "<<nums[i]<<endl;
        //     vis[i]=0;
        //     for(int j=i+nums[i]; j>=i+1; j--){
        //         if(j<l){
        //             //cout<<j<<endl;
        //             if(j==l-1){flag=1;}
        //             graph[i].push_back(j);
        //         }
        //     }
        // }
        // if(flag==0){return false;}
        // dfs(graph, l, 0, vis);
        // return vis[l-1];
        int lp=l-1;
        for(int i=l-1; i>=0; i--){
            if(i+nums[i]>=lp){
                lp=i;
            }
        }
        if(lp==0){return true;}
        return false;
        
    }
};
