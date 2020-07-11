/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.
*/

class Solution {
    vector<vector<int>> v;
public:
    void print(vector<int>& v1){
        for(int i=0; i<v1.size(); i++){
            cout<<v1[i]<<" ";
        }
        cout<<endl;
    }
    void ss(vector<int>& nums, vector<int> &v1, int i, int n){
        if(i==n){
            //print(v1);
            v.push_back(v1);
            return;
        }
        ss(nums, v1, i+1, n);
        v1.push_back(nums[i]);
        ss(nums, v1, i+1, n);
        v1.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>v1;
        ss(nums, v1, 0, n);
        
        return v;
    }
};
