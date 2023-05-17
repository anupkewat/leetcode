class Solution {
private:
    int n, m;
    vector <int> delrow = {-1,0,1,0};
    vector <int> delcol = { 0,1,0,-1};
public:


    void dfs( int i, int j, vector <vector<int>> &viz, vector<vector<int>>& grid){
        viz[i][j] = 1; 

        for (int p =0;p<4;p++){
            int ncol = j+delcol[p];
            int nrow = i+delrow[p];
            if ( ncol<m and nrow<n and nrow >-1 and ncol>-1 and grid[nrow][ncol] == 1 and !viz[nrow][ncol])
                dfs(nrow,ncol,viz,grid);


        }
        
    }
    int numEnclaves(vector<vector<int>>&grid) {
        n = grid.size(); 
        m = grid[0].size(); 
        

        vector <vector<int>> viz(n, vector<int>(m, 0));
        int count = 0; 
        for ( int i =0 ; i<n;i++){
            for ( int j =0;j<m;j++){
                if (i == 0 or i == n-1 or j==0 or j==m-1){
                if ( !viz[i][j] and grid[i][j] == 1)
                    dfs(i,j,viz,grid);
                }
                    
            }
        }
        for ( int i =0 ; i<n;i++){
            for ( int j =0;j<m;j++){
                if (grid[i][j] == 1 and !viz[i][j] )
                    count ++; 
            }}
        
        return count ;
        
        
    }
};