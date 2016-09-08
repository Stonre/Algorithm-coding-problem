#include <iostream>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

bool Union(int i, int j, int* id,int len){
	if (id[i]==id[j])
		return false;

	int id1 = id[i];
	int id2 = id[j];

	for (int p=0;p<len;p++){
		if (id[p]==id2)
			id[p] = id1;
	}

	return true;
}

int num_component(int* id,int len){
	int count = 0;
	map<int,int> m;
	for (int i=0;i<len;i++){
		if (m.count(id[i])==0)
			m[id[i]] = 1;
	}
	return m.size();
}

bool validTree(int n, vector<pair<int, int> >& edges){
	int id[n];
	int len = edges.size();

	for (int i=0;i<n;i++)
		id[i] = i;

	for (int i=0;i<len;i++){
		pair<int,int> tmp = edges[i];
		int id1 = tmp.first;
		int id2 = tmp.second;
		if (id[id1]==id[id2])
			return false;
		for (int p=0;p<n;p++){
			if (id[p]==id2)
				id[p] = id1;
		}
	}

	int num_com = num_component(id,n);

	return num_com==1?true:false;
}

int main(){
	return 0;
}