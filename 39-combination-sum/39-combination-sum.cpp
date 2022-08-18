class Solution {
public:
    
    vector<vector<int>> ans;
    
    void f(vector<int>& a , int i , int t , vector<int>& v){
        
        if(i == a.size()) return;
        
        if(t == 0){
            ans.push_back(v);
            return;
        }
        
        f(a , i+1 , t , v);
        
        if(a[i] <= t){
            v.push_back(a[i]);
            f(a , i , t-a[i] , v);
            v.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        f(candidates , 0 , target , v);
        
        return ans;
    }
};