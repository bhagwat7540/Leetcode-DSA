class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for(int i=0 ; i<nums.size() ; i++){
            int s=i+1 , e=n-1;
            while(s<e){
                long long sum = nums[i] + nums[s] + nums[e];
                if(sum==0){
                    vector<int> v(3);
                    v[0] = nums[i];
                    v[1] = nums[s];
                    v[2] = nums[e];
                    ans.push_back(v);
                    
                    while(s+1<e && nums[s] == nums[s+1]) s++;
                    while(e-1>s && nums[e] == nums[e-1]) e--;
                }
                 if(sum > 0) e--;
                else s++;
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        
        return ans;
        
    }
};