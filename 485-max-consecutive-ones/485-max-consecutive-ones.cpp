class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j=0;
        int ans=0;
        
        while(j<nums.size()){
            if(nums[j]==1){
               int i=j;
               int cnt = 0; 
               while(i<nums.size() && nums[i]==1) cnt++ , i++; 
               ans = max(ans , i-j); 
               j=i-1; 
            }
            j++;
        }
        
        return ans;
    }
};