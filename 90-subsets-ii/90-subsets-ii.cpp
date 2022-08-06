class Solution {
public:
    vector<vector<int>> ans;
    
    void f(vector<int>& nums , int i , vector<int>& yo){
        
        ans.push_back(yo);
        
        for(int ind = i ; ind<nums.size() ; ind++){
            if(ind!=i && nums[ind] == nums[ind-1]) continue;
            yo.push_back(nums[ind]);
            f(nums , ind+1 , yo);
            yo.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int> yo;
        f(nums , 0 , yo);
        return ans;    
    }
};