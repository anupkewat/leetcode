class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(); 
        int m = matrix[0].size();
        int ans =-1;
        vector<vector<int>> dp ( n+1, vector<int> (m+1,0));
        for ( int i =0;i<n;i++){
            for( int j =0; j<m;j++){
                if ( matrix[i][j] == '1')
                    dp[i+1][j+1] = 1 + min ( {dp[i+1][j] ,dp[i][j], dp[i][j+1]} );

                
                ans = max( ans, dp[i+1][j+1]);
            }
        }
        return ans*ans;
    }
};