class Solution {
public:
    
    int f(int i , int j , vector<int>& nums , vector<vector<int>>& dp){
        
        if(i>j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxx = 0;
        for(int ind=i ; ind<=j ; ind++){
            int ans = nums[i-1]*nums[ind]*nums[j+1];        
            ans += f(i , ind-1 , nums , dp) + f(ind+1 , j , nums , dp);
            
            maxx = max(maxx , ans);
        }
        
        return dp[i][j] = maxx;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin() , 1);
        int n = nums.size();
        
        vector<vector<int>> dp(n , vector<int>(n , 0));
        
        for(int i=n-2 ; i>=1 ; i--){
            for(int j=1 ; j<=n-2 ; j++){
                if(i>j) continue;
                
                int maxx = 0;
                
                for(int ind=i ; ind<=j ; ind++){
                    int ans = nums[i-1]*nums[ind]*nums[j+1];
                    ans += dp[i][ind-1] + dp[ind+1][j];
                    
                    maxx = max(maxx , ans);
                }
                
                dp[i][j] = maxx;
            }
        }
        
        return dp[1][n-2];
        // return f(1 , n-2 , nums , dp);
    }
};