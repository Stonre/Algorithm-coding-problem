#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

void solve(vector<vector<char> >& board){

	int len_row = board.size();
	if (len_row==0)
		return;
	int len_col = board[0].size();
	if (len_row<=2 || len_col<=2)
		return;

	queue<pair<int,int> > q;

	int len = len_row>len_col?len_row:len_col;

	for (int i=0;i<len;i++){
		if (i<len_row && board[i][0]=='O')
			q.push(pair<int,int>(i,0));
		if (i<len_row && board[i][len_col-1]=='O')
			q.push(pair<int,int>(i,len_col-1));
		if (i<len_col && board[0][i]=='O')
			q.push(pair<int,int>(0,i));
		if (i<len_col && board[len_row-1][i]=='O')
			q.push(pair<int,int>(len_row-1,i));
	}

	while (!q.empty()){
		pair<int,int> tm = q.front();
		board[tm.first][tm.second] = '*';
		if (tm.first+1<len_row && board[tm.first+1][tm.second]=='O')
			q.push(pair<int,int>(tm.first+1,tm.second));
		if (tm.first-1>=0 && board[tm.first-1][tm.second]=='O')
			q.push(pair<int,int>(tm.first-1,tm.second));
		if (tm.second+1<len_col && board[tm.first][tm.second+1]=='O')
			q.push(pair<int,int>(tm.first,tm.second+1));
		if (tm.second-1>=0 && board[tm.first][tm.second-1]=='O')
			q.push(pair<int,int>(tm.first,tm.second-1));
		q.pop();
	}

	for (int i=0;i<len_row;i++)
	{
		for (int j=0;j<len_col;j++)
		{
			if (board[i][j]=='O')
				board[i][j] = 'X';
			if (board[i][j]=='*')
				board[i][j] = 'O';
		}
	}
}

int main(){
	vector<vector<char> > board;
	fstream in("in.txt");
	vector<char> line;
	char c;

	while(in.get(c)){
		cout<<c;
		if (c=='\n'){
			board.push_back(line);
			line.clear();
			continue;
		}
		if (c==' ')
			continue;
		line.push_back(c);
	}
	board.push_back(line);

	cout<<endl<<endl;

	for (int i=0;i<board.size();i++){
		for (int j=0;j<board[0].size();j++){
			cout<<board[i][j];
		}
		cout<<endl;
	}

	solve(board);

	cout<<endl<<endl;

	for (int i=0;i<board.size();i++){
		for (int j=0;j<board[0].size();j++){
			cout<<board[i][j];
		}
		cout<<endl;
	}

	return 0;
}