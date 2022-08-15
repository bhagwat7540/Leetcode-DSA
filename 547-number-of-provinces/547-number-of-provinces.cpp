class Solution {
public:
    
    void dfs(vector<vector<int>>& isConnected , int node , vector<int>& vis){
        vis[node] = 1;
        
        for(int i=0 ; i<isConnected[node].size() ; i++){
            if(isConnected[node][i] && !vis[i]) dfs(isConnected , i , vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        long long ans = 0;
        int n = isConnected.size();
        vector<int> vis(n+1 , 0);
        
        for(int i=0 ; i<isConnected.size() ; i++){
            if(!vis[i]){
                ans++;
                dfs(isConnected , i , vis);
            }
        }
        
        return ans;
    }
};