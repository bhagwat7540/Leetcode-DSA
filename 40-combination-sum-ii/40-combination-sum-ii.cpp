class Solution {
public:
    vector<vector<int>> ans;
    
    void f(vector<int>& a , int t , int i , vector<int>& v){
        
        if(t == 0){
            ans.push_back(v);
            return;
        }
        
        if(i == a.size()) return;
        
        for(int j=i ; j<a.size() ; j++){
            if(j==i || a[j]!=a[j-1]){
                if(a[j] <= t){
                    v.push_back(a[j]);
                    f(a , t-a[j] , j+1 , v);
                    v.pop_back();   
                }
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin() , candidates.end());
        
        f(candidates , target , 0 , v);
        
        return ans;
    }
};