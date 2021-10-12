void dfs(int node ,vector<int> &vis,vector<int> &res,vector<int> adj[]){

	    res.push_back(node);

	    vis[node] = 1;

	    for(auto it : adj[node]){

	        if(!vis[it]){

	            dfs(it,vis,res,adj);

	        }
	    }
	}
	vector<int>dfsOfGraph(int V, vector<int> adj[])

	{
	   vector<int> res;

	   vector<int> vis(V,0);

	   dfs(0,vis,res,adj);

	   return res;
	}