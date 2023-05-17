class Solution {
public:
    vector <vector<int>> dp;

    int f( int index, bool bought, vector<int>&prices){


        if ( index >= prices.size() ) return 0;
        if( dp[index][bought] != -1) return dp[index][bought];

        if( bought){
            int sell = prices[index] + f( index+2, false, prices) ;
            int hold = 0 + f( index+1, true , prices);
            return dp[index][bought] = max(sell, hold);
        }
        else{
            int buy =  f( index+1, true, prices) - prices[index] ;
            int next_buy = 0 + f( index+1, false, prices);
            return  dp[index][bought] =max( buy, next_buy);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        dp.resize( n, vector<int> ( 2, -1));
        return f( 0 , false, prices);
    }
};