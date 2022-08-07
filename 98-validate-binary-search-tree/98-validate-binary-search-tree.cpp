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
    
    bool f(TreeNode* root , long long lb , long long ub){
        if(!root) return true;
        
        if(root->val <= lb || root->val >= ub) return false;
        
        return f(root->left, lb, root->val)&&f(root->right, root->val,ub);
    }
    
    bool isValidBST(TreeNode* root) {
        return f(root , LLONG_MIN , LLONG_MAX);
    }
};