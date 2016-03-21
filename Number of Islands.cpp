#include "pack.h"

int numIslands(vector<vector<char> >& grid)
{
    int lenr = grid.size();
    if (lenr == 0)
        return 0;
    int lenc = grid[0].size();

    int ans=0;
    for (int i=0;i<lenr;i++)
        for (int j=0;j<lenc;j++)
    {
        if (grid[i][j]=='0')
            continue;
        ams++;
    }
    return ans;
}

void dfs(vector<vector<char> >& grid,int i,int j)
{
    int lenr = grid.size();
    int lenc = grid[0].size();

    if (i+1==lenr&&j+1==lenc)
        return;
    else if (i+1==lenr)
    {
        if (grid[i][j+1]=='0')
            return;
    }
    else if (j+1==lenc)
    {
        if (grid[i+1][j]=='0')
            return;
    }
    else
    {
        if (grid[i+1][j]=='0'&&grid[i][j+1]=='0')
            return;
    }
    if (grid[i][j]=='1')
        grid[i][j]=0;
    if (i+1<lenr)
        dfs(grid,i+1,j);
    if (j+1<lenc)
        dfs(grid,i,j+1);
}
