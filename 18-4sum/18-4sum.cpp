class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                long long target1 = 1ll*target - nums[i] - nums[j];
                
                int s=j+1 , e=n-1;
                
                while(s<e){
                    long long sum = nums[s] + nums[e];
                    if(sum < target1) s++;
                    else if(sum > target1) e--;
                    else{
                        vector<int> v(4);
                        v[0] = nums[i];
                        v[1] = nums[j];
                        v[2] = nums[s];
                        v[3] = nums[e];
                        ans.push_back(v);
                        
                        while(s<e && nums[s]==v[2]) s++;
                        while(e>s && nums[e]==v[3]) e--;
                    }
                }
                while(j+1<n && nums[j+1]==nums[j]) j++;
            }
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        
        return ans;
    }
};