class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size();
//         int i=0 , j=m-1;
        
//         while(i<n && j>=0){
//             if(matrix[i][j] == target) return true;
//             else if(matrix[i][j] < target) i++;
//             else j--;
//         }
        
//         return false;
        int i=0 , j=n*m-1;
        
        while(i<=j){
            long long mid = i + (j-i)/2;
            int r = mid/m , c = mid%m;
            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] > target) j=mid-1;
            else i = mid+1;
        }
        
        return false;
    }
};