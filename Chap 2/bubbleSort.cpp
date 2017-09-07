#include<bits/stdc++.h>
using namespace std;
void swap(int *p, int*q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void bubbleSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
        for(int j = n-1;j>=i+1;j--)
    {
        if(a[j]<a[j-1])
            swap(&a[j],&a[j-1]);
    }
}
void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
}
int main()
{
  int a[] = {10,2,6,7,5};
 bubbleSort(a,5);
 printArray(a,5);
}
