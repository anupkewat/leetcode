class Solution {
public:
    vector <vector< vector<int>>> dp;

    int f( int index, bool bought, vector<int>&prices, int t){


        if ( index >= prices.size() ) return 0;

        
        if( dp[index][bought][t] != -1) return dp[index][bought][t];

        if( bought){
            int sell = prices[index] + f( index+1, false, prices, t - 1) ;
            int hold = 0 + f( index+1, true , prices, t);
            return dp[index][bought][t] = max(sell, hold);
        }
        else{
            if (t > 0){
                int buy =  f( index+1, true, prices ,t) - prices[index] ;
                int next_buy = 0 + f( index+1, false, prices, t);
                return  dp[index][bought][t] =max( buy, next_buy);
                }
            else { return 0 ;}
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        dp.resize( n, vector< vector<int>>( 2, vector<int> (3 , -1)));
        return f( 0 , false, prices, 2);
    }
};