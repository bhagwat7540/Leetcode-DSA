class Solution {
public:
    
    vector<vector<int>> ans;
    
    void f(vector<int>& nums , int i , vector<int>& v){
        
        if(i < 0){
            ans.push_back(v);
            return;
        }
        
        f(nums , i-1 , v);
        v.push_back(nums[i]);
        f(nums , i-1 , v);
        v.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        
        f(nums , nums.size()-1 , v);
        
        return ans;
    }
};