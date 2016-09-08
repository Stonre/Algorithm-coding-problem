#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool verifyPreorder(vector<int>& preorder) {
	int len = preorder.size();

	if (len <= 1)
		return true;   
	int maxvalue = INT_MAX, minvalue = INT_MIN;

	stack<int> stk;
	stk.push(preorder[0]);

	for (int i=1;i<len;i++){
		if (preorder[i] < preorder[i-1]){
			if (preorder[i] < minvalue || preorder[i] > maxvalue)
				return false;
		}
		else{
			while (!stk.empty()){
				if (preorder[i] > stk.top()){
					minvalue = stk.top();
					maxvalue = INT_MAX;
					stk.pop();
				}
				else{
					maxvalue = stk.top();
					break;
				}
			}
		}
		stk.push(preorder[i]);
	}

	return true;
}

int main(){
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);

	bool re = verifyPreorder(v);

	cout<<re;
	return 0;
}



