map<char,int>arr;

bool comp(char a, char b){
        return (arr[a]>arr[b]);
}
class Solution {
    
public:
 
    string frequencySort(string s) {
        string p="";
        for(int i=0; i<s.length(); i++){
            if(arr.count(s[i])==0){
                arr[s[i]]=1;
                p=p+s[i];
            }else{
                arr[s[i]]=arr[s[i]]+1;
            }
        }
        
        //cout<<arr['A']<<endl;
        sort(p.begin(), p.end(), comp);
        //cout<<p<<endl;
        string x="";
        for(int i=0; i<p.length(); i++){
            x=x+string(arr[p[i]], p[i]);
        }
        arr.clear();
        //cout<<s<<endl;
        return x;
    }
};
