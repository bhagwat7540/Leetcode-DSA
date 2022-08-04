class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int n = intervals.size();
        
        vector<vector<int>> ans;
        
        for(int i=0 ; i<n ; i++){
            int l = intervals[i][0] , r = intervals[i][1];
            int j=i+1;
            
            while(j<n && intervals[j][0]<=r){
                r = max(r , intervals[j][1]);
                j++;
            }
            i=j-1;
            ans.push_back({l,r});
        }
        
        return ans;
    }
};