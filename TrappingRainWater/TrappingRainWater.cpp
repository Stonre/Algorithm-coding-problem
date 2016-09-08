#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
	stack<pair<int,int> > stk;
	int len = height.size();
	int vol = 0;

	if (len<3)
		return 0;
	stk.push(pair<int,int>(0,height[0]));
	for (int i=1;i<len;i++){
		pair<int,int> tmp = stk.top();
		int base = tmp.second;
		if (tmp.second >= height[i]){
			
			stk.push(pair<int,int>(i,height[i]));
		}
		else{
			
			stk.pop();

			if (stk.size()!=0){

				while (stk.top().second < height[i]){

					pair<int,int> tmp_2 = stk.top();

					vol += (i - tmp_2.first - 1) * (tmp_2.second - base);
					base = tmp_2.second;
					stk.pop();
					
				}
				

				if (stk.size()!=0){
					pair<int,int> tmp_2 = stk.top();
					vol += (i - tmp_2.first -1) * (height[i] - base);
				}
			}

			stk.push(pair<int,int>(i,height[i]));
		}
	}
	return vol;
}

int main(){
	vector<int> h;
	h.push_back(0);
	h.push_back(1);
	h.push_back(0);
	h.push_back(2);
	h.push_back(1);
	h.push_back(0);
	h.push_back(1);
	h.push_back(3);
	h.push_back(2);
	h.push_back(1);
	h.push_back(2);
	h.push_back(1);

	int re = trap(h);
	cout<<re;
	return 0;
}