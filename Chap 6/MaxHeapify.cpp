#include<bits/stdc++.h>
#include<tuple>
using namespace std;
int left(int i)
{
    return (2*i + 1);
}
int right(int i)
{
    return (2*i+2);
}
int parent(int i)
{
    return (i-1)/2;
}

void swap(int *a, int*b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void max_heapify(int a[], int i,int n)
{
    int l = left(i);
   
    int r = right(i);
   
    int largest;
    if(l < n && a[l]>a[i])
        largest = l;
    else
        largest = i;
    if(r<n && a[r] > a[largest])
        largest = r;
   
    if(largest!=i)
    {swap(&a[largest], &a[i]);
     max_heapify(a,largest,n);}
}
void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
}
int main()
{
    int a[] = {16,4,10,14,7,9,3,2,8,1};

    max_heapify(a,1,10);
    printArray(a,10);

}
