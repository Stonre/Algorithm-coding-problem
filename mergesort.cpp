#include<iostream>
using namespace std;

void merger(int a[],int low,int mid,int high)
{
    int tmp[high-low+1];
    int i=low, j=mid, k=0;

    while (i<mid && j<=high)
    {
        if (a[i]<a[j])
            tmp[k++]=a[i++];
        else
            tmp[k++]=a[j++];
    }
    while (i<mid)
        tmp[k++]=a[i++];
    while (j<=high)
        tmp[k++]=a[j++];
    for (i=0,k=low;k<=high;)
        a[k++]=tmp[i++];
    delete[] tmp;
}

void mergesort(int a[],int low,int high)
{
    if (high==low)
        return;
    int mid=(high+low)/2;
    mergesort(a,mid+1,high);
    mergesort(a,low,mid);
    merger(a,low,mid+1,high);
}

int main()
{
    int a[9]={2,1,4,3,7,5,8,6,9};
    mergesort(a,0,8);
    for (int i=0;i<9;i++)
        cout<<a[i]<<endl;
    return 0;
}
