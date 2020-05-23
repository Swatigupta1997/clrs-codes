class Solution {
public:
    int check(string p, string n){
        //cout<<p<<endl;
        sort(n.begin(), n.end());
             
        if (p==n){
            return 1;
        }
        return 0;
    }
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
    vector<int> findAnagrams(string s, string p) {
        vector<int>v;
        if(s.length()<p.length()){return v;}
        map<char, int>m;
        map<char,int>m1;
        sort(p.begin(), p.end());
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
            v.push_back(0);
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
                v.push_back(i);
            }
            i++;
            prev++;
            next++;      
        }
        return v;
    }
};
