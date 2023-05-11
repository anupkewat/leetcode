class Solution {
public:

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector <vector<int>> dp ( nums1.size() , vector<int> (nums2.size(),-1)) ;
        return f(nums1, nums2, nums1.size()-1, nums2.size()-1, dp);
    }
    
    int f(vector<int>& nums1, vector<int>& nums2, int i, int j, vector <vector<int>> &dp) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if ( dp[i][j] != -1) return dp[i][j];
        if (nums1[i] == nums2[j]) { 
            return dp[i][j] =1 + f(nums1, nums2, i-1, j-1,dp);
        }
        return dp[i][j] = max(f(nums1, nums2, i-1, j, dp), f(nums1, nums2, i, j-1, dp));
    }
};
