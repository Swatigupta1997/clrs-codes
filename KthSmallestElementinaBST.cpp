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
    int flag=0;
    int kval;
    void dfs(TreeNode* root, int k){
        if(flag>k){return;}
        if(root->left){
            dfs(root->left, k);
        }
        flag++;
        if(flag==k){
            kval=root->val;
            return;
        }
        if(flag<k && root->right){
            dfs(root->right, k);
        }
        
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root){
            dfs(root, k);
        }
        return kval;   
    }
};
