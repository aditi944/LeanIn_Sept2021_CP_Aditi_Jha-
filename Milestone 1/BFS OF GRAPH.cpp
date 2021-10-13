class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
     vector<int> bfs;
       
       //Visited Array
       bool visited[V];
       for(int i = 0; i < V; i++) 
       visited[i] = false; 
       
       //A queue for temporary
       queue<int> q;
       visited[0]=true;
       q.push(0);
       
       while(q.empty()==false)
       {
           //Store current queue value in a variable and pop the queue
           int k=q.front();
           q.pop();
           
           bfs.push_back(k); //store bfs in a vector
           
           for(int x:adj[k])//Traverses the current node's edges
           {
               if(visited[x]==false)//only insert the node if it is not traversed before
               {
                   visited[x]=true;//sets traversed node to true
                   q.push(x);//pushes all the directed node of x in the queue
               }
           }
       }
       return bfs;
   }
};
