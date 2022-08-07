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
    map<int , int> mp;
    vector<int> ans;
    
    void f(TreeNode* root , int level){
        if(!root) return;
        
        mp[level] = root->val;
        f(root->left , level+1);
        f(root->right , level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        f(root , 0);    
        for(auto x : mp) ans.push_back(x.second);
        return ans;
    }
};