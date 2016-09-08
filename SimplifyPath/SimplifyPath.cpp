#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

string simplifyPath(string path){
    vector<string> dir;
    string name = "";
    for (int i=0;i<path.length();i++){
    	if (path[i] == '/'){
    		if (name!=""&&name!=".."&&name!="."){
    			dir.push_back(name);
    			name = "";
    		}
    		else if (name==".."){
    			if (dir.size()!=0)
    				dir.pop_back();
    			name = "";
    		}
    		else if (name=="."){
    			name = "";
    		}
    	}
    	else{
    		name = name + path[i];
    	}
    }

    if (name != "" && name != "." && name != "..")
    	dir.push_back(name);
    else if (name == ".." && dir.size()>0)
    	dir.pop_back();

    if (dir.size()==0){
    	return "/";
    }

    string re = "";
    for (int i=0;i<dir.size();i++){
    	re = re + '/' + dir[i];
    }

    return re;
}

int main(){
	string path = "/.";
	string pathnew = simplifyPath(path);
	cout<<pathnew;

	return 0;
}