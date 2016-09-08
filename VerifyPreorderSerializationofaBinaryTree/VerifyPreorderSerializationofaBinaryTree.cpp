#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

vector<string> parse(string s){
	int left = 0;
	int len = s.length();
	vector<string> re;
	s = s + ',';

	for (int i=0;i<len+1;i++){
		if (s[i]==','){
			string tmp = s.substr(left,i-left);
			re.push_back(tmp);
			left = i + 1;
		}
	}

	return re;
}

bool isValidSerialization(string preorder) {
	vector<string> s = parse(preorder);
	stack<string> stk;
	int len = s.size();
	stk.push(s[0]);
	for (int i=1;i<len;i++){
		if (s[i] == "#"){
			while(stk.size()!=0 && stk.top() == "#"){
				stk.pop();
				if (stk.size()==0)
					return false;
				if (stk.top()=="#")
					return false;
				stk.pop();
			}
			stk.push("#");
		}
		else{
			stk.push(s[i]);
		}
	}

	if (stk.top() == "#" && stk.size() == 1){
		return true;
	}

	return false;   
}

int main(){
	string s = "#,8,8,3,#,#,0,4,4,#,#,#,#,#,3,7,8,#,7,#,#";
	//string s = "1,#,#,#,#";
	bool re = isValidSerialization(s);
	cout<<re;

	return 0;
}