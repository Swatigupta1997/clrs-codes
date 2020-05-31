class Solution {
    static bool comp(vector<int>a , vector<int>b){
        return a[0]<b[0];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>>v;
        int dist;
        for(int i=0; i<points.size(); i++){
            dist = points[i][0]*points[i][0]+points[i][1]*points[i][1];
            vector<int>x;
            x.push_back(dist);
            x.push_back(i);
            v.push_back(x);
        }
        sort(v.begin(), v.end(), comp);
        vector<vector<int>>val;
        for(int i=0; i<K; i++){
            int k = v[i][1];
            val.push_back(points[k]);
        }
        return val;
    }
};
