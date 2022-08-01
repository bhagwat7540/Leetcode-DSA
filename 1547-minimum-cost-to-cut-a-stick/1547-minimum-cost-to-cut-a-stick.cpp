class Solution {
public:
    
    int f(int i , int j , vector<int>& cuts , vector<vector<int>>& dp){
        
        if(i>j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int minn = INT_MAX;
        for(int ind = i ; ind<=j ; ind++){
            int cost = cuts[j+1] - cuts[i-1] + f(i, ind-1, cuts, dp) + f(ind+1, j,                          cuts, dp);
            
            minn = min(minn , cost);
        }
        
        return dp[i][j] = minn;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);
        sort(cuts.begin() , cuts.end());
        int size = cuts.size();
        
        vector<vector<int>> dp(size+1 , vector<int>(size+1 , 0));
        
        for(int i=size-2 ; i>=1 ; i--){
            for(int j=1 ; j<=size-2 ; j++){
                if(i>j) continue;
                
                int minn = INT_MAX;
                for(int ind=i ; ind<=j ; ind++){
                    int cost = cuts[j+1]-cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                    
                    minn = min(minn , cost);
                }
                dp[i][j] = minn;
            }
        }
        
        return dp[1][size-2];
        // return f(1 , size-2 , cuts , dp);
    }
};