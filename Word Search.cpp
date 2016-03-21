#include "pack.h"

bool exist(vector<vector<char> >& board,string word)
{
    bool re = false;
    for (int i = 0;i<board.size();i++)
    {
        for (int j=0;j<board[0].size();j++)
        {
            int k = 0;
            searchword(board,word,k,i,j,re);
        }
    }
    return re;
}

void searchword(vector<vector<char> >& board,string& word,int k,int i,int j,bool& re)
{
    int h = board.size();
    int w = board[0].size();
    if (k==word.size())
    {
        re = true;
        return;
    }
    if (board[i][j]==word[k])
    {
        if (i+1<h)
            searchword(board,word,k+1,i+1,j,re);
        if (j+1<h)
            searchword(board,word,k+1,i,j+1,re);
        if (i-1>=0)
            searchword(board,word,k+1,i-1,j,re);
        if (j-1>=0)
            searchword(board,word,k+1,i,j-1,re);
    }
}
