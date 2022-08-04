class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        
        for(int i=n-2 ; i>=0 ; i--){
            if(nums[i]<nums[i+1]){
                ind = i;
                break;
            }
        }
        
        if(ind == -1){
            reverse(nums.begin() , nums.end());
            return;
        }
        
        int i = n-1;
        for( ; i>=0 ; i--){
            if(nums[i] > nums[ind]){
                break;
            }
        }
        
        swap(nums[ind] , nums[i]);
        
        reverse(nums.begin()+ind+1 , nums.end());
        
    }
};