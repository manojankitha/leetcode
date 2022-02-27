// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	
	int findPar(int node, vector<int>& parent){
	    if(node==parent[node]){
	        return node;
	    }
	    return parent[node]=findPar(parent[node],parent);
	}
	
	void Union(int uP, int vP, vector<int>& parent, vector<int>& rank){
	    int u = findPar(uP,parent);
	    int v = findPar(vP,parent);
	    
	    if(rank[u]<rank[v]){
	        parent[u]=v;
	    } else if (rank[v]<rank[u]){
	        parent[v]=u;
	    }else if(rank[v]==rank[u]){
	        parent[v]=u;
	        rank[u]++;
	    }
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        vector<int> parent(V);
        vector<int> rank(V,0);
        // code here
        vector<vector<int>> edgeList;
        
        for(int i=0;i<V;i++){
            vector<int> temp;
            for(int j=0;j<adj[i].size();j++){
                temp.push_back(adj[i][j][1]);
                temp.push_back(adj[i][j][0]);
                temp.push_back(i);
             
                edgeList.push_back(temp);
                temp.clear();
            }
        }
       
          
        
        // sort in increasing order of weight
        sort(edgeList.begin(), edgeList.end());
        
        // initialization
        for(int i=0;i<V;i++){
            parent[i]=i;
            rank[i]=0;
        }
        
        int result = 0;
        
        for(auto edge: edgeList){
            if(findPar(edge[1],parent) !=findPar(edge[2],parent)){
                result+=edge[0];
                Union(edge[1],edge[2],parent,rank);
            }
        }
        
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