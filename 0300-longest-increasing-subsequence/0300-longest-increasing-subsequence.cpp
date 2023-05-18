class Solution {
public:
    int f ( vector<int>& nums, int i, int prev, vector <vector<int>>&dp  ){
        if (i<0 ) return 0;
        if (dp[i+1][prev+1] != -1) return dp[i+1][prev+1];

        
        int pick = 0; 
       

         if ( prev == -1 or nums[i] < nums[prev] ){
              pick =  1 + f(nums, i-1, i, dp);
         }
         int nonpick = 0 + f(nums,i-1,prev, dp);
         return dp[i+1][prev+1] = max(pick,nonpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector <vector<int>>dp ( nums.size()+ 1 , vector<int>(nums.size() + 1, -1)) ;

        return f ( nums, nums.size()-1, -1,dp);
    }
};