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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> vec;
        
        TreeNode *curr=root;
        
        while(curr!=NULL){
            
            TreeNode *pre=curr->left;
            if(pre==NULL){
                vec.push_back(curr->val);
                curr=curr->right;
            }
            else {
                while(pre->right!=NULL&&pre->right!=curr){
                    pre=pre->right;
                }
                
                if(pre->right==NULL){
                    pre->right=curr;
                    curr=curr->left;
                }
                else{
                    vec.push_back(curr->val);
                    pre->right=NULL;
                    curr=curr->right;
                }
                        
            }
        }
        
        return vec;
        
    }
};