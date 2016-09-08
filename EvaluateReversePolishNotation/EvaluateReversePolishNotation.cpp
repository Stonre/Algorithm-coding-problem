#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

int evalRPN(vector<string>& tokens) {
	int len = tokens.size();

	stack<int> stk;

	for (int i=0;i<len;i++){
		if (tokens[i] == "+"){
			int first = stk.top();
			stk.pop();
			int second = stk.top();
			stk.pop();
			int re = second + first;
			stk.push(re);
		}
		else if (tokens[i] == "-"){
			int first = stk.top();
			stk.pop();
			int second = stk.top();
			stk.pop();
			int re = second - first;
			stk.push(re);
		}
		else if (tokens[i] == "*"){
			int first = stk.top();
			stk.pop();
			int second = stk.top();
			stk.pop();
			int re = second * first;
			stk.push(re);
		}
		else if (tokens[i] == "/"){
			int first = stk.top();
			stk.pop();
			int second = stk.top();
			stk.pop();
			int re = second / first;
			stk.push(re);
		}
		else{
			int elem = stoi(tokens[i]);
			stk.push(elem);
		}
	}

	int re = stk.top();
	stk.pop();

	return re;
}
 
int main(){
	vector<string> tokens;
	tokens.push_back("2");
	tokens.push_back("1");
	tokens.push_back("+");
	tokens.push_back("3");
	tokens.push_back("*");
	int re = evalRPN(tokens);
	cout<<re;
	return 0;
}