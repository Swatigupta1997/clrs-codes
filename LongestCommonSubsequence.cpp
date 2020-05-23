class Solution {
public:
    int lcs(string text1, int i1, int j1,  string text2, int i2, int j2){
        if(i1>j1 || i2>j2){return 0;}
        int val = max( lcs(text1, i1, j1, text2, i2+1, j2), lcs(text1, i1+1, j1, text2, i2, j2) );
        if(text1[i1]==text2[i2]){
            return ( max( 1+lcs(text1,i1+1, j1, text2, i2+1, j2 ), val ) );
        }else{
            return( val );
        }
    }
    int dp(string text1, int l1, string text2, int l2){
        int a1[l1+1][l2+1];
        
        a1[l1][l2]=0;
        for(int i=0; i<=l1; i++){
            a1[i][l2]=0;
        }
        for(int i=0; i<=l2; i++){
            a1[l1][i]=0;
        }
        for(int i=l1-1; i>=0; i--){
            for(int j=l2-1; j>=0; j--){
                if(text1[i]==text2[j]){a1[i][j]=1+a1[i+1][j+1];}
                else{a1[i][j]=max(a1[i][j+1], a1[i+1][j]);}
            }
        }
        return a1[0][0];
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length();
        int l2 = text2.length();
        //return lcs(text1, 0, l1-1, text2, 0, l2-1);
        return dp(text1, l1, text2, l2);
    }
};
