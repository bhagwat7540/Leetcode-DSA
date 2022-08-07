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
    
    TreeNode* f(vector<int>&i , int is , int ie , vector<int>&p , int ps , int                 pe , map<int , int>& mp){
        
        if(is>ie || ps>pe) return NULL;
        
        TreeNode* root = new TreeNode(p[pe]);
        
        int ind = mp[p[pe]];
        int val = ind - is;
        
        root->left = f(i , is , ind-1 , p , ps , ps+val-1 , mp);
        root->right = f(i , ind+1 , ie , p , ps+val , pe-1 , mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        map<int,int> mp;
        
        for(int i=0 ;i<in.size() ; i++){
            mp[in[i]] = i;
        }
        
        return f(in , 0 , in.size()-1 , po , 0 , po.size()-1 , mp);
    }
};