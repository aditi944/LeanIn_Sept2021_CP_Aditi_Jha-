
	    queue<int> q;
	    vector<int> vis(V,-1);
	    
	    for( int i = 0 ; i < V ; i++)
	    {
	        if( vis[i] == -1 )
	        {   
	            q.push(i);
	            vis[i] = 0;
	            while(!q.empty())
	            {
    	            int node = q.front();	            
    	            q.pop();  
    	            for(auto it : adj [node])
    	            {
    	                if( vis[it] == -1)
    	                {
    	                    q.push(it);
    	                    vis[it] = 1 - vis[node];
    	                }
    	                else if( vis[it] == vis[node] )
    	                {
    	                    return false;
    	                }       
    	            }
	            }
	        }
	    }
	    return true;