class Solution {
public:
    
    int f(vector<int>& nums , int i , int target , vector<vector<int>>& dp){
        
        if(target == 0) return 1;
        if(i==nums.size()) return 0;
        
        if(dp[i][target] != -1) return dp[i][target];
        
        int ans1 = f(nums , i+1 , target , dp);
        int ans2 = 0;
        if(nums[i]<=target){
            ans2 = f(nums , 0 , target-nums[i] , dp);    
        }
        
        return dp[i][target] = ans1 + ans2;
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(target+1 , -1));
        return f(nums , 0 , target , dp);
    }
};