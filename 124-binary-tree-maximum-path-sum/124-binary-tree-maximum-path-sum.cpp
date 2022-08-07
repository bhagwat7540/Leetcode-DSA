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
    int ans=INT_MIN;
    
    int f(TreeNode* root){
        if(!root) return 0;
        
        int lsum = max(0,f(root->left));
        int rsum = max(0,f(root->right));
        
        ans = max(ans , lsum + rsum + root->val);
        
        return root->val + max(lsum , rsum);
    }
    
    int maxPathSum(TreeNode* root) {
        f(root);
        return ans;
    }
};