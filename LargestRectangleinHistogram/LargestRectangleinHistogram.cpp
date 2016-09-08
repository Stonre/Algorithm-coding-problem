#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int largestRectangleArea(vector<int>& heights) {
	int maxArea = 0;
	stack<int> stk;

	int len = heights.size();
	if (len == 0)
		return maxArea;
	heights.push_back(0);
	
	for (int i=0;i<len+1;i++){
		while (!stk.empty() && heights[stk.top()] > heights[i]){
			int tmp = stk.top();
			stk.pop();
			int lenright = i - tmp - 1;
			int lenleft = stk.empty()?(tmp + 1):(tmp - stk.top());
			int area = (lenright + lenleft) * heights[tmp];
			if (area > maxArea)
				maxArea = area;
		}
		stk.push(i);
	}

	return maxArea;
}

int main(){
	vector<int> heights;
	heights.push_back(0);
	heights.push_back(1);
	//heights.push_back(2);

	int re = largestRectangleArea(heights);
	cout<<re;
	return 0;
}