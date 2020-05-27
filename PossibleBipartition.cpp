class Solution {
public:

    bool dfs(vector<int>val[], int N, int vis[], int i, int pc){
        if(vis[i]!=0 && vis[i]==pc){
            return false;
        }else if(vis[i]!=0 && vis[i]!=pc){
            return true;
        }
        vis[i]=3-pc;
        //cout<<i+1<<" "<<vis[i]<<endl;
        for(auto it = val[i].begin(); it!=val[i].end(); it++){
            if(vis[*it]==0){
                if (!dfs(val, N, vis, *it, vis[i])){
                    return false;
                }
            }else if(vis[*it]==vis[i]){
                return false;
            }
        }
        return true; 
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int>val[N];
        int vis[N];
        for(int i=0; i<dislikes.size(); i++){
            int x1 = dislikes[i][0]-1;
            int x2 = dislikes[i][1]-1;
            val[x1].push_back(x2);
            val[x2].push_back(x1);
    
        }
        for(int i=0; i<N; i++){
            vis[i]=0;
        }
        for(int i=0; i<N; i++){
            if(vis[i]==0 && !dfs(val, N, vis, i, 2)){
                return false;
            }
            
        }
        return true;
        
    }
};
