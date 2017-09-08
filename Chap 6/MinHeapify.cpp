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

void min_heapify(int a[], int i,int n)
{
    int l = left(i);
 
    int r = right(i);
 
    int smallest;
    if(l < n && a[l]<a[i])
        smallest = l;
    else
        smallest = i;
    if(r<n && a[r] < a[smallest])
        smallest = r;
   
    if(smallest!=i)
    {swap(&a[smallest], &a[i]);
     max_heapify(a,smallest,n);}
}
void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
}
int main()
{
    int a[] = {16,4,10,14,7,9,3,2,8,1};

    min_heapify(a,1,10);
    printArray(a,10);

}
