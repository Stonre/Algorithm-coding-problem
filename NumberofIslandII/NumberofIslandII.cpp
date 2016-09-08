#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class UnionFind{
	private:
		int count;
		int* id;
		int* sizes;

	public:
		UnionFind(int n){
			id = new int[n];
			sizes = new int[n];

			for (int i=0;i<n;i++){
				id[i] = i;
				sizes[i] = 1;
			}

			count = 0;
		}

		void Union(int i,int j){
			int r_1 = findroot(i);
			int r_2 = findroot(j);
			if (r_1 == r_2)
				return;

			if (sizes[r_1] > sizes[r_2]){
				id[r_2] = id[r_1];
				sizes[r_1] = sizes[r_1] + sizes[r_2];
			}
			else{
				id[r_1] = id[r_2];
				sizes[r_2] = sizes[r_1] + sizes[r_2];
			}
			count--;
		}

		int findroot(int i){
			while (id[i]!=i){
				i = id[i];
			}
			return i;
		}

		bool isConnected(int i,int j){
			return findroot(i) == findroot(j);
		}

		int Count(){
			return count;
		}
};

vector<int> numIslands2(int m, int n, vector<pair<int, int> >& positions) {
	vector<int> re;
	if (m<=0 || n<=0){
		return re;
	}

	UnionFind* uf = new UnionFind(m*n);
	int len = positions.size();
	int board[m][n];
	memset(board,0,sizeof(board));
	for (int i=0;i<len;i++){
		pair<int,int> loca = positions[i];
		int x = loca.first;
		int y = loca.second;

		board[x][y] = 1;
		int index = x * n + y;
		if (x>0 && board[x-1][y] == 1){
			uf->Union(index,index-n);
		}
		if (x<m-1 && board[x+1][y] == 1){
			uf->Union(index,index+n);
		}
		if (y>0 && board[x][y-1] == 1){
			uf->Union(index,index-1);
		}
		if (y<n-1 && board[x][y+1] == 1){
			uf->Union(index,index+1);
		}
		re.push_back(i+1+uf->Count());
	}

	return re;
}



int main(){
	return 0;
}