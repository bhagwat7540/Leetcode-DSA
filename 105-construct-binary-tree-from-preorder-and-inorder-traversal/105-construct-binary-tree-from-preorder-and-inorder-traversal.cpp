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
    
    TreeNode* f(vector<int>& p , int ps , int pe , vector<int>& i , int is ,                   int ie , map<int,int> &mp){
        if(is>ie || ps>pe) return NULL;
        
        TreeNode* root = new TreeNode(p[ps]);
        
        int ind = mp[root->val];
        int val = ind-is;
        
        root->left = f(p , ps+1 , ps+val , i , is , ind-1 , mp);
        root->right = f(p , ps+val+1 , pe , i , ind+1 , ie , mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        
        for(int i=0 ; i<inorder.size() ; i++) mp[inorder[i]] = i;
        
        return f(preorder , 0 , preorder.size()-1 , inorder , 0 ,                                inorder.size()-1 , mp);
    }
};