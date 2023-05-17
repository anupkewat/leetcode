//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs ( int node, stack<int> &s, int viz[], vector<int> adj[] )
	{
	    viz[node] = 1; 
	    for ( auto i : adj[node]){
	        if( !viz[i]) dfs( i, s, viz, adj);
	            
	    }
	    s.push(node); // after done adding all the neighbours,add the node to the stack
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	    int viz[V] = {0};
	    stack <int> s; 
	    for( int i= 0; i<V; i++)
	       if( !viz[i]) 
	        dfs( i , s, viz, adj);
	   
	   
	    vector<int> ans;
	    
        while( !s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends