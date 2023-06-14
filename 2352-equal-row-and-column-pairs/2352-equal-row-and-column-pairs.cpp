class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        int ans =0;
        int maxi = INT_MIN;
        map<string, int> mp;
        for( int i=0;i<n;i++){
            string s ="";
            for(int j=0;j<m;j++){
            s += to_string(grid[i][j]) + ".";
            
            }
            mp[s]++;
            cout << s << " ";
            
            maxi = max( mp[s], maxi);
        }
        for(int i=0 ;i<m;i++){
            string s ="";
            for(int j=0;j<n;j++){
            s += to_string(grid[j][i]) + ".";
            
            }
            cout <<  s << ".";
            if (mp[s] >=1){ ans+= mp[s];}

        }
        return ans;
        
    }
};