#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1=(C-A)*(D-B);
        int area2=(G-E)*(H-F);

        vector<int> t1;
        vector<int> t2;

        t1.push_back(A);
        t1.push_back(C);
        t1.push_back(E);
        t1.push_back(G);

        t2.push_back(B);
        t2.push_back(D);
        t2.push_back(F);
        t2.push_back(H);


        sort(t1.begin(),t1.end());
        sort(t2.begin(),t2.end());

        int area=(t1[2]-t1[1])*(t2[2]-t2[1]);
        return area1+area2-area;
    }
int main
{

}
