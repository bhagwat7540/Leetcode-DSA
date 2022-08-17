class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> temp(n) , t(n);
        
        int sum1=0 , sum2=0;
        for(int i : nums1) sum1 += i;
        for(int i : nums2) sum2 += i;
        
        int ans = max(sum1 , sum2);
        
        for(int i=0 ; i<n ; i++){
            temp[i] = nums1[i] - nums2[i];
            t[i] = nums2[i] - nums1[i];
        }
        
        int sum=0 , maxx=INT_MIN;
        
        for(int i=0 ; i<n ; i++){
            sum += temp[i];
            maxx = max(maxx , sum);
            
            if(sum<0) sum=0;
        }
        
        ans = max(ans , sum2+maxx);
        sum=0;
        int minn = INT_MAX;
        
        for(int i=0 ; i<n ; i++){
            sum += temp[i];
            minn = min(minn , sum);
            
            if(sum>0) sum=0;
        }
        
        ans = max(ans , sum1 -minn);
        
//         for(int i=0 ; i<n ; i++){
//             sum += t[i];
//             maxx = max(maxx , sum);
            
//             sum = sum < 0 ? 0 : sum;  
//         }
        
//         ans = max(ans , sum1 + maxx);
        
        return ans;
    }
};