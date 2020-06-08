class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size()==0)
            return false;
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        int left=0,right=r*c-1;
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            int midel = matrix[mid/c][mid%c];
            if(midel==target)
                return true;
            else if(midel>target)
                right = mid-1;
            else
                left = mid+1;
        }
        
        return false;
    }
};