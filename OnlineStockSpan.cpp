class StockSpanner {
    stack<int>s;
    vector<int>p;
    int i;
public:
    StockSpanner() {
        i=-1;
    }
    
    int next(int price) {
        int c=0;
        //cout<<price<<endl;
        while(!s.empty() && p[s.top()]<=price){
            //cout<<"here";
            //cout<<p[s.top()]<<endl;
            s.pop();
        }
        if(s.empty()){
            p.push_back(price);
            i++;
            s.push(i);
            return i+1;
        }
        //cout<<i<<" "<<s.top()<<endl;
        i++;
        c = i-s.top();
        s.push(i);
        p.push_back(price);
        return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
