class Solution {
public:
    void numislands(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j,int r,int c)
    {
        if(i<0 || i>=r || j<0 || j>=c)
            return;
        if(grid[i][j]=='0')
            return;
        if(visited[i][j]==true)
            return;
        visited[i][j] = true;
        numislands(grid,visited,i-1,j,r,c);
        numislands(grid,visited,i,j+1,r,c);
        numislands(grid,visited,i+1,j,r,c);
        numislands(grid,visited,i,j-1,r,c);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
       
        int r,c;
        r = grid.size();
        vector<vector<bool> > visited;
        for(int i=0;i<grid.size();i++)
        {
            vector<bool> temp;
            c = grid[i].size();
            for(int j=0;j<grid[i].size();j++)
            {
                temp.push_back(false);
            }
            visited.push_back(temp);
            temp.clear();
        }
        
        int res=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==false)
                {
                    numislands(grid,visited,i,j,r,c);
                    res++;
                }
            }
        }
        return res;
        
    }
};