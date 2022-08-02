class Solution {
public:
    
    static bool comp(vector<int>& a , vector<int>& b){
        if(a[1]<b[1]) return true;
        if(a[1]==b[1] && a[0]<=b[0]) return true;
        return false;
    }
    
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin() , events.end());
        priority_queue<int , vector<int> , greater<int>> pq;
        int n = events.size();
        int j=0 , ans=0;
        
        for(int i=1 ; i<=1e5 ; i++){
            
            while(!pq.empty() && pq.top()<i) pq.pop();
            
            while(j<n && events[j][0] == i){
                pq.push(events[j][1]);
                j++;
            }
            
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
            
            if(j==n && pq.empty()) break;
        }
        
        return ans;
        
    }
};