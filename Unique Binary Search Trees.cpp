#include<iostream>
using namespace std;

    int cur(int sleft,int eleft,int sright,int eright)
    {
        int contl,contr;
        if (sleft>eleft&&sright>eright)
            return 1;
        if (sleft<=eleft)
        {
            contl=0;
            for (int i=sleft;i<=eleft;i++)
            {
                contl+=cur(sleft,i-1,i+1,eleft);
            }
        }
        else
            contl=1;
        if (sright<=eright)
        {
            contr=0;
            for (int i=sright;i<=eright;i++)
            {
                contr+=cur(sright,i-1,i+1,eright);

            }
        }
        else
            contr=1;
        return contr*contl;
    }
    int numTrees(int n) {
        int cont=0;
        for (int i=1;i<=n;i++)
        {
            cont+=cur(1,i-1,i+1,n);
        }
        return cont;
    }

int main()
{
    int num;
    num=numTrees(3);
    cout<<num;
    return 0;
}
