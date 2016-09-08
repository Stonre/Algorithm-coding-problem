#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights){
	int len = heights.size();
	if (len <= 1)
	    return heights[0];
	stack<int> stk;
	int maxArea = 0;
	heights.push_back(0);

	for (int i=0;i<len+1;i++){
		while (!stk.empty() && heights[stk.top()] > heights[i]){
			int tmp = stk.top();
			stk.pop();
			int lenleft = stk.empty()?tmp+1:tmp-stk.top();
			int lenright = i - tmp - 1;
			int area = (lenleft + lenright) * heights[tmp];
			if (area > maxArea)
				maxArea = area;
		}
		stk.push(i);
	}
	return maxArea;
}
 
int maximalRectangle(vector<vector<char> >& matrix) {
	int lenr = matrix.size();
	if (lenr == 0)
		return 0;
	int lenc = matrix[0].size();

	int maxRec = 0;
	vector<int> dpr(lenc,0);
	vector<vector<int> > dp(lenr,dpr);

	for (int i=0;i<lenc;i++){
		if (matrix[0][i] == '0')
			dp[0][i] = 0;
		else
			dp[0][i] = 1;
	}

	for (int i=1;i<lenr;i++){
		for (int j=0;j<lenc;j++){
			if (matrix[i][j] == '1')
				dp[i][j] = dp[i-1][j] + 1;
		}
	}

	for (int i=0;i<lenr;i++){
		int tmpArea = largestRectangleArea(dp[i]);
		if (tmpArea>maxRec)
			maxRec = tmpArea;
	}

	return maxRec;
}

int main(){
	
}