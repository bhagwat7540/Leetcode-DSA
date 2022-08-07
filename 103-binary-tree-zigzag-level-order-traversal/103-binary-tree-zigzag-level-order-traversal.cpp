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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        bool flag = true;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int x = q.size();
            vector<int> yo(x);
            
            for(int i=0 ; i<x ; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(flag) yo[i] = node->val;
                else yo[x-i-1] = node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            ans.push_back(yo);
            flag = !flag;
        }
        
        return ans;
    }
};