class Solution {
public:
    string rec(string num, int k, int i){
        if(i>num.length()){return "";}
        if(k==0){return num.substr(i, num.length()-i);}
        string a = rec(num, k-1, i+1);
        string b = num[i]+rec(num, k, i+1);
        //cout<<a<<" "<<k<<" "<<i<<endl;
        //cout<<b<<" "<<k<<" "<<i<<endl;
        return min(a,b);
    }
    string dp(string num, int k){
        vector<vector<string>>a(k+1, vector<string>(num.length()+1));
        for(int i=0; i<num.length(); i++){
            a[0][i]=num.substr(i, num.length()-i);
        }
        for(int j=0; j<=k; j++){
            a[j][num.length()]="";
        }
        
        for(int i=num.length()-1; i>=0; i--){
            for(int j=1; j<=k; j++){
                a[j][i]= min(a[j-1][i+1], num[i]+a[j][i+1]);
            }
        }
        return a[k][0];
    }
    string f(string num, int k, int ind){
        if(ind>=num.length()){return "";}
        if(k==0){return num.substr(ind, num.length()-ind);}
        char x=num[ind];
        int index=ind;
        string res="";
        for(int i=ind; i<=k; i++){
            if(x>num[i]){
                x=num[i];
                index=i;
            }
        }
        cout<<x<<" "<<ind<<endl;
        res = x+f(num, k-index,index+1);
        return res;
    }
    void buildLowestNumberRec(string str, int n, string &res) 
    { 
        if (n == 0) 
    { 
        res.append(str); 
        return; 
    } 
  
    int len = str.length(); 
  
    // If there are more characters to remove than string 
    // length, then append nothing to result 
    if (len <= n) 
        return; 
  
    // Find the smallest character among first (n+1) characters 
    // of str. 
    int minIndex = 0; 
    for (int i = 1; i<=n ; i++) 
        if (str[i] < str[minIndex]) 
            minIndex = i; 
  
    // Append the smallest character to result 
    res.push_back(str[minIndex]); 
  
    // substring starting from minIndex+1 to str.length() - 1. 
    string new_str = str.substr(minIndex+1, len-minIndex); 
     cout<<str[minIndex]<<" "<<new_str<<" "<<n-minIndex<<endl;
  
    // Recur for the above substring and n equals to n-minIndex 
    buildLowestNumberRec(new_str, n-minIndex, res); 
    }
    string removeKdigits(string num, int k) {
        //cout<<num.substr(2, num.length()-1)<<endl;
        //string v = rec(num, k, 0);
        //cout<<num.length();
        // string v = dp(num, k);
        // cout<<v<<endl;
        // for(int i=0; i<v.length(); i++){
        //     if(v[i]!='0'){
        //         return v.substr(i, v.length());
        //     }
        // }
        // return "0";
        //return f(num, k, 0);
        string v="";
        buildLowestNumberRec(num, k, v);
        for(int i=0; i<v.length(); i++){
            if(v[i]!='0'){
                return v.substr(i, v.length());
            }
        }
        return "0";
        //return res;
        //return num;
    }
};
