//Number of Islands (leetcode 200)

/* We can use DFS to solve this problem.
Algorithm: 
	1.Search for the '1' in grid if found start DFS from that position
	2.search in all 4 direction and mark all ones by any character except '0' and '1'.
	3.keep track of index out of bound.
	4.Increase the count after calling the DFS.
	5.return count.
*/
	
//Code:	
void dfs(vector<vector<char>>&grid,int i,int j)
    {
    	//checking index out of bound and element is '1' or not
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!='1')
            return;
        //marking the current '1' as '2' for nto traversing again    
        grid[i][j]='2';
        //calling dfs in all four directions
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }	

