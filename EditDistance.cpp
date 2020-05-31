#define INF 1000000007
class Solution {
public:
    int rec(string word1, string word2, int n1, int n2, int i, int j){
        if(i==n1 && j==n2){
            return 0;
        }
        if((i==n1 && j!=n2) ){
            return n2-j;
        }
        if((i!=n1 && j==n2) ){
            return n1-i;
        }
        int s=INF;
        if(word1[i]==word2[j]){
            s = min(s, rec(word1, word2, n1, n2, i+1, j+1));
        }else{
            s = min(s, rec(word1, word2, n1, n2, i+1, j+1)+1);
        }
        int v = min(rec(word1, word2, n1, n2, i+1, j), rec(word1, word2, n1, n2, i, j+1))+1;
        s=min(s, v);
        return s;
    }
    
    int dp(string word1, string word2, int n1, int n2){
        int arr[n1+1][n2+1];
        arr[n1][n2]=0;
        for(int i=0; i<n1; i++){
            arr[i][n2]=n1-i;
        }
        for(int j=0; j<n2; j++){
            arr[n1][j]=n2-j;
        }
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                if(word1[i]==word2[j]){
                    arr[i][j]=arr[i+1][j+1];
                }else{
                    arr[i][j]=arr[i+1][j+1]+1;
                }
                arr[i][j]=min(arr[i][j], min(arr[i+1][j], arr[i][j+1])+1);
            }
        }
        return arr[0][0];
    }
    
    int minDistance(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        //return rec(word1, word2, n1, n2, 0, 0);
        return dp(word1, word2, n1, n2);
        
    }
};
