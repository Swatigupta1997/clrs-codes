class Solution {
public:
    int check_maps(map<char, int>&m, map<char, int>&m1){
        for(auto i=m.begin(); i!=m.end(); i++){
            if(m1.count(i->first)==0){
                return 0;
            }else if(i->second!=m1[i->first]){
                return 0;
            }
        }
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length() || s2.length()==0){return false;}
        map<char, int>m;
        map<char,int>m1;
        string s = s2;
        string p= s1;
        for(int i=0; i<p.length(); i++){
            if(m.count(p[i])==0){
                m[p[i]]=1;
            }else{
                m[p[i]]=m[p[i]]+1;
            }
            if(m1.count(s[i])==0){
                m1[s[i]]=1;
            }else{
                m1[s[i]]=m1[s[i]]+1;
            }
        }
        if (check_maps(m, m1)){
           return true;
        }
        int prev=0;
        int next=p.length();
        int i=1;
        while(next<s.length()){
            //cout<<next<<endl;
            if(m1.count(s[next])==0){
                m1[s[next]]=1;
            }else{
                m1[s[next]]=m1[s[next]]+1;
            }
            m1[s[prev]]=m1[s[prev]]-1;
            
            if (check_maps(m, m1)){
                return true;
            }
            i++;
            prev++;
            next++;      
        }
        return false;
    }
};
