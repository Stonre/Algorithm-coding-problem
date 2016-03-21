#include<vector>
#include<iostream>
using namespace std;

int minPathSum(vector<vector<int> >& grid) {
        if (grid.size()==0)
            return 0;
        int sp[grid.size()][grid[0].size()];
        sp[0][0]=grid[0][0];
        for (int i=1;i<grid.size();i++)
            sp[i][0]=sp[i-1][0]+grid[i][0];
        for (int i=1;i<grid[0].size();i++)
            sp[0][i]=sp[0][i-1]+grid[0][i];
        for (int i=1;i<grid.size();i++)
            for (int j=1;j<grid[0].size();j++)
            {
                if (sp[i-1][j]>sp[i][j-1])
                    sp[i][j]=sp[i-1][j]+grid[i][j];
                else
                    sp[i][j]=sp[i][j-1]+grid[i][j];
            }
        return sp[grid.size()-1][grid[0].size()-1];
    }

int main()
{
    vector<int> c({1,2});
    vector<int> b({1,1});
    vector<vector<int> > re;
    re.push_back(c);
    re.push_back(b);
    int r=minPathSum(re);
    cout<<r;
    return 0;
}
