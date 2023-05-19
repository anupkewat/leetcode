//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, vector<int>adj[], int viz[], int pathviz[]){
        viz[node] = 1; 
        pathviz[node] = 1;
        for ( auto i : adj[node]){
            if (!viz[i])
            {if ( dfs(i, adj, viz, pathviz)) 
                return true;}
            else {
                if ( pathviz[i] ) return true;
            } 
        }
        pathviz[node] = 0;
        return false; 
        
        }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int viz[V] = {0};
        int pathviz[V] = {0};
        
        for ( int i =0 ;i<V; i++){
            if ( !viz[i]){
                if (dfs(i, adj, viz, pathviz)) 
                    return true;
            }
        }
        return false; 
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends