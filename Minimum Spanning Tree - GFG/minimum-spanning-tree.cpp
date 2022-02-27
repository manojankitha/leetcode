// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,int>> ad[V];
        
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                ad[i].push_back(make_pair(adj[i][j][0], adj[i][j][1]));
                ad[adj[i][j][0]].push_back(make_pair(i, adj[i][j][1]));
            }
        }
        
        int parent[V];
        int key[V];
        bool mst[V];
        
        // initialize
        for(int i=0;i<V;i++){
            key[i]=INT_MAX;
            parent[i]=-1;
            mst[i]=false;
        }
        
        key[0]=0;
        
        for(int count=0;count<V-1;count++){
            
            int mini = INT_MAX, index;
            for(int i=0;i<V;i++){
                if(mst[i]==false && key[i]<mini){
                    mini = key[i];
                    index = i;
                }
            }
            mst[index]=true;
            
            for(auto j:ad[index]){
                int v = j.first;
                int wt = j.second;
                if(mst[v]==false and wt < key[v]){
                    parent[v] = index;
                    key[v] = wt;
                }
            }
            
        }
        int result = 0;
        for(int i=0;i<V;i++){result+=key[i];}
        
        return result;
        
      
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends