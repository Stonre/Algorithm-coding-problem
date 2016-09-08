#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

void Union(int* comp,int n,int i,int j){
	int tm = comp[j];
    if (comp[i]!=comp[j]){
        for (int k=0;k<n;k++){
            if (comp[k]==tm){
                comp[k] = comp[i];
            }
        }
    }
}

int num_comp(int* comp,int n){
    map<int,int> m;
    for (int i=0;i<n;i++){
        if (m.count(comp[i])==0){
            m[comp[i]] = 1;
        }
    }
    return m.size();
}

int countComponents(int n, vector<pair<int, int> >& edges) {
    int cmp[n];
    for (int i=0;i<n;i++)
    	cmp[i] = i;
    for (int i=0;i<edges.size();i++){
        Union(cmp,n,edges[i].first,edges[i].second);
    }
    return num_comp(cmp,n);
}

int main(){
	vector<pair<int,int> > edges;
	edges.push_back(pair<int,int>(0,1));
	edges.push_back(pair<int,int>(2,3));
	edges.push_back(pair<int,int>(1,2));

	int num = countComponents(4,edges);
	cout<<num;
	return 0;
}