class Solution {
public:


        bool dfs(int node,vector<vector<int>>& adj,vector<int> &viz,vector<int> &pathviz,vector<int> &check){
            viz[node] = 1; 
            pathviz[node] = 1; 
            check[node] = 0; 

            for( auto i : adj[node]){
                if(!viz[i]){
                    if(dfs(i, adj, viz, pathviz, check)){
                        check[node] = 0;
                        return true;
                    }
                }
                else if (pathviz[i]){
                    check[node] = 0;
                    return true;
                }

            }
            check[node] = 1; 
            pathviz[node] = 0;
            return false; 
            
        }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> viz(n);
        vector<int> pathviz(n);
        vector<int> check(n);
        for ( int i =0; i<n;i++){
            if( !viz[i])
                dfs(i, adj, viz, pathviz, check);
        }
        vector <int> ans;
        for ( int i =0 ; i<n;i++){
            if( check[i] == 1)
                ans.push_back(i);
        }
        return ans;

    }
};