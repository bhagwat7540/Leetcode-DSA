class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k1) {
        int n = matrix.size();
//         vector<int> a(n*n);
//         int k=0;
//         for(int i=0 ; i<n ; i++){
//             for(int j=0 ; j<n ; j++){
//                 a[k] = matrix[i][j];
//                 k++;
//             }
//         }
        
//         sort(a.begin() , a.end());
        
//         return a[k1-1];
        int l = matrix[0][0];
        int r = matrix[n-1][n-1];
        int ans;
        
        while(l<=r){
            long long mid = l + (r-l)/2;
            int cnt=0;
            for(int i=0 ; i<n ; i++){
                int ind = upper_bound(matrix[i].begin() , matrix[i].end() , mid) - 
                          matrix[i].begin();
                    
                cnt += ind;    
            }
            
            if(cnt >= k1){
                ans = mid;
                r=mid-1;
            }
            else l = mid+1;
        }
        
        return ans;
    }
};