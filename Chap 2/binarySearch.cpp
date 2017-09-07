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
void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
}
int main()
{
  int a[] = {1,2,3,4,5};
  int key = 4;
  if(binarySearch(a,0,4,key))
    cout << "found " << key;
  else
    cout << "Not found";
}
