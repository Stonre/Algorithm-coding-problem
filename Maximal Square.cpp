#include "pack.h"

int maximalSquare(vector<vector<char> >& matrix)
{
    int len = matrix.size();
    if (len == 0)
        return 0;
    int dp[matrix.size()][matrix[0].size()];
    for (int i=0;i<matrix.size();i++)
        for (int j=0;j<matrix[0].size();j++)
            dp[i][j]=0;
    int maxarea = 0;
    for (int i=0;i<len;i++)
    {
        for (int j=0;j<matrix[0].size();j++)
        {
            if (i > 0 && j > 0)
                if (matrix[i][j] =='1')
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
            else if (matrix[i][j] == '1')
                    dp[i][j] = 1;
            if (dp[i][j] > maxarea)
                maxarea = dp[i][j];
        }
    }
    return maxarea * maxarea;
}

int main()
{
    ifstream in("in.txt");
    vector<vector<char> > sss;
    vector<char> t;
    int k=0;
    while (!in.eof())
    {
        char tmp;
        in>>tmp;
        t.push_back(tmp);
        k++;
        if (k%5==0)
        {
            sss.push_back(t);
            t.clear();
        }
    }
    for (int i=0;i<sss.size();i++)
    {
        for (int j=0;j<sss[i].size();j++)
            cout<<sss[i][j]<<" ";
        cout<<endl;
    }
    int re = maximalSquare(sss);
    cout<<re;

    return 0;
}
