#include<bits/stdc++.h>
using namespace std;
int merge(int a[],int p,int q, int r)
{
    int cnt=0;
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++)
        L[i]=a[i+p];
    for(int i=0;i<n2;i++)
        R[i] = a[q+i+1];
    int i=0,j=0,k=p;
    while(i<n1 && j<n2)
    {
        if(L[i]>R[j])
        {
            a[k++] = R[j++];
            cnt = cnt+n1-i;

        }
        else
            a[k++] = L[i++];
    }
    while(i<n1)
        a[k++] = L[i++];
    while(j<n2)
        a[k++] = R[j++];

    return cnt;
}
int mergesort(int a[], int p, int q) //to start call mergesort(a,0,array_size-1)
{
    int cnt=0;
    int mid = (p+q)/2;
    if(p<q)
    {
        cnt+= mergesort(a,p,mid);
        cnt+=mergesort(a,mid+1,q);
        cnt+=merge(a,p,mid,q);
    }
    return cnt;
}
void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
}
int main()
{
  int a[] = {1, 20, 6, 4, 5};
 int inve = mergesort(a,0,4);
 cout << inve;
}
