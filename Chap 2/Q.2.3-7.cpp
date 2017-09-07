#include<bits/stdc++.h>
using namespace std;
bool binarySearch(int a[], int first, int last, int key)
{
    if(first>last)
        return false;
    int mid = (first+last)/2;
    if(a[mid]==key)
        return true;
    else if(a[mid] > key)
        return binarySearch(a,first,mid-1,key);
    else
        return binarySearch(a,mid+1,last,key);
}
void merge(int a[],int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1], R[n2];
    for (int i=0;i<n1;i++)
        L[i] = a[p+i];
    for(int i=0;i<n2;i++)
        R[i] = a[q+i+1];
    int i=0,j=0,k=p;
    while(i<n1 && j < n2)
    {
        if(L[i]>R[j])
            a[k++] = R[j++];
        else
            a[k++] = L[i++];
    }
    while(i<n1)
        a[k++] = L[i++];
    while(j<n2)
        a[k++] = R[j++];
}
void mergesort(int a[], int low, int high)
{
    int mid = (high + low)/2;
    if(low<high)
    {
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
}
int main()
{
  int a[] = {1,2,6,7,5};
  int sum = 3;
  mergesort(a,0,4);
    bool f = false;
  for(int i=0;i<4;i++)
  {
      if(binarySearch(a,0,4,sum-a[i]))
        {
        f = true;
            break;
        }

  }
  if(f)
    cout << "pair of numbers exist";
  else
    cout << "Doesnot exist";
}
