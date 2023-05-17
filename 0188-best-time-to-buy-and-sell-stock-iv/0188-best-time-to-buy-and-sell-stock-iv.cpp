class Solution {
public:

    int f( int index, bool bought, vector<int>&prices, int t, vector<vector<vector<int>>>&dp){


        if ( index >= prices.size() ) return 0;

        
        if( dp[index][bought][t] != -1) return dp[index][bought][t];

        if( bought){
            int sell = prices[index] + f( index+1, false, prices, t - 1, dp) ;
            int hold = 0 + f( index+1, true , prices, t, dp);
            return dp[index][bought][t] = max(sell, hold);
        }
        else{
            if (t > 0){
                int buy =  f( index+1, true, prices ,t, dp) - prices[index] ;
                int next_buy = 0 + f( index+1, false, prices, t, dp);
                return  dp[index][bought][t] =max( buy, next_buy);
                }
            else
            { return 0 ;}
        }
    }
int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<vector<int>>>dp( n, vector< vector<int>>( 2, vector<int> (k+1 , -1)));
        return f( 0 , false, prices, k,dp);
    }
};