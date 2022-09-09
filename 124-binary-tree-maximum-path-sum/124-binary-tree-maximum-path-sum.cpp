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
    
    class Pair{
        
        public:
        int maxSoFar=-(int) 1e9;
        int maxPathSum =-(int) 1e9;
    };
    
    Pair maxPathSumUti(TreeNode *root)
    {
        if(root==NULL)
        {
            Pair base;
            return base;
        }
        
        if(root->left==NULL&&root->right==NULL)
        {
            Pair base;
            base.maxSoFar=root->val;
            base.maxPathSum=root->val;
            return base;
        }
        Pair left=maxPathSumUti(root->left);
        Pair right=maxPathSumUti(root->right);
        
        Pair myAns;
        myAns.maxSoFar=max({root->val,root->val+max(left.maxPathSum,right.maxPathSum),root->val+left.maxPathSum+right.maxPathSum,left.maxSoFar,right.maxSoFar});
        myAns.maxPathSum=max(root->val,root->val+max(left.maxPathSum,right.maxPathSum));
        return myAns;
    }
    
    int maxPathSum(TreeNode* root) {
        
       return  maxPathSumUti(root).maxSoFar;
        
    }
};