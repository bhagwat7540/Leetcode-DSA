class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin() , nums.end());
        int cnt=1;
        int ans=1;
        
        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i]==nums[i-1]) continue;
            else if(nums[i] == nums[i-1]+1){
                cnt++;
                ans = max(ans , cnt);
            }
            else cnt=1;
        }
        
        return ans;
    }
};