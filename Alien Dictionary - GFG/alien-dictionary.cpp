//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
	void dfs(int node,vector<int> adj[], vector <int> &viz, stack <int> &s){
	
	    viz[node ] =1 ; 
	    for ( auto i : adj[node]){
	        if (!viz[i])
	            dfs( i, adj, viz, s);
	    }
	    s.push(node);
	    
	}
    
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        vector<int> viz(K, 0);
        stack<int> s; 

        for ( int i = 0 ; i<N-1 ; i++){
            string word1= dict[i];
            string word2= dict[i+1]; 
            int mini = min( word1.size(), word2.size());
            for(int j=0;j<mini;j++){
                if (word1[j]!=word2[j]){
                    adj[word1[j] - 'a'].push_back(word2[j]-'a');
                    break;
                }
            }
        }
        
        //  topo sort 
        //  adj 
        
        for ( int i=0;i<K;i++){
            if( !viz[i]){dfs(i, adj,viz,s);}
        }
        string ans = "";
        for ( ;!s.empty();s.pop())
        {
            int top = s.top(); 
            ans+= char(top + 'a');
        }
        return ans;
        
        //code here
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends