/* Is Graph Bipartite (leetcode 785)
Algorithm: we are using iterative BFS,
	1.we will do a BFS keeping track of visited nodes with color.
	2.for one colour we use 1 for other -1.
	3.if at any point we find the child and par having same colour we conclude graph is not bipartite.
	
*/
//code
bool isBipartite(vector<vector<int>>& graph) {
        vector<int>vis(graph.size()+1,0);
        queue<int>q;
        for(int i=0;i<graph.size();++i)
        {
            if(vis[i])
                continue;
            vis[i]=1;
            q.push(i);
            while(q.empty()==false)
           {
                int par=q.front();
                for(auto child:graph[par])
                {
                    if(!vis[child])
                    {
                        vis[child]=-1*vis[par];
                        q.push(child);
                    }
                    else if(vis[child]==vis[par])
                        return false;
                    
                }
                q.pop();
            
           }
        }    
        return true;
    }	 
