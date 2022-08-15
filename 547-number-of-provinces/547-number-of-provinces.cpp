class Solution {
public:
    
    void dfs(vector<int> adj[] , int node , vector<int>& vis){
        vis[node] = 1;
        
        for(auto x : adj[node]){
            if(!vis[x]) dfs(adj , x , vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        long long ans = 0;
        int n = isConnected.size();
        vector<int> vis(n+1 , 0);
        vector<int> adj[n+1];
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<isConnected[i].size() ; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                ans++;
                dfs(adj , i , vis);
            }
        }
        
        // for(int i=0 ; i<isConnected.size() ; i++){
        //     if(!vis[i]){
        //         ans++;
        //         dfs(isConnected , i , vis);
        //     }
        // }
        
        return ans;
    }
};