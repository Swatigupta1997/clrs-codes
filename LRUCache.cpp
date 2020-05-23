#include <bits/stdc++.h> 
using namespace std; 

class LRUCache {
    unordered_map<int,int>m1;
    int cap=0;
    list<int>v;
    int l;
public:
    LRUCache(int capacity) {
        cap=capacity;
        l=0;
    }
    
    int get(int key) {
        if(m1.count(key)==0){return -1;}
        else{ 
            v.remove(key);
            v.push_front(key); 
            //cout<<"access "<<v.front()<<endl;
            return m1[key];
        }
        
    }
    
    void put(int key, int value) {
        //cout<<key<<" "<<"len: "<<l<<" cap: "<<cap<<endl;
        if(m1.count(key)!=0){
            m1[key]=value;
            v.remove(key);
            v.push_front(key);
        }else if(l<cap){
          l++;
          m1[key]=value;
          v.remove(key);
          v.push_front(key);
          
        }else{
          //cout<<v.back()<<endl;
          m1.erase(v.back());
          v.pop_back();
          v.push_front(key);
          //cout<<"after pop "<<v.back()<<endl;
          m1[key]=value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
