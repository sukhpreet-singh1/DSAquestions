//Rotting oranges (leetcode 994)
/* We will use iterative BFS 
Algorithm: 
 	1.Put all the rotten oranges in queue.
	2.Start tarversing the queue and mark adjacent oranges as rotten and add to queue.
	3. after each traversal increase the time.
		   	 
*/
//Code
int orangesRotting(vector<vector<int>>& grid) 
{
        int count1=0;
        int count2=0;
        vector<int> dir={-1,0,1,0,-1}; 
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==1)
                    count1++;
                if(grid[i][j]==2)
                {    
                    count2++;
                    q.push({i,j});
                }
            }
        }
        int ans=-1;
        while(q.empty()==false)
        {
            int size=q.size();
            while(size--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x-1>=0 && grid[x-1][y]==1)
                {
                    grid[x-1][y]=2;
                    q.push({x-1,y});
                    count1--;
                }
                if(y-1>=0 && grid[x][y-1]==1)
                {
                    grid[x][y-1]=2;
                    q.push({x,y-1});
                    count1--;
                }
                 if(x+1<grid.size() && grid[x+1][y]==1)
                {
                    grid[x+1][y]=2;
                    q.push({x+1,y});
                     count1--;
                }
                if(y+1<grid[0].size() && grid[x][y+1]==1)
                {
                    grid[x][y+1]=2;
                    q.push({x,y+1});
                    count1--;
                }
                
            }
            ans++;
        }
        if(count1>0)
            return -1;
        if(ans==-1)
            return 0;
        
        return ans;
}
