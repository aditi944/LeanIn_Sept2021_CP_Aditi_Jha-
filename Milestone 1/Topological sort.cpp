void findtoposort(int node,vector<int> adj[],vector<int> &vis,stack<int> &st){
    vis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0){
            findtoposort(it,adj,vis,st);
        }
    }
    st.push(node);
}
//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    stack<int> st;
    vector<int> vis(V,0);
    for(int i=0;i<V;i++){
        if(vis[i]==0){
            findtoposort(i,adj,vis,st);
        }
    }
    vector<int> topo;
    while(!st.empty()){
    topo.push_back(st.top());
    st.pop();
    }
    return topo;
    
}
