class Solution {
public:
    
    int f(int i , int j , vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        
        if(i<0 || j<0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = f(i-1 , j , dp) + f(i , j-1 , dp);
    }
    
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m , vector<int>(n , -1));
        // return f(m-1 , n-1 , dp);
        
        // m-1 + n-1  Total steps
        // m-1 in one direction
        
        // ans = m+n-2 C m-1
        
        int total = m+n-2;
        int one = m-1;
        
        double ans=1;
        for(int i=1 ; i<=one ; i++){
            ans *= (total - one + i);
            ans /= i;
        }
        
        return (int)ans;
    }
};