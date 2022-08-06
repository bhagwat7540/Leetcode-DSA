class Solution {
public:
    vector<vector<int>> ans;
    
    void f(vector<int>& a , int t , int i , vector<int>& yo){
        
        if(t == 0){
            ans.push_back(yo);
            return;
        }
        
        if(i == a.size()) return;
        
        f(a , t , i+1 , yo);
        
        if(t >= a[i]){
           yo.push_back(a[i]);
           f(a , t-a[i] , i , yo);
           yo.pop_back(); 
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> yo;
        f(candidates , target , 0 , yo);
        return ans;
    }
};