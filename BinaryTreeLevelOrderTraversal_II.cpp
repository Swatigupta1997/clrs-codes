/*

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void bfs(TreeNode* root, vector<vector<int>> &v){
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        int curr_level_nodes=1;
        vector<int>tmp;
        
        while(!q.empty()){
            TreeNode *curr = q.front();
            //cout<<curr->val<<" ";
            tmp.push_back(curr->val);
            
            q.pop();
            curr_level_nodes--;
            
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
            if(curr_level_nodes==0){
                //cout<<""<<endl;
                // level changed! 
                curr_level_nodes=q.size();
                level++;
                v.push_back(tmp);
                tmp.clear();
            }
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL){return v;}
        bfs(root, v);
        reverse(v.begin(), v.end());
        return v;
    }
};
